#pragma once
#include <mciapi.h>
#include "Scene.h"
#include "Graphic.h"
#include "GameObject.h"
#include "GameSystem.h"

class MainScene : public Scene
{
private:
	GameObject* selectUI;
	GameObject* mainUI[3];
	int cnt = 0;

public:
	void  Init();
	void Update();
	void Render();
	void Release();

	void PlayUI();
};

