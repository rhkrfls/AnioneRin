#include "stdafx.h"
#include "Background.h"

Background::Background(LPCWSTR filename) : GameObject(filename)
{
	
}

void Background::Render()
{
	Graphic::Render(this);
}
