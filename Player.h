#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Player : public GameObject
{
private:
	ID2D1Bitmap * Ani_Bitmap[3];
	Bullet * bullet[10];
	int currentbullet;
	float bullettime = 0;

	int current_Ani = 0;
	float Ani_Time = 0;

public:
	Player(LPCWSTR filename);

	void Move();
	void Shot();
	void Render();
	void Animation();
	void BulletAttackCheck(GameObject* obj);
};

