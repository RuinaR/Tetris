#pragma once
#include<windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib");
#ifndef __STDIO_H__
#define __STDIO_H__
	#include<stdio.h>
#endif
#ifndef __STDLIB_H__
#define __STDLIB_H__
	#include<stdlib.h>
#endif
#ifndef __CONIO_H__
#define __CONIO_H__
	#include<conio.h>
#endif
#ifndef __TIME_H__
#define __TIME_H__
	#include<time.h>
#endif

#define ESC 27
#define KEY_ARROW 224
#define LEFT 75  
#define RIGHT 77 
#define UP 72  
#define DOWN 80 
#define Z_S 'z'
#define Z_B 'Z'
#define X_S 'x'
#define X_B 'X'
#define P_S 'P'
#define P_B 'p'


#define MINO_TYPE_MAX 7
#define MINO_ROTATE_MAX 4
#define MINO_BLOCK_CNT 4
#define MINO_SIZE 4

#define OFFSET_TITLE_X 5
#define OFFSET_TITLE_Y 4
#define OFFSET_GAME_X 5
#define OFFSET_GAME_Y 5
#define OFFSET_NEXTMINO_Y 3

#define GAMEAREA_X 10
#define GAMEAREA_Y 24

#define UI_PAUSE_POS_X1 1
#define UI_PAUSE_POS_Y1 10
#define UI_PAUSE_POS_X2 8 
#define UI_PAUSE_POS_Y2 15

#define UIPOS_X  OFFSET_GAME_X + GAMEAREA_X + 3
#define UIPOS_Y  OFFSET_GAME_Y + OFFSET_NEXTMINO_Y + MINO_BLOCK_CNT + 3
#define UIAREA_X  30
#define UIAREA_Y  16

#define UI_END_X 10
#define UI_END_Y 5
#define UI_END_SIZE_X 30
#define UI_END_SIZE_Y 20

#define CRATEMINO_X 3

#define ENDLINE 4

#define DRAW_WALL "в╠"
#define DRAW_CMINO "бс"
#define DRAW_SHADOWMINO "бр"
#define DRAW_SMINO "бс"
#define DRAW_ENDLINE "__"
#define DRAW_EMPTY "  "
#define DRAW_EMPTY_BLOCKSIZE "        "
#define DRAW_PAUSE_UI "  "
#define DRAW_EMPTY_UILINE "                                                            "
#define DRAW_UI "  "
#define DRAW_UIFRAME "  "
#define DRAW_UI_END_FRAME "в╠"
#define DRAW_EMPTY_UILINE_END "                                              "

#define FRAME_UNIT 10

#define MINOBGCOLOR COLOR_BLACK
#define GAMEMAPCOLOR COLOR_GRAY
#define ENDLINECOLOR COLOR_RED
#define PAUSEUICOLOR COLOR_WHITE
#define PAUSEUI_TEXTCOLOR COLOR_BLACK
#define SHADOWMINO_COLOR COLOR_BLACK
#define UIAREA_COLOR COLOR_GRAY
#define UITEXT_COLOR COLOR_BLACK
#define UIFRAME_COLOR COLOR_DARK_GRAY
#define UI_END_FRAME_COLOR COLOR_YELLOW
#define UI_END_FRAME_BG_COLOR COLOR_BLACK
#define EXIT_BG_COLOR COLOR_BLACK
#define EXIT_COLOR COLOR_GREEN
#define SUBUI_BG_COLOR COLOR_BLACK
#define SUBUI_COLOR COLOR_GREEN


#define WINDOWSIZE_X 80
#define WINDOWSIZE_Y 35

#define POINTUNIT 5
#define LEVELCNT 10
#define LEVELMAX 10
#define SHOWLVUP_TIME 40

#define DEFAULTSPEED 700
#define SPEEDUNIT 73

#define ERR -10

enum
{
	UI_0_INDEX = 0,
	UI_1_INDEX,
	UI_2_INDEX,
	UI_3_INDEX,
	UI_4_INDEX,
	UI_5_INDEX,
	UI_6_INDEX,
	UI_7_INDEX,
	UI_8_INDEX,
	UI_9_INDEX,
	UI_P_INDEX,
	UI_LVUP_INDEX,
	UI_INDEX_MAX
};
enum
{
	UI_0_CNT = 28,
	UI_1_CNT = 14,
	UI_2_CNT = 28,
	UI_3_CNT = 29,
	UI_4_CNT = 26,
	UI_5_CNT = 32,
	UI_6_CNT = 31,
	UI_7_CNT = 21,
	UI_8_CNT = 34,
	UI_9_CNT = 31,
	UI_P_CNT = 9,
	UI_LVUP_CNT = 72
};
enum
{
	MINO_EMPTY = -1,
	MINO_I = 0,
	MINO_O,
	MINO_T,
	MINO_L,
	MINO_J,
	MINO_S,
	MINO_Z,
};
enum
{
	COLOR_BLACK = 0,
	COLOR_WHITE = 15,
	COLOR_BLUE = 9,
	COLOR_SKYBLUE = 11,
	COLOR_RED = 12,
	COLOR_DARK_RED =4,
	COLOR_ORANGE = 6,
	COLOR_YELLOW = 14,
	COLOR_PURLPE = 13,
	COLOR_GREEN = 10,
	COLOR_GRAY = 7,
	COLOR_DARK_GRAY = 8
};

typedef struct _C_NODE
{
	int nMinoType;
	_C_NODE* after;
}C_NODE;

void SetTextColor(int bgColor, int textColor);
void GotoxyDraw(int x, int y, const char* str);
void Gotoxy(int x, int y);
void SetNoCursor(void);
void InitData(void);
void DrawMino(int nX, int nY, int MINO_TYPE, int MINO_ROTATE);
void DrawCMino(void);
void DrawSMino(int nX, int nY, int MINO_TYPE, int MINO_ROTATE);
void DeleteMinoArea(int MinoPosX, int MinoPosY, int MINO_TYPE, int MINO_ROTATE);
void DeleteCMinoArea(void);
void Title(void);
void Game(void);
void DrawWall(void);
void DrawEndLine(void);
BOOL CheckCol(int MinoPosX, int MinoPosY, int MINO_TYPE, int MINO_ROTATE);
void UpdateGameMapAll(void);
void ChangeCtoS(void);
BOOL CheckGameOver(void);
void GameOver(void);
void ResetGameMap(void);
void SetNewMinoData(void);
void DrawNextMinoInfoWall(void);
void UpdateNextMinoInfo(void);
void CheckKey(void);
void CheckLine(void);
void DrawMapData(void);
void ShowDebugData(void);
void UpdateGameMapArea(int x1, int y1, int x2, int y2);
void Pause(void);
void DrawShadowMino(void);
void DeleteShadowMino(void);
void DeleteUIArea(void);
void DrawUIFrame(void);
void UpdateUI(unsigned int point);
void DrawUI_ShowLVUP();
void GetBestScore(void);
void SaveBestScore(void);
void ShowEnd(void);
void Exit(void);
void SubUIUpdate(void);
void ShowKeyExplain(void);

void InitHead(void);
void InsertNode(int nType);
int GetDataFromNode(unsigned int nAfterCnt);
void DeleteAllNode(void);
