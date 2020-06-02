#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "Player.h"
#include "Graphic.h"
#include "Background.h"

class GameScene : public Scene
{
private:
	Player* player;
	GameObject* enemy;
	GameObject * BG;

public:
	void Init();
	void Update();
	void Render();
	void Release();
};

