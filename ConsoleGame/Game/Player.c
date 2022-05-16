#include "Player.h"

#include "Framework/Input.h"
#include "Framework/Renderer.h"
#include "Framework/Timer.h"

void Player_Init(Player* player)
{
	TextCopyWithWhite(&player->Text, L"P");
	SetCoord(player->Coord, 0, 0);
	Gun_Init(&player->YellowGun, TEXT_COLOR_YELLOW | TEXT_COLOR_STRONG);
	Gun_Init(&player->MagentaGun, TEXT_COLOR_MAGENTA | TEXT_COLOR_STRONG);
	player->MaxShootSpeed = 0.3f;
	player->ShootSpeed = 0.0f;
}

void Player_Update(Player* player)
{
	if (Input_GetKey(VK_DOWN))
	{
		++player->Coord.Y;
	}

	if (Input_GetKey(VK_UP))
	{
		--player->Coord.Y;
	}

	if (Input_GetKey(VK_LEFT))
	{
		--player->Coord.X;
	}

	if (Input_GetKey(VK_RIGHT))
	{
		++player->Coord.X;
	}

	/*
	if (Input_GetKey(VK_SPACE))
	{
		Gun_Shoot(&player->Gun, player->Coord.X + 1, player->Coord.Y);
	}
	*/
	if (player->ShootSpeed <= 0) {
		if (Input_GetKey(VK_NUMPAD1)) {
			Gun_Shoot(&player->YellowGun, player->Coord.X + 1, player->Coord.Y);
			player->ShootSpeed = player->MaxShootSpeed;
		}

		if (Input_GetKey(VK_NUMPAD2)) {
			Gun_Shoot(&player->MagentaGun, player->Coord.X + 1, player->Coord.Y);
			player->ShootSpeed = player->MaxShootSpeed;
		}
	}
	else {
		player->ShootSpeed -= DELTA_TIME;
	}

	Gun_Update(&player->YellowGun);
	Gun_Update(&player->MagentaGun);
}

void Player_Render(Player* player)
{
	Text* text = &player->Text;
	Renderer_DrawText(text, 1, player->Coord.X, player->Coord.Y);

	Gun_Render(&player->YellowGun);
	Gun_Render(&player->MagentaGun);
}

void Player_Release(Player* player)
{
	Gun_Release(&player->YellowGun);
	Gun_Release(&player->MagentaGun);
}