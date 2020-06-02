#include "stdafx.h"
#include "GameScene.h"

void GameScene::Init()
{
	player = new Player(L"Player.png");
	
	enemy = new GameObject(L"enemy.png");
	BG = new GameObject(L"background.png");
	enemy->position = { 1000,300 };
	BG->position = { GetSystemMetrics(SM_CXSCREEN) / 2.0f,GetSystemMetrics(SM_CYSCREEN) / 2.0f };
	BG->scale = { 2,2 };
}

void GameScene::Update()
{
	player->Move();
	player->Shot();
	player->Animation();
	player->BulletAttackCheck(enemy);
}

void GameScene::Render()
{
	Graphic::Render(BG);
	Graphic::Render(enemy);
	player->Render();
}

void GameScene::Release()
{
	delete player;
}
