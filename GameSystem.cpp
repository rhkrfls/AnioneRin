#include "stdafx.h"
#include "GameSystem.h"

bool GameSystem::GameExit = false;
int GameSystem::CH_s_number = SCENETYPE::INTRO;

void GameSystem::Init()
{
	SetScene(SCENETYPE::INTRO);
}

void GameSystem::Update()
{
	scene->Update();
}

void GameSystem::Render()
{
	scene->Render();
}

void GameSystem::Release()
{
	scene->Release();
	delete scene;
}

void GameSystem::SetScene(int scenenumber)
{
	current_s_number = scenenumber;
	CH_s_number = scenenumber;

	if (scene != nullptr)
	{
		scene->Release();
		delete scene;
	}

	switch (scenenumber)
	{
	case SCENETYPE::INTRO:
		scene = new MainScene();
		break;
	case SCENETYPE::GAME:
		scene = new GameScene();
		break;
	case SCENETYPE::EXIT:
		GameExit = true;
		break;
	}

	if (scene != nullptr)
		scene->Init();
}

void GameSystem::SceneChangeCheck()
{
	if (current_s_number != CH_s_number)
		SetScene(CH_s_number);
}
