#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(LPCWSTR filename)
{
	position = { 500,500 };
	scale = { 2,2 };
	angle = 0;

	Graphic::Load_Bitmap(this, filename);
}

GameObject::~GameObject()
{
}
