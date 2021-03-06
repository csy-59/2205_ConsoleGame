#pragma once

#include "Type.h"
#include "Text.h"

/// <summary>
/// 렌더러를 초기화한다.
/// </summary>
/// <returns>초기화 성공하면 true, 아니면 false</returns>
bool	Renderer_Init(void);

/// <summary>
/// 렌더러를 정리한다.
/// </summary>
void	Renderer_Cleanup(void);

/// <summary>
/// 화면을 바꾼다.
/// </summary>
void	Renderer_Flip(void);

/// <summary>
/// 텍스트를 출력한다.
/// </summary>
/// <param name="text">텍스트</param>
/// <param name="numberOfChar">출력할 문자의 개수</param>
/// <param name="x">출력할 위치</param>
/// <param name="y">출력할 위치</param>
void	Renderer_DrawText(const Text* text, int32 numberOfChar, int32 x, int32 y);

