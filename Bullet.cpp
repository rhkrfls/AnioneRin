#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(LPCWSTR filename) : GameObject(filename)
{
}

void Bullet::Move()
{
	position.y -= 10;
}

void Bullet::Attack(GameObject * obj)
{
	if (ColliderManager::BoxCollider(this, obj))
	{
		obj->exist = false;
	}
}
