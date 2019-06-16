#include "PCH.h"
#include "DisplayMgr.h"
#include "Display.h"

namespace one
{
	DisplayMgr::DisplayMgr(Engine* game)
		:m_Game(game)
	{
	}

	DisplayMgr::~DisplayMgr()
	{
		Destroy();
	}

	Display* DisplayMgr::MoveToNextDisplay()
	{
		Display* currentDisplay = GetCurrentDisplay();

		if (currentDisplay->GetNextDisplayID() != DISPLAY_ID_NO_DISPLAY)
		{
			m_CurrentDisplayID = currentDisplay->GetNextDisplayID();
		}

		return GetCurrentDisplay();
	}

	Display* DisplayMgr::MoveToPreviousDisplay()
	{
		Display* currentDisplay = GetCurrentDisplay();

		if (currentDisplay->GetPreviousDisplayID() != DISPLAY_ID_NO_DISPLAY)
		{
			m_CurrentDisplayID = currentDisplay->GetPreviousDisplayID();
		}

		return GetCurrentDisplay();
	}

	Display* DisplayMgr::GetCurrentDisplay()
	{
		if (m_CurrentDisplayID == DISPLAY_ID_NO_DISPLAY)
		{
			//Error
			return nullptr;
		}
		return m_Displays[m_CurrentDisplayID];
	}

	void DisplayMgr::SetCurrentDisplay(int nextDisplay)
	{
		m_CurrentDisplayID = nextDisplay;
	}

	void DisplayMgr::AddDisplay(Display* newDisplay)
	{
		newDisplay->m_DisplayID = m_Displays.size(); //set index correctly
		m_Displays.push_back(newDisplay);
		newDisplay->Build();
		newDisplay->SetParentGame(m_Game);
	}

	void DisplayMgr::Destroy()
	{
		for (size_t i = 0; i < m_Displays.size(); i++)
		{
			m_Displays[i]->Destroy();
		}
		m_Displays.resize(0);
		m_CurrentDisplayID = DISPLAY_ID_NO_DISPLAY;
	}

}
