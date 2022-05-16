#pragma once

#include "Common.h"
#include "Gun.h"
#include "Enemy.h"

#include "Framework/Text.h"

typedef struct tagPlayer
{
	Text	Text;
	COORD	Coord;
	Gun		YellowGun;
	Gun		MagentaGun;
	float	MaxShootSpeed;
	float	ShootSpeed;

	Enemy	Enemy;
} Player;

void Player_Init(Player* player);
void Player_Update(Player* player);
void Player_Render(Player* player);
void Player_Release(Player* player);
void Player_Die(Player* player);