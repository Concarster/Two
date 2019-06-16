#pragma once
#include <Engine/Main.h>
#include <Engine/Engine.h>
#include "GameMgr.h"

class Game : public one::Engine
{
public:
	Game();
	~Game();

	virtual void OnInit() override;
	virtual void OnExit() override;
	virtual void AddDisplays() override;

private:
	std::unique_ptr<GameMgr> m_GameMgr = nullptr;
};

