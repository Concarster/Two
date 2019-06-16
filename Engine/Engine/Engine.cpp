#include "PCH.h"
#include "Engine.h"
#include "Api/Initialize.h"

#include <glad/glad.h>

namespace one
{
	Engine::Engine()
	{
		m_DisplayMgr = std::make_unique<DisplayMgr>(this);
	}

	Engine::~Engine()
	{
	}

	void Engine::Run()
	{
		if (!Init())
			return;

		m_Running = true;

		///Game Loop
		while (m_Running)
		{

			Update();
			Draw();

		}
	}

	void Engine::ExitGame()
	{
		m_CurrentDisplay->OnExit();

		if (m_DisplayMgr)
		{
			m_DisplayMgr->Destroy();
			m_DisplayMgr.reset(); //Free memory
		}

		m_Running = false;
	}

	void Engine::OnEvent(Event& event)
	{
		switch (event.GetEventType()) 
		{
		case EventType::WindowClose:
			m_Running = false;
			break;
		}
	}

	bool Engine::Init()
	{
		one::Init();

		OnInit();

		AddDisplays();
		m_CurrentDisplay = m_DisplayMgr->GetCurrentDisplay();
		m_CurrentDisplay->OnEntry();
		m_CurrentDisplay->Run();


		return true;
	}

	void Engine::Update()
	{
		if (m_CurrentDisplay)
		{
			switch (m_CurrentDisplay->GetDisplayState())
			{
			case DisplayState::RUNNING:
				m_CurrentDisplay->Update();
				break;
			case DisplayState::CHANGE_NEXT:
				m_CurrentDisplay->OnExit();
				m_CurrentDisplay = m_DisplayMgr->MoveToNextDisplay();

				if (m_CurrentDisplay)
				{
					m_CurrentDisplay->Run();
					m_CurrentDisplay->OnEntry();
				}
				break;
			case DisplayState::CHANGE_PREVIOUS:
				m_CurrentDisplay->OnExit();
				m_CurrentDisplay = m_DisplayMgr->MoveToPreviousDisplay();

				if (m_CurrentDisplay)
				{
					m_CurrentDisplay->Run();
					m_CurrentDisplay->OnEntry();
				}
				break;
			case DisplayState::EXIT_GAME:
				ExitGame();
				break;
			default:
				break;
			}
		}
		else
		{
			//we have no screen so exit
			ExitGame();
		}
	}

	void Engine::Draw()
	{
		//For safety
		//glViewport(0, 0, m_Window.GetScreenWidth(), m_Window.GetScreenHeight());

		//Check if we have a screen and that the screen is running
		if (m_CurrentDisplay && m_CurrentDisplay->GetDisplayState() == DisplayState::RUNNING)
		{
			m_CurrentDisplay->Draw();
		}
	}
}
