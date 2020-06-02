#pragma once
#include "GameObject.h"
#include "ColliderManager.h"

class Bullet : public GameObject
{
public:
	Bullet(LPCWSTR filename);

	void Move();
	void Attack(GameObject* obj);
};

