#include "GameMgr.h"
#include <iostream>
#include <glad/glad.h>
#include <Engine/Engine.h>
#include <Engine/Util/Log.h>


GameMgr::GameMgr()
{
}


GameMgr::~GameMgr()
{
}

void GameMgr::Build()
{
}

void GameMgr::Destroy()
{
}

void GameMgr::OnEntry()
{
	ENGINE_INFO("OnEntry");

	/*Logger System*/
	ENGINE_INFO("Welcome To One Engine!");
	ENGINE_WARN("Initializing Engine Logger!");
	ENGINE_TRACE("Engine Logger Initialized!");
	CLIENT_WARN("Initializing Client Logger!");
	CLIENT_TRACE("Client Logger Initialized!");
}

void GameMgr::OnExit()
{
}

void GameMgr::Update()
{
	ENGINE_INFO("Update");
	CheckInput();
}

void GameMgr::Draw()
{
	ENGINE_INFO("Draw");
	/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);*/
}

int GameMgr::GetNextDisplayID() const
{
	return DISPLAY_ID_NO_DISPLAY;
}

int GameMgr::GetPreviousDisplayID() const
{
	return DISPLAY_ID_NO_DISPLAY;
}

void GameMgr::CheckInput()
{
	
}
