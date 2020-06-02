#pragma once
#include <d2d1.h>
#include "Graphic.h"

class GameObject
{
public:
	GameObject(LPCWSTR filename);
	~GameObject();

public:
	bool exist = true;
	ID2D1Bitmap* pBitmap;
	D2D_VECTOR_2F position;
	D2D_VECTOR_2F scale;
	float angle;
};

