#include "App.h"
#include "Common.h"
#include "Renderer.h"
#include "Timer.h"
#include "Input.h"
#include "Random.h"

#include "Framework/Scene.h"

bool App_Init()
{
	if (false == Renderer_Init())
	{
		return false;
	}

	Random_Init();

	return true;
}

/*
2022.05.16 _ 11:45
희희희 복받으세요 코딩영재

삼촌 시선 :	포인터		-> 레이져빔
			구조체		-> 구조된 사람
			if			-> 만약에
			switch		-> 불켜는거
			함수			-> 수학시간에 본거
			프레임워크	-> 프레임 위 걷기
			void		-> 소년(이었던)
			char		-> 차
			Coord		-> 추움
			Macro		-> 불법게임러
			박진			-> 즐잠러
			노우진		-> 알고보면 귀여운애




			- 노력은 하는데 멍청한 삼촌이....

*/

void processInput()
{
	Input_Update();
}

void update()
{
	g_Scene.Update();
}

void render()
{
	g_Scene.Render();
	Renderer_Flip();
}

void cleanup(void)
{
	Renderer_Cleanup();
}

int32 App_Run()
{
	atexit(cleanup);

	Timer_Init(60);

	Scene_SetNextScene(SCENE_TITLE);

	while (true)
	{
		if (Scene_IsSetNextScene())
		{
			Scene_Change();
		}

		if (Timer_Update())
		{
			processInput();		
			update();			
			render();			
		}
	}

	return 0;
}