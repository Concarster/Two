#include "Game.h"
#include <Engine/Display/DisplayMgr.h>

Game::Game()
{
}


Game::~Game()
{
}

void Game::OnInit()
{
}

void Game::OnExit()
{
}

void Game::AddDisplays()
{
	m_GameMgr = std::make_unique<GameMgr>();
    m_DisplayMgr->AddDisplay(m_GameMgr.get()); //get underlining pointer
	m_DisplayMgr->SetCurrentDisplay((int)m_GameMgr->GetDisplayID());
}

one::Engine* one::Generate()
{
	return new Game();
}