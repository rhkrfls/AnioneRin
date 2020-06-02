#include "stdafx.h"
#include "Player.h"

Player::Player(LPCWSTR filename) : GameObject(filename)
{
	for (int i = 0; i < 10; i++)
		bullet[i] = new Bullet(L"bullet.png");

	currentbullet = 0;

	Ani_Bitmap[0] = pBitmap;
	Ani_Bitmap[1] = Graphic::Load_Bitmap(L"flower.jpg");
	Ani_Bitmap[2] = Graphic::Load_Bitmap(L"Player.png");

	Ani_Time = GetTickCount();
}

void Player::Move()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8001)
		position.x -= 10;

	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
		position.x += 10;

	if (GetAsyncKeyState(VK_UP) & 0x8001)
		position.y -= 10;

	if (GetAsyncKeyState(VK_DOWN) & 0x8001)
		position.y += 10;
}

void Player::Shot()
{
	if (GetTickCount() - bullettime > 300)
	{
		bullettime = GetTickCount();

		if (GetAsyncKeyState(VK_SPACE) & 0x8001)
		{
			currentbullet %= 10;
			bullet[currentbullet++]->position = position;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		bullet[i]->Move();
	}
}

void Player::Render()
{
	for (int i = 0; i < 10; i++)
	{
		Graphic::Render(bullet[i]);
	}

	Graphic::Render(this);
}

void Player::Animation()
{
	if (GetTickCount() - Ani_Time > 1000)
	{
		Ani_Time = GetTickCount();
		current_Ani++;
		current_Ani %= 3;

		pBitmap = Ani_Bitmap[current_Ani];
	}
}

void Player::BulletAttackCheck(GameObject * obj)
{
	for (int i = 0; i < 10; i++)
		bullet[i]->Attack(obj);
}
