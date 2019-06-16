#pragma once
#include <memory>
#include "Display/Display.h"
#include "Display/DisplayMgr.h"

#include "Window.h"
#include "InputMgr.h"
#include "Events/Event.h"

namespace one
{
	class Engine
	{
	protected:
		std::unique_ptr<DisplayMgr> m_DisplayMgr = nullptr;
		Display* m_CurrentDisplay = nullptr;
		Window m_Window;
		InputMgr m_InputMgr;
		bool m_Running = false;
		float m_FPS = 0.0f;

	public:
		Engine();
		virtual ~Engine();

		void Run();
		void ExitGame();

		virtual void OnInit() = 0;
		virtual void OnExit() = 0;

		virtual void AddDisplays() = 0;

		void OnEvent(Event& event);

		const float GetFPS() const { return m_FPS; }

	protected:
		bool Init();

		virtual void Update();
		virtual void Draw();
	};

	/*For Clients */
	Engine* Generate();
}
