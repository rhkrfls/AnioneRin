#include "stdafx.h"
#include "MainScene.h"


void MainScene::Init()
{
	selectUI = new GameObject(L"Select.png");

	mainUI[0] = new GameObject(L"start.png");
	mainUI[1] = new GameObject(L"option.png");
	mainUI[2] = new GameObject(L"exit.png");

	selectUI->position = { 500,700 };
	selectUI->scale = { 1,1 };

	for (int i = 0; i < 3; i++)
	{
		mainUI[i]->position = { 700,700 + (float)100 * i };
		mainUI[i]->scale = { 1,1 };
	}

	mciSendString(L"Play moon.mp3 repeat", 0, 0, 0);
}

void MainScene::Update()
{
	PlayUI();
}

void MainScene::Render()
{
	Graphic::Render(selectUI);
	for (int i = 0; i < 3; i++)
		Graphic::Render(mainUI[i]);
}

void MainScene::Release()
{
}

void MainScene::PlayUI()
{
	if (GetAsyncKeyState(VK_DOWN) & 0x0001 && cnt < 2)
		cnt++;

	if (GetAsyncKeyState(VK_UP) & 0x0001 && cnt > 0)
		cnt--;

	if (GetAsyncKeyState(VK_RETURN) & 0x0001)
	{
		switch (cnt)
		{
		case 0:
			GameSystem::CH_s_number = GAME;
			break;

		case 1:
			break;

		case 2:
			GameSystem::CH_s_number = EXIT;
			break;
		}
	}

	selectUI->position = { 500,700 + (float)100 * cnt };
}
