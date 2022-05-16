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
������ ���������� �ڵ�����

���� �ü� :	������		-> ��������
			����ü		-> ������ ���
			if			-> ���࿡
			switch		-> ���Ѵ°�
			�Լ�			-> ���нð��� ����
			�����ӿ�ũ	-> ������ �� �ȱ�
			void		-> �ҳ�(�̾���)
			char		-> ��
			Coord		-> �߿�
			Macro		-> �ҹ����ӷ�
			����			-> ���ᷯ
			�����		-> �˰��� �Ϳ����




			- ����� �ϴµ� ��û�� ������....

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