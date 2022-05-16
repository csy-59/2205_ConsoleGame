#pragma once

#include "Type.h"
#include "Framework/Text.h"

typedef struct tagEnemy {
	Text	Text;
	COORD	Coord;
	int32	Health;
} Enemy;

void Enemy_Init(Enemy* enemy);
void Enemy_Update(Enemy* enemy, const COORD playerCoord);
void Enemy_Render(Enemy* enemy);
void Enemy_Release(Enemy* enemy);