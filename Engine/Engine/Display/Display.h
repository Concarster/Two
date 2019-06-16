#pragma once

namespace one
{
	class Engine;

	enum class DisplayState
	{
		NONE,
		RUNNING,
		EXIT_GAME,
		CHANGE_NEXT,
		CHANGE_PREVIOUS
	};

	class Display
	{
	protected:
		DisplayState m_CurrentState = DisplayState::NONE;
		Engine* m_Game = nullptr;
		size_t m_DisplayID = -1;

	public:
		friend class DisplayMgr;

		Display()
		{

		};

		virtual ~Display()
		{

		};

		//Called on beginning and end of app
		virtual void Build() = 0; //pure virtual (makes it a must to inherit)
		virtual void Destroy() = 0;

		virtual void OnEntry() = 0;
		virtual void OnExit() = 0;

		virtual void Update() = 0;
		virtual void Draw() = 0;

		void Run()
		{
			m_CurrentState = DisplayState::RUNNING;
		}

		///Return the current screen index
		size_t GetDisplayID() const
		{
			return m_DisplayID;
		}

		void SetRunning() 
		{
			m_CurrentState = DisplayState::RUNNING;
		}

		DisplayState GetDisplayState() const
		{
			return m_CurrentState;
		}

		virtual int GetNextDisplayID() const = 0;
		virtual int GetPreviousDisplayID() const = 0;

		void SetParentGame(Engine* game)
		{
			m_Game = game;
		}

	};
}
