#include "Enemy.h"

void Enemy_Init(Enemy* enemy) {
	SetCoord(enemy->Coord, 150, 30);
	TextCopy(&enemy->Text, L"E", TEXT_COLOR_RED | TEXT_COLOR_STRONG);
	enemy->Health = 30;
}

void Enemy_Update(Enemy* enemy,const COORD playerCoord) {
	if (playerCoord.X > enemy->Coord.X) {
		enemy->Coord.X++;
	}
	else {
		enemy->Coord.X--;
	}

	if (playerCoord.Y > enemy->Coord.Y) {
		enemy->Coord.Y++;
	}
	else {
		enemy->Coord.Y--;
	}
}

void Enemy_Render(Enemy* enemy) {

}

void Enemy_Release(Enemy* enemy) {

}