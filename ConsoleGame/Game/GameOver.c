#include "GameOver.h"

#include "Framework/Input.h"
#include "Framework/Scene.h"
#include "Framework/Renderer.h"
void GameOver_Init(GameOver* gameOver) {
	TextCopyWithWhite(gameOver->Text[0], L"Game Over!");
	TextCopyWithWhite(gameOver->Text[1], L"스페이스를 눌러 메인으로 돌아갑니다.");
}

void GameOver_Update(GameOver* gameOver) {
	if (Input_GetKey(VK_SPACE)) {
		Scene_SetNextScene(SCENE_TITLE);
	}
}

void GameOver_Render(GameOver* gameOver) {
	Renderer_DrawText(&gameOver->Text[0], TextLen(&gameOver->Text[0]), 0, 0);
	Renderer_DrawText(&gameOver->Text[1], TextLen(&gameOver->Text[1]), 0, 1);
}

void GameOver_Release(GameOver* gameOver) {

}
