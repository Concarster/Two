#pragma once

#include <vector>

namespace one
{
	class Engine;
	class Display;

	class DisplayMgr
	{
	protected:
		Engine* m_Game = nullptr;
		std::vector<Display*> m_Displays;
		int m_CurrentDisplayID = -1;

	public:
		DisplayMgr(Engine* game);
		~DisplayMgr();

		Display* MoveToNextDisplay();

		Display* MoveToPreviousDisplay();

		Display* GetCurrentDisplay();

		void SetCurrentDisplay(int nextDisplay);

		void AddDisplay(Display* newDisplay);

		void Destroy();
	};
}

