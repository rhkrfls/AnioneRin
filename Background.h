#pragma once
#include "GameObject.h"
#include "Graphic.h"

class Background : public GameObject
{
public:
	Background(LPCWSTR filename);
	void Render();

};

