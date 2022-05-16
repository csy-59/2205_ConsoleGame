#pragma once

#include "Framework/Text.h"
typedef struct tagGameOver {
	Text	Text[2][1024];
} GameOver;

void GameOver_Init(GameOver* gameOver);
void GameOver_Update(GameOver* gameOver);
void GameOver_Render(GameOver* gameOver);
void GameOver_Release(GameOver* gameOver);
