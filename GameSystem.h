#pragma once
#include "GameObject.h"
#include "Graphic.h"
#include "Scene.h"
#include "GameScene.h"
#include "MainScene.h"

enum SCENETYPE
{
	INTRO, MAIN, GAME, EXIT
};

class GameSystem
{
private:
	Scene * scene = nullptr;
	int current_s_number;

public:
	static bool GameExit;
	static int CH_s_number;

public:
	void Init();
	void Update();
	void Render();
	void Release();
	void SetScene(int scenenumber);
	void SceneChangeCheck();
};

