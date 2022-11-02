#include "tetris.h"


COORD arrUIDATA_Num_0[UI_0_CNT];
COORD arrUIDATA_Num_1[UI_1_CNT];
COORD arrUIDATA_Num_2[UI_2_CNT];
COORD arrUIDATA_Num_3[UI_3_CNT];
COORD arrUIDATA_Num_4[UI_4_CNT];
COORD arrUIDATA_Num_5[UI_5_CNT];
COORD arrUIDATA_Num_6[UI_6_CNT];
COORD arrUIDATA_Num_7[UI_7_CNT];
COORD arrUIDATA_Num_8[UI_8_CNT];
COORD arrUIDATA_Num_9[UI_9_CNT];
COORD arrUIDATA_Num_P[UI_P_CNT];
COORD arrUIData_LvUp[UI_LVUP_CNT];

COORD* arrUIData[UI_INDEX_MAX];
int arrUIDataSize[UI_INDEX_MAX];

//int arrUIData[UIAREA_X2 - UIAREA_X1 + 1][UIAREA_Y2 - UIAREA_Y1 + 1];
int arrMinoColor[MINO_TYPE_MAX] = { 0 };
COORD arrMinoData[MINO_TYPE_MAX][MINO_ROTATE_MAX][MINO_BLOCK_CNT] = { 0 };
int arrGameMapData[GAMEAREA_X][GAMEAREA_Y] = { 0 };
C_NODE * head = NULL;
COORD CMinoPos = { 0 };
COORD changePos = { 0 };
int isGameOver = FALSE;
int nMinoBagCnt = 0;
int nCMinoType = 0;
int nCMinoRotate = 0;
int nChangeRotate = 0;
int nNextMinoType = -1;
int nShadowMino_y = 0;

int nBestScore = 0;
int nScore = 0;
int nLevelCnt = 0;
int nLevel = 0;
int nGameSpeed = 0;
BOOL ShowLvUp = FALSE;

void SetTextColor(int bgColor, int textColor)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (bgColor << 4) + textColor);
}

void GotoxyDraw(int x, int y, const char * str)
{ 
	COORD pos = { (SHORT)(x * 2), (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s", str);
}
void Gotoxy(int x, int y)
{
	COORD pos = { (SHORT)(x * 2), (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void SetNoCursor(void)
{
	CONSOLE_CURSOR_INFO CurInfo = { 0 };
	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}
void InitData(void) //겁나 기니까 접어두세요
{
	//Data입력
	{
		// I
		{
			arrMinoData[0][0][0].X = 0;
			arrMinoData[0][0][0].Y = 2;
			arrMinoData[0][0][1].X = 1;
			arrMinoData[0][0][1].Y = 2;
			arrMinoData[0][0][2].X = 2;
			arrMinoData[0][0][2].Y = 2;
			arrMinoData[0][0][3].X = 3;
			arrMinoData[0][0][3].Y = 2;

			arrMinoData[0][1][0].X = 1;
			arrMinoData[0][1][0].Y = 0;
			arrMinoData[0][1][1].X = 1;
			arrMinoData[0][1][1].Y = 1;
			arrMinoData[0][1][2].X = 1;
			arrMinoData[0][1][2].Y = 2;
			arrMinoData[0][1][3].X = 1;
			arrMinoData[0][1][3].Y = 3;

			arrMinoData[0][2][0].X = 0;
			arrMinoData[0][2][0].Y = 1;
			arrMinoData[0][2][1].X = 1;
			arrMinoData[0][2][1].Y = 1;
			arrMinoData[0][2][2].X = 2;
			arrMinoData[0][2][2].Y = 1;
			arrMinoData[0][2][3].X = 3;
			arrMinoData[0][2][3].Y = 1;

			arrMinoData[0][3][0].X = 2;
			arrMinoData[0][3][0].Y = 0;
			arrMinoData[0][3][1].X = 2;
			arrMinoData[0][3][1].Y = 1;
			arrMinoData[0][3][2].X = 2;
			arrMinoData[0][3][2].Y = 2;
			arrMinoData[0][3][3].X = 2;
			arrMinoData[0][3][3].Y = 3;
		}

		// O
		{
			arrMinoData[1][0][0].X = 1;
			arrMinoData[1][0][0].Y = 1;
			arrMinoData[1][0][1].X = 2;
			arrMinoData[1][0][1].Y = 1;
			arrMinoData[1][0][2].X = 1;
			arrMinoData[1][0][2].Y = 2;
			arrMinoData[1][0][3].X = 2;
			arrMinoData[1][0][3].Y = 2;

			arrMinoData[1][1][0].X = 1;
			arrMinoData[1][1][0].Y = 1;
			arrMinoData[1][1][1].X = 2;
			arrMinoData[1][1][1].Y = 1;
			arrMinoData[1][1][2].X = 1;
			arrMinoData[1][1][2].Y = 2;
			arrMinoData[1][1][3].X = 2;
			arrMinoData[1][1][3].Y = 2;

			arrMinoData[1][2][0].X = 1;
			arrMinoData[1][2][0].Y = 1;
			arrMinoData[1][2][1].X = 2;
			arrMinoData[1][2][1].Y = 1;
			arrMinoData[1][2][2].X = 1;
			arrMinoData[1][2][2].Y = 2;
			arrMinoData[1][2][3].X = 2;
			arrMinoData[1][2][3].Y = 2;

			arrMinoData[1][3][0].X = 1;
			arrMinoData[1][3][0].Y = 1;
			arrMinoData[1][3][1].X = 2;
			arrMinoData[1][3][1].Y = 1;
			arrMinoData[1][3][2].X = 1;
			arrMinoData[1][3][2].Y = 2;
			arrMinoData[1][3][3].X = 2;
			arrMinoData[1][3][3].Y = 2;
		}

		// T
		{
			arrMinoData[2][0][0].X = 2;
			arrMinoData[2][0][0].Y = 1;
			arrMinoData[2][0][1].X = 1;
			arrMinoData[2][0][1].Y = 2;
			arrMinoData[2][0][2].X = 2;
			arrMinoData[2][0][2].Y = 2;
			arrMinoData[2][0][3].X = 3;
			arrMinoData[2][0][3].Y = 2;

			arrMinoData[2][1][0].X = 2;
			arrMinoData[2][1][0].Y = 1;
			arrMinoData[2][1][1].X = 2;
			arrMinoData[2][1][1].Y = 2;
			arrMinoData[2][1][2].X = 2;
			arrMinoData[2][1][2].Y = 3;
			arrMinoData[2][1][3].X = 3;
			arrMinoData[2][1][3].Y = 2;

			arrMinoData[2][2][0].X = 1;
			arrMinoData[2][2][0].Y = 2;
			arrMinoData[2][2][1].X = 2;
			arrMinoData[2][2][1].Y = 2;
			arrMinoData[2][2][2].X = 3;
			arrMinoData[2][2][2].Y = 2;
			arrMinoData[2][2][3].X = 2;
			arrMinoData[2][2][3].Y = 3;

			arrMinoData[2][3][0].X = 2;
			arrMinoData[2][3][0].Y = 1;
			arrMinoData[2][3][1].X = 1;
			arrMinoData[2][3][1].Y = 2;
			arrMinoData[2][3][2].X = 2;
			arrMinoData[2][3][2].Y = 2;
			arrMinoData[2][3][3].X = 2;
			arrMinoData[2][3][3].Y = 3;
		}

		// L
		{
			arrMinoData[3][0][0].X = 3;
			arrMinoData[3][0][0].Y = 1;
			arrMinoData[3][0][1].X = 1;
			arrMinoData[3][0][1].Y = 2;
			arrMinoData[3][0][2].X = 2;
			arrMinoData[3][0][2].Y = 2;
			arrMinoData[3][0][3].X = 3;
			arrMinoData[3][0][3].Y = 2;

			arrMinoData[3][1][0].X = 2;
			arrMinoData[3][1][0].Y = 1;
			arrMinoData[3][1][1].X = 2;
			arrMinoData[3][1][1].Y = 2;
			arrMinoData[3][1][2].X = 2;
			arrMinoData[3][1][2].Y = 3;
			arrMinoData[3][1][3].X = 3;
			arrMinoData[3][1][3].Y = 3;

			arrMinoData[3][2][0].X = 1;
			arrMinoData[3][2][0].Y = 2;
			arrMinoData[3][2][1].X = 1;
			arrMinoData[3][2][1].Y = 3;
			arrMinoData[3][2][2].X = 2;
			arrMinoData[3][2][2].Y = 2;
			arrMinoData[3][2][3].X = 3;
			arrMinoData[3][2][3].Y = 2;

			arrMinoData[3][3][0].X = 1;
			arrMinoData[3][3][0].Y = 1;
			arrMinoData[3][3][1].X = 2;
			arrMinoData[3][3][1].Y = 1;
			arrMinoData[3][3][2].X = 2;
			arrMinoData[3][3][2].Y = 2;
			arrMinoData[3][3][3].X = 2;
			arrMinoData[3][3][3].Y = 3;
		}

		// J
		{
			arrMinoData[4][0][0].X = 1;
			arrMinoData[4][0][0].Y = 1;
			arrMinoData[4][0][1].X = 1;
			arrMinoData[4][0][1].Y = 2;
			arrMinoData[4][0][2].X = 2;
			arrMinoData[4][0][2].Y = 2;
			arrMinoData[4][0][3].X = 3;
			arrMinoData[4][0][3].Y = 2;

			arrMinoData[4][1][0].X = 2;
			arrMinoData[4][1][0].Y = 1;
			arrMinoData[4][1][1].X = 2;
			arrMinoData[4][1][1].Y = 2;
			arrMinoData[4][1][2].X = 2;
			arrMinoData[4][1][2].Y = 3;
			arrMinoData[4][1][3].X = 3;
			arrMinoData[4][1][3].Y = 1;

			arrMinoData[4][2][0].X = 1;
			arrMinoData[4][2][0].Y = 2;
			arrMinoData[4][2][1].X = 2;
			arrMinoData[4][2][1].Y = 2;
			arrMinoData[4][2][2].X = 3;
			arrMinoData[4][2][2].Y = 2;
			arrMinoData[4][2][3].X = 3;
			arrMinoData[4][2][3].Y = 3;

			arrMinoData[4][3][0].X = 2;
			arrMinoData[4][3][0].Y = 1;
			arrMinoData[4][3][1].X = 2;
			arrMinoData[4][3][1].Y = 2;
			arrMinoData[4][3][2].X = 2;
			arrMinoData[4][3][2].Y = 3;
			arrMinoData[4][3][3].X = 1;
			arrMinoData[4][3][3].Y = 3;
		}

		// S
		{
			arrMinoData[5][0][0].X = 2;
			arrMinoData[5][0][0].Y = 1;
			arrMinoData[5][0][1].X = 3;
			arrMinoData[5][0][1].Y = 1;
			arrMinoData[5][0][2].X = 1;
			arrMinoData[5][0][2].Y = 2;
			arrMinoData[5][0][3].X = 2;
			arrMinoData[5][0][3].Y = 2;

			arrMinoData[5][1][0].X = 2;
			arrMinoData[5][1][0].Y = 1;
			arrMinoData[5][1][1].X = 2;
			arrMinoData[5][1][1].Y = 2;
			arrMinoData[5][1][2].X = 3;
			arrMinoData[5][1][2].Y = 2;
			arrMinoData[5][1][3].X = 3;
			arrMinoData[5][1][3].Y = 3;

			arrMinoData[5][2][0].X = 2;
			arrMinoData[5][2][0].Y = 2;
			arrMinoData[5][2][1].X = 3;
			arrMinoData[5][2][1].Y = 2;
			arrMinoData[5][2][2].X = 2;
			arrMinoData[5][2][2].Y = 3;
			arrMinoData[5][2][3].X = 1;
			arrMinoData[5][2][3].Y = 3;

			arrMinoData[5][3][0].X = 1;
			arrMinoData[5][3][0].Y = 1;
			arrMinoData[5][3][1].X = 1;
			arrMinoData[5][3][1].Y = 2;
			arrMinoData[5][3][2].X = 2;
			arrMinoData[5][3][2].Y = 2;
			arrMinoData[5][3][3].X = 2;
			arrMinoData[5][3][3].Y = 3;
		}

		// Z
		{
			arrMinoData[6][0][0].X = 1;
			arrMinoData[6][0][0].Y = 1;
			arrMinoData[6][0][1].X = 2;
			arrMinoData[6][0][1].Y = 1;
			arrMinoData[6][0][2].X = 2;
			arrMinoData[6][0][2].Y = 2;
			arrMinoData[6][0][3].X = 3;
			arrMinoData[6][0][3].Y = 2;

			arrMinoData[6][1][0].X = 3;
			arrMinoData[6][1][0].Y = 1;
			arrMinoData[6][1][1].X = 3;
			arrMinoData[6][1][1].Y = 2;
			arrMinoData[6][1][2].X = 2;
			arrMinoData[6][1][2].Y = 2;
			arrMinoData[6][1][3].X = 2;
			arrMinoData[6][1][3].Y = 3;

			arrMinoData[6][2][0].X = 1;
			arrMinoData[6][2][0].Y = 2;
			arrMinoData[6][2][1].X = 2;
			arrMinoData[6][2][1].Y = 2;
			arrMinoData[6][2][2].X = 2;
			arrMinoData[6][2][2].Y = 3;
			arrMinoData[6][2][3].X = 3;
			arrMinoData[6][2][3].Y = 3;

			arrMinoData[6][3][0].X = 2;
			arrMinoData[6][3][0].Y = 1;
			arrMinoData[6][3][1].X = 2;
			arrMinoData[6][3][1].Y = 2;
			arrMinoData[6][3][2].X = 1;
			arrMinoData[6][3][2].Y = 2;
			arrMinoData[6][3][3].X = 1;
			arrMinoData[6][3][3].Y = 3;
		}

		//COLOR
		{
			arrMinoColor[MINO_I] = COLOR_SKYBLUE;
			arrMinoColor[MINO_O] = COLOR_YELLOW;
			arrMinoColor[MINO_T] = COLOR_PURLPE;
			arrMinoColor[MINO_L] = COLOR_DARK_RED;
			arrMinoColor[MINO_J] = COLOR_BLUE;
			arrMinoColor[MINO_S] = COLOR_GREEN;
			arrMinoColor[MINO_Z] = COLOR_RED;
		}

		//UI_LVUP
		{
			arrUIData_LvUp[0].X = 2;
			arrUIData_LvUp[0].Y = 3;
			arrUIData_LvUp[1].X = 2;
			arrUIData_LvUp[1].Y = 4;
			arrUIData_LvUp[2].X = 2;
			arrUIData_LvUp[2].Y = 5;
			arrUIData_LvUp[3].X = 2;
			arrUIData_LvUp[3].Y = 6;
			arrUIData_LvUp[4].X = 2;
			arrUIData_LvUp[4].Y = 7;
			arrUIData_LvUp[5].X = 2;
			arrUIData_LvUp[5].Y = 8;
			arrUIData_LvUp[6].X = 2;
			arrUIData_LvUp[6].Y = 9;
			arrUIData_LvUp[7].X = 2;
			arrUIData_LvUp[7].Y = 10;
			arrUIData_LvUp[8].X = 2;
			arrUIData_LvUp[8].Y = 11;
			arrUIData_LvUp[9].X = 2;
			arrUIData_LvUp[9].Y = 12;
			arrUIData_LvUp[10].X = 3;
			arrUIData_LvUp[10].Y = 12;
			arrUIData_LvUp[11].X = 4;
			arrUIData_LvUp[11].Y = 12;
			arrUIData_LvUp[12].X = 5;
			arrUIData_LvUp[12].Y = 12;
			arrUIData_LvUp[13].X = 6;
			arrUIData_LvUp[13].Y = 12;
			arrUIData_LvUp[14].X = 7;
			arrUIData_LvUp[14].Y = 3;
			arrUIData_LvUp[15].X = 7;
			arrUIData_LvUp[15].Y = 4;
			arrUIData_LvUp[16].X = 7;
			arrUIData_LvUp[16].Y = 5;
			arrUIData_LvUp[17].X = 8;
			arrUIData_LvUp[17].Y = 6;
			arrUIData_LvUp[18].X = 8;
			arrUIData_LvUp[18].Y = 7;
			arrUIData_LvUp[19].X = 8;
			arrUIData_LvUp[19].Y = 8;
			arrUIData_LvUp[20].X = 9;
			arrUIData_LvUp[20].Y = 9;
			arrUIData_LvUp[21].X = 9;
			arrUIData_LvUp[21].Y = 10;
			arrUIData_LvUp[22].X = 9;
			arrUIData_LvUp[22].Y = 11;
			arrUIData_LvUp[23].X = 10;
			arrUIData_LvUp[23].Y = 12;
			arrUIData_LvUp[24].X = 11;
			arrUIData_LvUp[24].Y = 11;
			arrUIData_LvUp[25].X = 11;
			arrUIData_LvUp[25].Y = 10;
			arrUIData_LvUp[26].X = 11;
			arrUIData_LvUp[26].Y = 9;
			arrUIData_LvUp[27].X = 12;
			arrUIData_LvUp[27].Y = 8;
			arrUIData_LvUp[28].X = 12;
			arrUIData_LvUp[28].Y = 7;
			arrUIData_LvUp[29].X = 12;
			arrUIData_LvUp[29].Y = 6;
			arrUIData_LvUp[30].X = 13;
			arrUIData_LvUp[30].Y = 5;
			arrUIData_LvUp[31].X = 13;
			arrUIData_LvUp[31].Y = 4;
			arrUIData_LvUp[32].X = 13;
			arrUIData_LvUp[32].Y = 3;
			arrUIData_LvUp[33].X = 17;
			arrUIData_LvUp[33].Y = 3;
			arrUIData_LvUp[34].X = 17;
			arrUIData_LvUp[34].Y = 4;
			arrUIData_LvUp[35].X = 17;
			arrUIData_LvUp[35].Y = 5;
			arrUIData_LvUp[36].X = 17;
			arrUIData_LvUp[36].Y = 6;
			arrUIData_LvUp[37].X = 17;
			arrUIData_LvUp[37].Y = 7;
			arrUIData_LvUp[38].X = 17;
			arrUIData_LvUp[38].Y = 8;
			arrUIData_LvUp[39].X = 17;
			arrUIData_LvUp[39].Y = 9;
			arrUIData_LvUp[40].X = 18;
			arrUIData_LvUp[40].Y = 10;
			arrUIData_LvUp[41].X = 18;
			arrUIData_LvUp[41].Y = 11;
			arrUIData_LvUp[42].X = 19;
			arrUIData_LvUp[42].Y = 12;
			arrUIData_LvUp[43].X = 20;
			arrUIData_LvUp[43].Y = 12;
			arrUIData_LvUp[44].X = 21;
			arrUIData_LvUp[44].Y = 11;
			arrUIData_LvUp[45].X = 21;
			arrUIData_LvUp[45].Y = 10;
			arrUIData_LvUp[46].X = 22;
			arrUIData_LvUp[46].Y = 9;
			arrUIData_LvUp[47].X = 22;
			arrUIData_LvUp[47].Y = 8;
			arrUIData_LvUp[48].X = 22;
			arrUIData_LvUp[48].Y = 7;
			arrUIData_LvUp[49].X = 22;
			arrUIData_LvUp[49].Y = 6;
			arrUIData_LvUp[50].X = 22;
			arrUIData_LvUp[50].Y = 5;
			arrUIData_LvUp[51].X = 22;
			arrUIData_LvUp[51].Y = 4;
			arrUIData_LvUp[52].X = 22;
			arrUIData_LvUp[52].Y = 3;
			arrUIData_LvUp[53].X = 24;
			arrUIData_LvUp[53].Y = 3;
			arrUIData_LvUp[54].X = 24;
			arrUIData_LvUp[54].Y = 4;
			arrUIData_LvUp[55].X = 24;
			arrUIData_LvUp[55].Y = 5;
			arrUIData_LvUp[56].X = 24;
			arrUIData_LvUp[56].Y = 6;
			arrUIData_LvUp[57].X = 24;
			arrUIData_LvUp[57].Y = 7;
			arrUIData_LvUp[58].X = 24;
			arrUIData_LvUp[58].Y = 8;
			arrUIData_LvUp[59].X = 24;
			arrUIData_LvUp[59].Y = 9;
			arrUIData_LvUp[60].X = 24;
			arrUIData_LvUp[60].Y = 10;
			arrUIData_LvUp[61].X = 24;
			arrUIData_LvUp[61].Y = 11;
			arrUIData_LvUp[62].X = 24;
			arrUIData_LvUp[62].Y = 12;
			arrUIData_LvUp[63].X = 25;
			arrUIData_LvUp[63].Y = 3;
			arrUIData_LvUp[64].X = 26;
			arrUIData_LvUp[64].Y = 3;
			arrUIData_LvUp[65].X = 27;
			arrUIData_LvUp[65].Y = 3;
			arrUIData_LvUp[66].X = 28;
			arrUIData_LvUp[66].Y = 4;
			arrUIData_LvUp[67].X = 28;
			arrUIData_LvUp[67].Y = 5;
			arrUIData_LvUp[68].X = 28;
			arrUIData_LvUp[68].Y = 6;
			arrUIData_LvUp[69].X = 27;
			arrUIData_LvUp[69].Y = 7;
			arrUIData_LvUp[70].X = 26;
			arrUIData_LvUp[70].Y = 7;
			arrUIData_LvUp[71].X = 25;
			arrUIData_LvUp[71].Y = 7;
		}

		//UI_0
		{
			arrUIDATA_Num_0[0].X = 4;
			arrUIDATA_Num_0[0].Y = 1;
			arrUIDATA_Num_0[1].X = 3;
			arrUIDATA_Num_0[1].Y = 2;
			arrUIDATA_Num_0[2].X = 2;
			arrUIDATA_Num_0[2].Y = 3;
			arrUIDATA_Num_0[3].X = 2;
			arrUIDATA_Num_0[3].Y = 4;
			arrUIDATA_Num_0[4].X = 1;
			arrUIDATA_Num_0[4].Y = 5;
			arrUIDATA_Num_0[5].X = 1;
			arrUIDATA_Num_0[5].Y = 6;
			arrUIDATA_Num_0[6].X = 1;
			arrUIDATA_Num_0[6].Y = 7;
			arrUIDATA_Num_0[7].X = 1;
			arrUIDATA_Num_0[7].Y = 8;
			arrUIDATA_Num_0[8].X = 1;
			arrUIDATA_Num_0[8].Y = 9;
			arrUIDATA_Num_0[9].X = 1;
			arrUIDATA_Num_0[9].Y = 10;
			arrUIDATA_Num_0[10].X = 2;
			arrUIDATA_Num_0[10].Y = 11;
			arrUIDATA_Num_0[11].X = 2;
			arrUIDATA_Num_0[11].Y = 12;
			arrUIDATA_Num_0[12].X = 3;
			arrUIDATA_Num_0[12].Y = 13;
			arrUIDATA_Num_0[13].X = 4;
			arrUIDATA_Num_0[13].Y = 14;
			arrUIDATA_Num_0[14].X = 5;
			arrUIDATA_Num_0[14].Y = 14;
			arrUIDATA_Num_0[15].X = 6;
			arrUIDATA_Num_0[15].Y = 13;
			arrUIDATA_Num_0[16].X = 7;
			arrUIDATA_Num_0[16].Y = 12;
			arrUIDATA_Num_0[17].X = 7;
			arrUIDATA_Num_0[17].Y = 11;
			arrUIDATA_Num_0[18].X = 8;
			arrUIDATA_Num_0[18].Y = 10;
			arrUIDATA_Num_0[19].X = 8;
			arrUIDATA_Num_0[19].Y = 9;
			arrUIDATA_Num_0[20].X = 8;
			arrUIDATA_Num_0[20].Y = 8;
			arrUIDATA_Num_0[21].X = 8;
			arrUIDATA_Num_0[21].Y = 7;
			arrUIDATA_Num_0[22].X = 8;
			arrUIDATA_Num_0[22].Y = 6;
			arrUIDATA_Num_0[23].X = 8;
			arrUIDATA_Num_0[23].Y = 5;
			arrUIDATA_Num_0[24].X = 7;
			arrUIDATA_Num_0[24].Y = 4;
			arrUIDATA_Num_0[25].X = 7;
			arrUIDATA_Num_0[25].Y = 3;
			arrUIDATA_Num_0[26].X = 6;
			arrUIDATA_Num_0[26].Y = 2;
			arrUIDATA_Num_0[27].X = 5;
			arrUIDATA_Num_0[27].Y = 1;
		}

		//UI_1
		{
			arrUIDATA_Num_1[0].X = 4;
			arrUIDATA_Num_1[0].Y = 1;
			arrUIDATA_Num_1[1].X = 4;
			arrUIDATA_Num_1[1].Y = 2;
			arrUIDATA_Num_1[2].X = 4;
			arrUIDATA_Num_1[2].Y = 3;
			arrUIDATA_Num_1[3].X = 4;
			arrUIDATA_Num_1[3].Y = 4;
			arrUIDATA_Num_1[4].X = 4;
			arrUIDATA_Num_1[4].Y = 5;
			arrUIDATA_Num_1[5].X = 4;
			arrUIDATA_Num_1[5].Y = 6;
			arrUIDATA_Num_1[6].X = 4;
			arrUIDATA_Num_1[6].Y = 7;
			arrUIDATA_Num_1[7].X = 4;
			arrUIDATA_Num_1[7].Y = 8;
			arrUIDATA_Num_1[8].X = 4;
			arrUIDATA_Num_1[8].Y = 9;
			arrUIDATA_Num_1[9].X = 4;
			arrUIDATA_Num_1[9].Y = 10;
			arrUIDATA_Num_1[10].X = 4;
			arrUIDATA_Num_1[10].Y = 11;
			arrUIDATA_Num_1[11].X = 4;
			arrUIDATA_Num_1[11].Y = 12;
			arrUIDATA_Num_1[12].X = 4;
			arrUIDATA_Num_1[12].Y = 13;
			arrUIDATA_Num_1[13].X = 4;
			arrUIDATA_Num_1[13].Y = 14;
		}

		//UI_2
		{
			arrUIDATA_Num_2[0].X = 1;
			arrUIDATA_Num_2[0].Y = 5;
			arrUIDATA_Num_2[1].X = 1;
			arrUIDATA_Num_2[1].Y = 4;
			arrUIDATA_Num_2[2].X = 1;
			arrUIDATA_Num_2[2].Y = 3;
			arrUIDATA_Num_2[3].X = 2;
			arrUIDATA_Num_2[3].Y = 2;
			arrUIDATA_Num_2[4].X = 3;
			arrUIDATA_Num_2[4].Y = 1;
			arrUIDATA_Num_2[5].X = 4;
			arrUIDATA_Num_2[5].Y = 1;
			arrUIDATA_Num_2[6].X = 5;
			arrUIDATA_Num_2[6].Y = 1;
			arrUIDATA_Num_2[7].X = 6;
			arrUIDATA_Num_2[7].Y = 1;
			arrUIDATA_Num_2[8].X = 7;
			arrUIDATA_Num_2[8].Y = 2;
			arrUIDATA_Num_2[9].X = 8;
			arrUIDATA_Num_2[9].Y = 3;
			arrUIDATA_Num_2[10].X = 8;
			arrUIDATA_Num_2[10].Y = 4;
			arrUIDATA_Num_2[11].X = 8;
			arrUIDATA_Num_2[11].Y = 5;
			arrUIDATA_Num_2[12].X = 8;
			arrUIDATA_Num_2[12].Y = 6;
			arrUIDATA_Num_2[13].X = 7;
			arrUIDATA_Num_2[13].Y = 7;
			arrUIDATA_Num_2[14].X = 6;
			arrUIDATA_Num_2[14].Y = 8;
			arrUIDATA_Num_2[15].X = 5;
			arrUIDATA_Num_2[15].Y = 9;
			arrUIDATA_Num_2[16].X = 4;
			arrUIDATA_Num_2[16].Y = 10;
			arrUIDATA_Num_2[17].X = 3;
			arrUIDATA_Num_2[17].Y = 11;
			arrUIDATA_Num_2[18].X = 2;
			arrUIDATA_Num_2[18].Y = 12;
			arrUIDATA_Num_2[19].X = 1;
			arrUIDATA_Num_2[19].Y = 13;
			arrUIDATA_Num_2[20].X = 1;
			arrUIDATA_Num_2[20].Y = 14;
			arrUIDATA_Num_2[21].X = 2;
			arrUIDATA_Num_2[21].Y = 14;
			arrUIDATA_Num_2[22].X = 3;
			arrUIDATA_Num_2[22].Y = 14;
			arrUIDATA_Num_2[23].X = 4;
			arrUIDATA_Num_2[23].Y = 14;
			arrUIDATA_Num_2[24].X = 5;
			arrUIDATA_Num_2[24].Y = 14;
			arrUIDATA_Num_2[25].X = 6;
			arrUIDATA_Num_2[25].Y = 14;
			arrUIDATA_Num_2[26].X = 7;
			arrUIDATA_Num_2[26].Y = 14;
			arrUIDATA_Num_2[27].X = 8;
			arrUIDATA_Num_2[27].Y = 14;

		}

		//UI_3
		{
			arrUIDATA_Num_3[0].X = 1;
			arrUIDATA_Num_3[0].Y = 4;
			arrUIDATA_Num_3[1].X = 1;
			arrUIDATA_Num_3[1].Y = 3;
			arrUIDATA_Num_3[2].X = 2;
			arrUIDATA_Num_3[2].Y = 2;
			arrUIDATA_Num_3[3].X = 3;
			arrUIDATA_Num_3[3].Y = 1;
			arrUIDATA_Num_3[4].X = 4;
			arrUIDATA_Num_3[4].Y = 1;
			arrUIDATA_Num_3[5].X = 5;
			arrUIDATA_Num_3[5].Y = 1;
			arrUIDATA_Num_3[6].X = 6;
			arrUIDATA_Num_3[6].Y = 1;
			arrUIDATA_Num_3[7].X = 7;
			arrUIDATA_Num_3[7].Y = 2;
			arrUIDATA_Num_3[8].X = 8;
			arrUIDATA_Num_3[8].Y = 3;
			arrUIDATA_Num_3[9].X = 8;
			arrUIDATA_Num_3[9].Y = 4;
			arrUIDATA_Num_3[10].X = 8;
			arrUIDATA_Num_3[10].Y = 5;
			arrUIDATA_Num_3[11].X = 8;
			arrUIDATA_Num_3[11].Y = 6;
			arrUIDATA_Num_3[12].X = 7;
			arrUIDATA_Num_3[12].Y = 7;
			arrUIDATA_Num_3[13].X = 6;
			arrUIDATA_Num_3[13].Y = 7;
			arrUIDATA_Num_3[14].X = 5;
			arrUIDATA_Num_3[14].Y = 7;
			arrUIDATA_Num_3[15].X = 4;
			arrUIDATA_Num_3[15].Y = 7;
			arrUIDATA_Num_3[16].X = 8;
			arrUIDATA_Num_3[16].Y = 8;
			arrUIDATA_Num_3[17].X = 8;
			arrUIDATA_Num_3[17].Y = 9;
			arrUIDATA_Num_3[18].X = 8;
			arrUIDATA_Num_3[18].Y = 10;
			arrUIDATA_Num_3[19].X = 8;
			arrUIDATA_Num_3[19].Y = 11;
			arrUIDATA_Num_3[20].X = 8;
			arrUIDATA_Num_3[20].Y = 12;
			arrUIDATA_Num_3[21].X = 7;
			arrUIDATA_Num_3[21].Y = 13;
			arrUIDATA_Num_3[22].X = 6;
			arrUIDATA_Num_3[22].Y = 14;
			arrUIDATA_Num_3[23].X = 5;
			arrUIDATA_Num_3[23].Y = 14;
			arrUIDATA_Num_3[24].X = 4;
			arrUIDATA_Num_3[24].Y = 14;
			arrUIDATA_Num_3[25].X = 3;
			arrUIDATA_Num_3[25].Y = 14;
			arrUIDATA_Num_3[26].X = 2;
			arrUIDATA_Num_3[26].Y = 13;
			arrUIDATA_Num_3[27].X = 1;
			arrUIDATA_Num_3[27].Y = 12;
			arrUIDATA_Num_3[28].X = 1;
			arrUIDATA_Num_3[28].Y = 11;
		}

		//UI_4
		{
			arrUIDATA_Num_4[0].X = 5;
			arrUIDATA_Num_4[0].Y = 1;
			arrUIDATA_Num_4[1].X = 4;
			arrUIDATA_Num_4[1].Y = 2;
			arrUIDATA_Num_4[2].X = 3;
			arrUIDATA_Num_4[2].Y = 3;
			arrUIDATA_Num_4[3].X = 2;
			arrUIDATA_Num_4[3].Y = 4;
			arrUIDATA_Num_4[4].X = 2;
			arrUIDATA_Num_4[4].Y = 5;
			arrUIDATA_Num_4[5].X = 1;
			arrUIDATA_Num_4[5].Y = 6;
			arrUIDATA_Num_4[6].X = 1;
			arrUIDATA_Num_4[6].Y = 7;
			arrUIDATA_Num_4[7].X = 2;
			arrUIDATA_Num_4[7].Y = 7;
			arrUIDATA_Num_4[8].X = 3;
			arrUIDATA_Num_4[8].Y = 7;
			arrUIDATA_Num_4[9].X = 4;
			arrUIDATA_Num_4[9].Y = 7;
			arrUIDATA_Num_4[10].X = 5;
			arrUIDATA_Num_4[10].Y = 7;
			arrUIDATA_Num_4[11].X = 6;
			arrUIDATA_Num_4[11].Y = 7;
			arrUIDATA_Num_4[12].X = 7;
			arrUIDATA_Num_4[12].Y = 7;
			arrUIDATA_Num_4[13].X = 8;
			arrUIDATA_Num_4[13].Y = 7;
			arrUIDATA_Num_4[14].X = 5;
			arrUIDATA_Num_4[14].Y = 2;
			arrUIDATA_Num_4[15].X = 5;
			arrUIDATA_Num_4[15].Y = 3;
			arrUIDATA_Num_4[16].X = 5;
			arrUIDATA_Num_4[16].Y = 4;
			arrUIDATA_Num_4[17].X = 5;
			arrUIDATA_Num_4[17].Y = 5;
			arrUIDATA_Num_4[18].X = 5;
			arrUIDATA_Num_4[18].Y = 6;
			arrUIDATA_Num_4[19].X = 5;
			arrUIDATA_Num_4[19].Y = 8;
			arrUIDATA_Num_4[20].X = 5;
			arrUIDATA_Num_4[20].Y = 9;
			arrUIDATA_Num_4[21].X = 5;
			arrUIDATA_Num_4[21].Y = 10;
			arrUIDATA_Num_4[22].X = 5;
			arrUIDATA_Num_4[22].Y = 11;
			arrUIDATA_Num_4[23].X = 5;
			arrUIDATA_Num_4[23].Y = 12;
			arrUIDATA_Num_4[24].X = 5;
			arrUIDATA_Num_4[24].Y = 13;
			arrUIDATA_Num_4[25].X = 5;
			arrUIDATA_Num_4[25].Y = 14;
		}

		//UI_5
		{
			arrUIDATA_Num_5[0].X = 1;
			arrUIDATA_Num_5[0].Y = 1;
			arrUIDATA_Num_5[1].X = 1;
			arrUIDATA_Num_5[1].Y = 2;
			arrUIDATA_Num_5[2].X = 1;
			arrUIDATA_Num_5[2].Y = 3;
			arrUIDATA_Num_5[3].X = 1;
			arrUIDATA_Num_5[3].Y = 4;
			arrUIDATA_Num_5[4].X = 1;
			arrUIDATA_Num_5[4].Y = 5;
			arrUIDATA_Num_5[5].X = 1;
			arrUIDATA_Num_5[5].Y = 6;
			arrUIDATA_Num_5[6].X = 1;
			arrUIDATA_Num_5[6].Y = 7;
			arrUIDATA_Num_5[7].X = 2;
			arrUIDATA_Num_5[7].Y = 7;
			arrUIDATA_Num_5[8].X = 3;
			arrUIDATA_Num_5[8].Y = 6;
			arrUIDATA_Num_5[9].X = 4;
			arrUIDATA_Num_5[9].Y = 6;
			arrUIDATA_Num_5[10].X = 5;
			arrUIDATA_Num_5[10].Y = 6;
			arrUIDATA_Num_5[11].X = 6;
			arrUIDATA_Num_5[11].Y = 6;
			arrUIDATA_Num_5[12].X = 7;
			arrUIDATA_Num_5[12].Y = 7;
			arrUIDATA_Num_5[13].X = 8;
			arrUIDATA_Num_5[13].Y = 8;
			arrUIDATA_Num_5[14].X = 8;
			arrUIDATA_Num_5[14].Y = 9;
			arrUIDATA_Num_5[15].X = 8;
			arrUIDATA_Num_5[15].Y = 10;
			arrUIDATA_Num_5[16].X = 8;
			arrUIDATA_Num_5[16].Y = 11;
			arrUIDATA_Num_5[17].X = 8;
			arrUIDATA_Num_5[17].Y = 12;
			arrUIDATA_Num_5[18].X = 7;
			arrUIDATA_Num_5[18].Y = 13;
			arrUIDATA_Num_5[19].X = 6;
			arrUIDATA_Num_5[19].Y = 14;
			arrUIDATA_Num_5[20].X = 5;
			arrUIDATA_Num_5[20].Y = 14;
			arrUIDATA_Num_5[21].X = 4;
			arrUIDATA_Num_5[21].Y = 14;
			arrUIDATA_Num_5[22].X = 3;
			arrUIDATA_Num_5[22].Y = 14;
			arrUIDATA_Num_5[23].X = 2;
			arrUIDATA_Num_5[23].Y = 13;
			arrUIDATA_Num_5[24].X = 1;
			arrUIDATA_Num_5[24].Y = 12;
			arrUIDATA_Num_5[25].X = 1;
			arrUIDATA_Num_5[25].Y = 11;
			arrUIDATA_Num_5[26].X = 2;
			arrUIDATA_Num_5[26].Y = 1;
			arrUIDATA_Num_5[27].X = 3;
			arrUIDATA_Num_5[27].Y = 1;
			arrUIDATA_Num_5[28].X = 4;
			arrUIDATA_Num_5[28].Y = 1;
			arrUIDATA_Num_5[29].X = 5;
			arrUIDATA_Num_5[29].Y = 1;
			arrUIDATA_Num_5[30].X = 6;
			arrUIDATA_Num_5[30].Y = 1;
			arrUIDATA_Num_5[31].X = 7;
			arrUIDATA_Num_5[31].Y = 1;
		}

		//UI_6
		{
			arrUIDATA_Num_6[0].X = 6;
			arrUIDATA_Num_6[0].Y = 1;
			arrUIDATA_Num_6[1].X = 5;
			arrUIDATA_Num_6[1].Y = 1;
			arrUIDATA_Num_6[2].X = 4;
			arrUIDATA_Num_6[2].Y = 1;
			arrUIDATA_Num_6[3].X = 3;
			arrUIDATA_Num_6[3].Y = 1;
			arrUIDATA_Num_6[4].X = 2;
			arrUIDATA_Num_6[4].Y = 2;
			arrUIDATA_Num_6[5].X = 1;
			arrUIDATA_Num_6[5].Y = 3;
			arrUIDATA_Num_6[6].X = 1;
			arrUIDATA_Num_6[6].Y = 4;
			arrUIDATA_Num_6[7].X = 1;
			arrUIDATA_Num_6[7].Y = 5;
			arrUIDATA_Num_6[8].X = 1;
			arrUIDATA_Num_6[8].Y = 6;
			arrUIDATA_Num_6[9].X = 1;
			arrUIDATA_Num_6[9].Y = 7;
			arrUIDATA_Num_6[10].X = 1;
			arrUIDATA_Num_6[10].Y = 8;
			arrUIDATA_Num_6[11].X = 1;
			arrUIDATA_Num_6[11].Y = 9;
			arrUIDATA_Num_6[12].X = 1;
			arrUIDATA_Num_6[12].Y = 10;
			arrUIDATA_Num_6[13].X = 1;
			arrUIDATA_Num_6[13].Y = 11;
			arrUIDATA_Num_6[14].X = 1;
			arrUIDATA_Num_6[14].Y = 12;
			arrUIDATA_Num_6[15].X = 2;
			arrUIDATA_Num_6[15].Y = 13;
			arrUIDATA_Num_6[16].X = 3;
			arrUIDATA_Num_6[16].Y = 14;
			arrUIDATA_Num_6[17].X = 4;
			arrUIDATA_Num_6[17].Y = 14;
			arrUIDATA_Num_6[18].X = 5;
			arrUIDATA_Num_6[18].Y = 14;
			arrUIDATA_Num_6[19].X = 6;
			arrUIDATA_Num_6[19].Y = 14;
			arrUIDATA_Num_6[20].X = 7;
			arrUIDATA_Num_6[20].Y = 13;
			arrUIDATA_Num_6[21].X = 8;
			arrUIDATA_Num_6[21].Y = 12;
			arrUIDATA_Num_6[22].X = 8;
			arrUIDATA_Num_6[22].Y = 11;
			arrUIDATA_Num_6[23].X = 8;
			arrUIDATA_Num_6[23].Y = 10;
			arrUIDATA_Num_6[24].X = 8;
			arrUIDATA_Num_6[24].Y = 9;
			arrUIDATA_Num_6[25].X = 7;
			arrUIDATA_Num_6[25].Y = 8;
			arrUIDATA_Num_6[26].X = 6;
			arrUIDATA_Num_6[26].Y = 7;
			arrUIDATA_Num_6[27].X = 5;
			arrUIDATA_Num_6[27].Y = 7;
			arrUIDATA_Num_6[28].X = 4;
			arrUIDATA_Num_6[28].Y = 7;
			arrUIDATA_Num_6[29].X = 3;
			arrUIDATA_Num_6[29].Y = 7;
			arrUIDATA_Num_6[30].X = 2;
			arrUIDATA_Num_6[30].Y = 8;
		}

		//UI_7
		{
			arrUIDATA_Num_7[0].X = 1;
			arrUIDATA_Num_7[0].Y = 1;
			arrUIDATA_Num_7[1].X = 2;
			arrUIDATA_Num_7[1].Y = 1;
			arrUIDATA_Num_7[2].X = 3;
			arrUIDATA_Num_7[2].Y = 1;
			arrUIDATA_Num_7[3].X = 4;
			arrUIDATA_Num_7[3].Y = 1;
			arrUIDATA_Num_7[4].X = 5;
			arrUIDATA_Num_7[4].Y = 1;
			arrUIDATA_Num_7[5].X = 6;
			arrUIDATA_Num_7[5].Y = 1;
			arrUIDATA_Num_7[6].X = 7;
			arrUIDATA_Num_7[6].Y = 1;
			arrUIDATA_Num_7[7].X = 8;
			arrUIDATA_Num_7[7].Y = 1;
			arrUIDATA_Num_7[8].X = 8;
			arrUIDATA_Num_7[8].Y = 2;
			arrUIDATA_Num_7[9].X = 8;
			arrUIDATA_Num_7[9].Y = 3;
			arrUIDATA_Num_7[10].X = 7;
			arrUIDATA_Num_7[10].Y = 4;
			arrUIDATA_Num_7[11].X = 7;
			arrUIDATA_Num_7[11].Y = 5;
			arrUIDATA_Num_7[12].X = 6;
			arrUIDATA_Num_7[12].Y = 6;
			arrUIDATA_Num_7[13].X = 6;
			arrUIDATA_Num_7[13].Y = 7;
			arrUIDATA_Num_7[14].X = 5;
			arrUIDATA_Num_7[14].Y = 8;
			arrUIDATA_Num_7[15].X = 5;
			arrUIDATA_Num_7[15].Y = 9;
			arrUIDATA_Num_7[16].X = 4;
			arrUIDATA_Num_7[16].Y = 10;
			arrUIDATA_Num_7[17].X = 4;
			arrUIDATA_Num_7[17].Y = 11;
			arrUIDATA_Num_7[18].X = 3;
			arrUIDATA_Num_7[18].Y = 12;
			arrUIDATA_Num_7[19].X = 3;
			arrUIDATA_Num_7[19].Y = 13;
			arrUIDATA_Num_7[20].X = 2;
			arrUIDATA_Num_7[20].Y = 14;

		}

		//UI_8
		{
			arrUIDATA_Num_8[0].X = 4;
			arrUIDATA_Num_8[0].Y = 1;
			arrUIDATA_Num_8[1].X = 3;
			arrUIDATA_Num_8[1].Y = 1;
			arrUIDATA_Num_8[2].X = 2;
			arrUIDATA_Num_8[2].Y = 2;
			arrUIDATA_Num_8[3].X = 1;
			arrUIDATA_Num_8[3].Y = 3;
			arrUIDATA_Num_8[4].X = 1;
			arrUIDATA_Num_8[4].Y = 4;
			arrUIDATA_Num_8[5].X = 1;
			arrUIDATA_Num_8[5].Y = 5;
			arrUIDATA_Num_8[6].X = 2;
			arrUIDATA_Num_8[6].Y = 6;
			arrUIDATA_Num_8[7].X = 3;
			arrUIDATA_Num_8[7].Y = 7;
			arrUIDATA_Num_8[8].X = 4;
			arrUIDATA_Num_8[8].Y = 7;
			arrUIDATA_Num_8[9].X = 5;
			arrUIDATA_Num_8[9].Y = 7;
			arrUIDATA_Num_8[10].X = 6;
			arrUIDATA_Num_8[10].Y = 7;
			arrUIDATA_Num_8[11].X = 7;
			arrUIDATA_Num_8[11].Y = 8;
			arrUIDATA_Num_8[12].X = 8;
			arrUIDATA_Num_8[12].Y = 9;
			arrUIDATA_Num_8[13].X = 8;
			arrUIDATA_Num_8[13].Y = 10;
			arrUIDATA_Num_8[14].X = 8;
			arrUIDATA_Num_8[14].Y = 11;
			arrUIDATA_Num_8[15].X = 8;
			arrUIDATA_Num_8[15].Y = 12;
			arrUIDATA_Num_8[16].X = 7;
			arrUIDATA_Num_8[16].Y = 13;
			arrUIDATA_Num_8[17].X = 6;
			arrUIDATA_Num_8[17].Y = 14;
			arrUIDATA_Num_8[18].X = 5;
			arrUIDATA_Num_8[18].Y = 14;
			arrUIDATA_Num_8[19].X = 4;
			arrUIDATA_Num_8[19].Y = 14;
			arrUIDATA_Num_8[20].X = 3;
			arrUIDATA_Num_8[20].Y = 14;
			arrUIDATA_Num_8[21].X = 2;
			arrUIDATA_Num_8[21].Y = 13;
			arrUIDATA_Num_8[22].X = 1;
			arrUIDATA_Num_8[22].Y = 12;
			arrUIDATA_Num_8[23].X = 1;
			arrUIDATA_Num_8[23].Y = 11;
			arrUIDATA_Num_8[24].X = 1;
			arrUIDATA_Num_8[24].Y = 10;
			arrUIDATA_Num_8[25].X = 1;
			arrUIDATA_Num_8[25].Y = 9;
			arrUIDATA_Num_8[26].X = 2;
			arrUIDATA_Num_8[26].Y = 8;
			arrUIDATA_Num_8[27].X = 7;
			arrUIDATA_Num_8[27].Y = 6;
			arrUIDATA_Num_8[28].X = 8;
			arrUIDATA_Num_8[28].Y = 5;
			arrUIDATA_Num_8[29].X = 8;
			arrUIDATA_Num_8[29].Y = 4;
			arrUIDATA_Num_8[30].X = 8;
			arrUIDATA_Num_8[30].Y = 3;
			arrUIDATA_Num_8[31].X = 7;
			arrUIDATA_Num_8[31].Y = 2;
			arrUIDATA_Num_8[32].X = 6;
			arrUIDATA_Num_8[32].Y = 1;
			arrUIDATA_Num_8[33].X = 5;
			arrUIDATA_Num_8[33].Y = 1;
		}

		//UI_9
		{
			arrUIDATA_Num_9[0].X = 7;
			arrUIDATA_Num_9[0].Y = 7;
			arrUIDATA_Num_9[1].X = 6;
			arrUIDATA_Num_9[1].Y = 8;
			arrUIDATA_Num_9[2].X = 5;
			arrUIDATA_Num_9[2].Y = 8;
			arrUIDATA_Num_9[3].X = 4;
			arrUIDATA_Num_9[3].Y = 8;
			arrUIDATA_Num_9[4].X = 3;
			arrUIDATA_Num_9[4].Y = 8;
			arrUIDATA_Num_9[5].X = 2;
			arrUIDATA_Num_9[5].Y = 7;
			arrUIDATA_Num_9[6].X = 1;
			arrUIDATA_Num_9[6].Y = 6;
			arrUIDATA_Num_9[7].X = 1;
			arrUIDATA_Num_9[7].Y = 5;
			arrUIDATA_Num_9[8].X = 1;
			arrUIDATA_Num_9[8].Y = 4;
			arrUIDATA_Num_9[9].X = 1;
			arrUIDATA_Num_9[9].Y = 3;
			arrUIDATA_Num_9[10].X = 2;
			arrUIDATA_Num_9[10].Y = 2;
			arrUIDATA_Num_9[11].X = 3;
			arrUIDATA_Num_9[11].Y = 1;
			arrUIDATA_Num_9[12].X = 4;
			arrUIDATA_Num_9[12].Y = 1;
			arrUIDATA_Num_9[13].X = 5;
			arrUIDATA_Num_9[13].Y = 1;
			arrUIDATA_Num_9[14].X = 6;
			arrUIDATA_Num_9[14].Y = 1;
			arrUIDATA_Num_9[15].X = 7;
			arrUIDATA_Num_9[15].Y = 2;
			arrUIDATA_Num_9[16].X = 8;
			arrUIDATA_Num_9[16].Y = 3;
			arrUIDATA_Num_9[17].X = 8;
			arrUIDATA_Num_9[17].Y = 4;
			arrUIDATA_Num_9[18].X = 8;
			arrUIDATA_Num_9[18].Y = 5;
			arrUIDATA_Num_9[19].X = 8;
			arrUIDATA_Num_9[19].Y = 6;
			arrUIDATA_Num_9[20].X = 8;
			arrUIDATA_Num_9[20].Y = 7;
			arrUIDATA_Num_9[21].X = 8;
			arrUIDATA_Num_9[21].Y = 8;
			arrUIDATA_Num_9[22].X = 8;
			arrUIDATA_Num_9[22].Y = 9;
			arrUIDATA_Num_9[23].X = 8;
			arrUIDATA_Num_9[23].Y = 10;
			arrUIDATA_Num_9[24].X = 8;
			arrUIDATA_Num_9[24].Y = 11;
			arrUIDATA_Num_9[25].X = 8;
			arrUIDATA_Num_9[25].Y = 12;
			arrUIDATA_Num_9[26].X = 7;
			arrUIDATA_Num_9[26].Y = 13;
			arrUIDATA_Num_9[27].X = 6;
			arrUIDATA_Num_9[27].Y = 14;
			arrUIDATA_Num_9[28].X = 5;
			arrUIDATA_Num_9[28].Y = 14;
			arrUIDATA_Num_9[29].X = 4;
			arrUIDATA_Num_9[29].Y = 14;
			arrUIDATA_Num_9[30].X = 3;
			arrUIDATA_Num_9[30].Y = 14;
		}

		//UI_P
		{
			arrUIDATA_Num_P[0].X = 3;
			arrUIDATA_Num_P[0].Y = 7;
			arrUIDATA_Num_P[1].X = 4;
			arrUIDATA_Num_P[1].Y = 7;
			arrUIDATA_Num_P[2].X = 5;
			arrUIDATA_Num_P[2].Y = 7;
			arrUIDATA_Num_P[3].X = 6;
			arrUIDATA_Num_P[3].Y = 7;
			arrUIDATA_Num_P[4].X = 7;
			arrUIDATA_Num_P[4].Y = 7;
			arrUIDATA_Num_P[5].X = 5;
			arrUIDATA_Num_P[5].Y = 5;
			arrUIDATA_Num_P[6].X = 5;
			arrUIDATA_Num_P[6].Y = 6;
			arrUIDATA_Num_P[7].X = 5;
			arrUIDATA_Num_P[7].Y = 8;
			arrUIDATA_Num_P[8].X = 5;
			arrUIDATA_Num_P[8].Y = 9;
		}
	}

	arrUIData[UI_0_INDEX] = arrUIDATA_Num_0;
	arrUIData[UI_1_INDEX] = arrUIDATA_Num_1;
	arrUIData[UI_2_INDEX] = arrUIDATA_Num_2;
	arrUIData[UI_3_INDEX] = arrUIDATA_Num_3;
	arrUIData[UI_4_INDEX] = arrUIDATA_Num_4;
	arrUIData[UI_5_INDEX] = arrUIDATA_Num_5;
	arrUIData[UI_6_INDEX] = arrUIDATA_Num_6;
	arrUIData[UI_7_INDEX] = arrUIDATA_Num_7;
	arrUIData[UI_8_INDEX] = arrUIDATA_Num_8;
	arrUIData[UI_9_INDEX] = arrUIDATA_Num_9;
	arrUIData[UI_P_INDEX] = arrUIDATA_Num_P;
	arrUIData[UI_LVUP_INDEX] = arrUIData_LvUp;

	arrUIDataSize[UI_0_INDEX] = UI_0_CNT;
	arrUIDataSize[UI_1_INDEX] = UI_1_CNT;
	arrUIDataSize[UI_2_INDEX] = UI_2_CNT;
	arrUIDataSize[UI_3_INDEX] = UI_3_CNT;
	arrUIDataSize[UI_4_INDEX] = UI_4_CNT;
	arrUIDataSize[UI_5_INDEX] = UI_5_CNT;
	arrUIDataSize[UI_6_INDEX] = UI_6_CNT;
	arrUIDataSize[UI_7_INDEX] = UI_7_CNT;
	arrUIDataSize[UI_8_INDEX] = UI_8_CNT;
	arrUIDataSize[UI_9_INDEX] = UI_9_CNT;
	arrUIDataSize[UI_P_INDEX] = UI_P_CNT;
	arrUIDataSize[UI_LVUP_INDEX] = UI_LVUP_CNT;
}

void DrawMino(int nX, int nY, int MINO_TYPE, int MINO_ROTATE)
{
	if ((MINO_TYPE >= MINO_TYPE_MAX) || (MINO_ROTATE >= MINO_ROTATE_MAX))
	{
		return;
	}

	SetTextColor(MINOBGCOLOR, arrMinoColor[MINO_TYPE]);
	for (int i = 0; i < MINO_BLOCK_CNT; i++)
	{
		GotoxyDraw
		(OFFSET_GAME_X + nX + arrMinoData[MINO_TYPE][MINO_ROTATE][i].X + 1, 
			OFFSET_GAME_Y + nY + arrMinoData[MINO_TYPE][MINO_ROTATE][i].Y + 1,
			DRAW_CMINO);
	}
}

void DrawCMino(void)
{
	if ((nCMinoType >= MINO_TYPE_MAX) || (nCMinoRotate >= MINO_ROTATE_MAX))
	{
		return;
	}

	SetTextColor(GAMEMAPCOLOR, arrMinoColor[nCMinoType]);
	for (int i = 0; i < MINO_BLOCK_CNT; i++)
	{
		GotoxyDraw
		(OFFSET_GAME_X + CMinoPos.X + arrMinoData[nCMinoType][nCMinoRotate][i].X + 1,
			OFFSET_GAME_Y + CMinoPos.Y + arrMinoData[nCMinoType][nCMinoRotate][i].Y + 1,
			DRAW_CMINO);
	}
}

void DrawSMino(int nX, int nY, int MINO_TYPE, int MINO_ROTATE)
{
	if ((MINO_TYPE >= MINO_TYPE_MAX) || (MINO_ROTATE >= MINO_ROTATE_MAX))
	{
		return;
	}
	SetTextColor(MINOBGCOLOR, arrMinoColor[MINO_TYPE]);
	for (int i = 0; i < MINO_BLOCK_CNT; i++)
	{
		GotoxyDraw
		(OFFSET_GAME_X + nX + arrMinoData[MINO_TYPE][MINO_ROTATE][i].X + 1,
			OFFSET_GAME_Y + nY + arrMinoData[MINO_TYPE][MINO_ROTATE][i].Y + 1,
			DRAW_SMINO);
	}
}

void DeleteMinoArea(int nX, int nY, int MINO_TYPE, int MINO_ROTATE)
{
	if ((MINO_TYPE >= MINO_TYPE_MAX) || (MINO_ROTATE >= MINO_ROTATE_MAX))
	{
		return;
	}
	SetTextColor(GAMEMAPCOLOR, GAMEMAPCOLOR);
	for (int i = 0; i < MINO_BLOCK_CNT; i++)
	{
		GotoxyDraw
		(OFFSET_GAME_X + nX + arrMinoData[MINO_TYPE][MINO_ROTATE][i].X + 1,
			OFFSET_GAME_Y + nY + arrMinoData[MINO_TYPE][MINO_ROTATE][i].Y + 1,
			DRAW_EMPTY);
	}
}

void DeleteCMinoArea(void)
{
	DeleteMinoArea(CMinoPos.X, CMinoPos.Y, nCMinoType, nCMinoRotate);
}

void Title(void)
{
	SetTextColor(COLOR_BLACK, COLOR_BLACK);
	system("cls");
	int nCnt = 0;  
	SetTextColor(COLOR_BLACK, COLOR_WHITE);
	GotoxyDraw(OFFSET_TITLE_X, OFFSET_TITLE_Y + 0, "■■■■■■■■■■■■■■■");
	GotoxyDraw(OFFSET_TITLE_X, OFFSET_TITLE_Y + 1, "■                          ■");
	GotoxyDraw(OFFSET_TITLE_X, OFFSET_TITLE_Y + 2, "■                          ■");
	GotoxyDraw(OFFSET_TITLE_X, OFFSET_TITLE_Y + 3, "■                          ■");
	GotoxyDraw(OFFSET_TITLE_X, OFFSET_TITLE_Y + 4, "■■■■■■■■■■■■■■■");
	Sleep(50);
	SetTextColor(COLOR_BLACK, COLOR_GREEN);
	GotoxyDraw(OFFSET_TITLE_X + 5, OFFSET_TITLE_Y + 2, "T"); 
	Sleep(50);
	GotoxyDraw(OFFSET_TITLE_X + 5, OFFSET_TITLE_Y + 2, "T E");
	Sleep(50);
	GotoxyDraw(OFFSET_TITLE_X + 5, OFFSET_TITLE_Y + 2, "T E T");
	Sleep(50);
	GotoxyDraw(OFFSET_TITLE_X + 5, OFFSET_TITLE_Y + 2, "T E T R");
	Sleep(50);
	GotoxyDraw(OFFSET_TITLE_X + 5, OFFSET_TITLE_Y + 2, "T E T R I");
	Sleep(50);
	GotoxyDraw(OFFSET_TITLE_X + 5, OFFSET_TITLE_Y + 2, "T E T R I S");
	Sleep(50);
	SetTextColor(COLOR_BLACK, COLOR_YELLOW);
	GotoxyDraw(OFFSET_TITLE_X, OFFSET_TITLE_Y + 9, "           △   : Hard Drop");
	GotoxyDraw(OFFSET_TITLE_X, OFFSET_TITLE_Y + 10, "         ◁  ▷ : Left / Right");
	GotoxyDraw(OFFSET_TITLE_X, OFFSET_TITLE_Y + 11, "           ▽   : Soft Drop");
	GotoxyDraw(OFFSET_TITLE_X, OFFSET_TITLE_Y + 12, "          Z, X  : Rotate"); 
	GotoxyDraw(OFFSET_TITLE_X, OFFSET_TITLE_Y + 13, "            P   : Pause");
	GotoxyDraw(OFFSET_TITLE_X - 3, OFFSET_TITLE_Y + 14, " (메인 화면에서) ESC  : Exit");


	GotoxyDraw(OFFSET_TITLE_X, OFFSET_TITLE_Y + 7, "★ Please Enter Any Key to Start ★");
	while(TRUE)
	{ 
		if (_kbhit())
		{
			if(_getch() == ESC)
			{
				Exit();
			}
			break;
		}
		if ((nCnt % 25) == 0)
		{
			GotoxyDraw(OFFSET_TITLE_X, OFFSET_TITLE_Y + 7, "                                                                 ");
		}
		if (nCnt % 50 == 0) 
		{ 
			GotoxyDraw(OFFSET_TITLE_X, OFFSET_TITLE_Y + 7, "★ Please Enter Any Key to Start ★");
			nCnt = 0;
		}     

		Sleep(10); // 00.1초 딜레이  
		nCnt++;
	}

	while (_kbhit())
	{
		_getch();//버퍼에 기록된 키값을 버림 
	}
}
void Game(void)
{
	system("cls");
	isGameOver = FALSE;
	int MinoDownT = 0;
	int ShowLvUpCnt = 0;
	int ShowLvUpCnt2 = 0;
	ShowLvUp = FALSE;
	nNextMinoType = ERR;
	nLevelCnt = LEVELCNT;
	nLevel = 1;
	nGameSpeed = DEFAULTSPEED;
	nScore = 0;

	InitHead();
	GetBestScore();
	ResetGameMap();
	DeleteUIArea();
	DrawUIFrame();
	UpdateUI(nScore);
	DrawWall();
	UpdateGameMapAll();
	DrawNextMinoInfoWall();
	DrawEndLine();
	
	SetNewMinoData();
	UpdateNextMinoInfo();
	DrawShadowMino();
	DrawCMino();

	ShowKeyExplain();
	SubUIUpdate();


	PlaySound(TEXT("BGM.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	while (TRUE)
	{
		//ShowDebugData();

		if (CheckGameOver())
		{
			isGameOver = TRUE;
			break;
		}

		if (nLevel < LEVELMAX && nLevelCnt <= 0)
		{
			nLevel++;
			nGameSpeed -= SPEEDUNIT;

			nLevelCnt += LEVELCNT;
			ShowLvUp = TRUE;
			ShowLvUpCnt2 = UI_LVUP_CNT - 1;
			DeleteUIArea();
			SubUIUpdate();
		}
		if (ShowLvUp)
		{
			if (ShowLvUpCnt < UI_LVUP_CNT)
			{
				int color = rand() % MINO_TYPE_MAX;
				SetTextColor(arrMinoColor[color], arrMinoColor[color]);
				GotoxyDraw(UIPOS_X + arrUIData[UI_LVUP_INDEX][ShowLvUpCnt].X, UIPOS_Y + arrUIData[UI_LVUP_INDEX][ShowLvUpCnt].Y, DRAW_UI);
				ShowLvUpCnt++;
			}
			else if (ShowLvUpCnt < (UI_LVUP_CNT + SHOWLVUP_TIME))
			{
				ShowLvUpCnt++;
				if ((ShowLvUpCnt % 4) <= 1)
				{
					DrawUI_ShowLVUP();
				}
			}
			else if (ShowLvUpCnt2 > 0)
			{
				SetTextColor(UIAREA_COLOR, UIAREA_COLOR);
				GotoxyDraw(UIPOS_X + arrUIData[UI_LVUP_INDEX][ShowLvUpCnt2].X, UIPOS_Y + arrUIData[UI_LVUP_INDEX][ShowLvUpCnt2].Y, DRAW_EMPTY);
				ShowLvUpCnt2--;
			}
			else
			{
				ShowLvUp = FALSE;
				ShowLvUpCnt = 0;
				ShowLvUpCnt2 = UI_LVUP_CNT - 1;
				UpdateUI(nScore);
			}
		}

		CheckKey();

		if (MinoDownT >= nGameSpeed) //미노 한칸씩 내려오는 조건
		{
			if (CheckCol(CMinoPos.X, CMinoPos.Y + 1, nCMinoType, nCMinoRotate)) //충돌체크
			{
				ChangeCtoS(); //미노를 고정된 미노로 바꾼다
				CheckLine();
				//DrawMapData();
				if (CheckGameOver())
				{
					isGameOver = TRUE;
					break;
				}
				SetNewMinoData();
				UpdateNextMinoInfo();
				DrawShadowMino();
				DrawCMino();	
			}
			else
			{
				DeleteCMinoArea();
				CMinoPos.Y++;
				DrawEndLine();
				DrawCMino();
			}
			MinoDownT = 0;
		}

		MinoDownT += FRAME_UNIT;
		Sleep(FRAME_UNIT);
	}


	DeleteAllNode();
	if (isGameOver)
	{
		if (nScore > nBestScore)
		{
			SaveBestScore();
		}
		PlaySound(NULL, NULL, NULL);
		ShowEnd();	
	}
}

void DrawWall(void)
{
	SetTextColor(COLOR_BLACK, COLOR_WHITE);
	for (int i = OFFSET_GAME_X; i < (OFFSET_GAME_X + GAMEAREA_X + 1); i++)
	{
		GotoxyDraw(i, OFFSET_GAME_Y, DRAW_WALL);
		GotoxyDraw(i, OFFSET_GAME_Y + GAMEAREA_Y + 1, DRAW_WALL);
	}
	for (int i = OFFSET_GAME_Y; i < (OFFSET_GAME_Y + GAMEAREA_Y + 2); i++)
	{
		GotoxyDraw(OFFSET_GAME_X, i, DRAW_WALL);
		GotoxyDraw(OFFSET_GAME_X + GAMEAREA_X + 1, i, DRAW_WALL);
	}
}

void DrawEndLine(void)
{
	SetTextColor(GAMEMAPCOLOR, ENDLINECOLOR);
	for (int i = OFFSET_GAME_X; i < (OFFSET_GAME_X + GAMEAREA_X ); i++)
	{
		GotoxyDraw(i + 1, OFFSET_GAME_Y + ENDLINE, DRAW_ENDLINE);
	}
}

BOOL CheckCol(int MinoPosX, int MinoPosY, int MINO_TYPE, int MINO_ROTATE)
{
	for (int i = 0; i < MINO_BLOCK_CNT; i++)
	{
		if ((arrGameMapData[MinoPosX + arrMinoData[MINO_TYPE][MINO_ROTATE][i].X]
			[MinoPosY + arrMinoData[MINO_TYPE][MINO_ROTATE][i].Y] != MINO_EMPTY) || //고정된 미노와 충돌
			MinoPosX + arrMinoData[MINO_TYPE][MINO_ROTATE][i].X < 0 || //여기부터는 벽돌과의 충돌 (게임 영역 벗어났는지 검사해서 판정함)
			MinoPosY + arrMinoData[MINO_TYPE][MINO_ROTATE][i].Y < 0 ||
			MinoPosX + arrMinoData[MINO_TYPE][MINO_ROTATE][i].X >= GAMEAREA_X ||
			MinoPosY + arrMinoData[MINO_TYPE][MINO_ROTATE][i].Y >= GAMEAREA_Y)
		{
			return TRUE;
		}
	}
	return FALSE;
}

void UpdateGameMapAll(void)
{
	for (int i = 0; i < GAMEAREA_X; i++)
	{
		for (int j = 0; j < GAMEAREA_Y; j++)
		{
			if (arrGameMapData[i][j] == MINO_EMPTY)
			{
				SetTextColor(GAMEMAPCOLOR, GAMEMAPCOLOR);
				GotoxyDraw(OFFSET_GAME_X + i + 1, OFFSET_GAME_Y + j + 1, DRAW_EMPTY);
			}
			else
			{
				SetTextColor(GAMEMAPCOLOR, arrMinoColor[arrGameMapData[i][j]]);
				GotoxyDraw(OFFSET_GAME_X + i + 1, OFFSET_GAME_Y + j + 1, DRAW_SMINO);
			}
		}
	}
}

void ChangeCtoS(void)
{
	for (int i = 0; i < MINO_BLOCK_CNT; i++)
	{
		arrGameMapData[CMinoPos.X + arrMinoData[nCMinoType][nCMinoRotate][i].X][CMinoPos.Y + arrMinoData[nCMinoType][nCMinoRotate][i].Y]
			= nCMinoType;
	}
	DrawSMino(CMinoPos.X, CMinoPos.Y, nCMinoType, nCMinoRotate);
}

BOOL CheckGameOver(void)
{
	for (int i = 0; i < GAMEAREA_X; i++)
	{
		if (arrGameMapData[i][ENDLINE - 1] != MINO_EMPTY)
		{
			return TRUE;
		}
	}
	return FALSE;
}

void GameOver(void)
{
	system("cls");
	Title();
}

void ResetGameMap(void)
{
	for (int i = 0; i < GAMEAREA_X; i++)
	{
		for (int j = 0; j < GAMEAREA_Y; j++)
		{
			arrGameMapData[i][j] = MINO_EMPTY;
		}
	}
}

void SetNewMinoData(void)
{
	if (nNextMinoType == ERR)
	{
		for (int i = 0; i < MINO_TYPE_MAX; i++)
		{
			InsertNode(i);
		}
		nMinoBagCnt = MINO_TYPE_MAX;
		nCMinoType = GetDataFromNode(rand() % nMinoBagCnt);
		nMinoBagCnt--;
	}
	else
	{
		nCMinoType = nNextMinoType;
	}
	if (!nMinoBagCnt)
	{
		for (int i = 0; i < MINO_TYPE_MAX; i++)
		{
			InsertNode(i);
		}
		nMinoBagCnt = MINO_TYPE_MAX;
	}
	nNextMinoType = GetDataFromNode(rand() % nMinoBagCnt);
	nMinoBagCnt--;
	
	nCMinoRotate = 0;
	CMinoPos.X = CRATEMINO_X;
	CMinoPos.Y = 0;
}

void DrawNextMinoInfoWall(void)
{
	SetTextColor(COLOR_BLACK, COLOR_WHITE);
	for (int i = OFFSET_GAME_X + GAMEAREA_X + 2; i < OFFSET_GAME_X + GAMEAREA_X + MINO_SIZE + 3; i++)
	{
		GotoxyDraw(i, OFFSET_GAME_Y + OFFSET_NEXTMINO_Y, DRAW_WALL);
		GotoxyDraw(i, OFFSET_GAME_Y + OFFSET_NEXTMINO_Y + MINO_SIZE + 1, DRAW_WALL);
	}
	for (int i = OFFSET_GAME_Y + OFFSET_NEXTMINO_Y + 1; i < OFFSET_GAME_Y + OFFSET_NEXTMINO_Y + MINO_SIZE + 1; i++)
	{
		GotoxyDraw(OFFSET_GAME_X + GAMEAREA_X + MINO_SIZE + 2, i, DRAW_WALL);
	}
	GotoxyDraw(OFFSET_GAME_X + GAMEAREA_X + 2, OFFSET_GAME_Y + OFFSET_NEXTMINO_Y - 1, "   NEXT");
}
void UpdateNextMinoInfo(void)
{
	SetTextColor(GAMEMAPCOLOR, GAMEMAPCOLOR);
	for (int i = 0; i < MINO_SIZE; i++)
	{
		GotoxyDraw
		(OFFSET_GAME_X + GAMEAREA_X + 2 ,
			OFFSET_GAME_Y + OFFSET_NEXTMINO_Y +  i + 1,
			DRAW_EMPTY_BLOCKSIZE);
	}
	SetTextColor(GAMEMAPCOLOR, arrMinoColor[nNextMinoType]);
	for (int i = 0; i < MINO_BLOCK_CNT; i++)
	{
		GotoxyDraw
		(OFFSET_GAME_X + GAMEAREA_X + arrMinoData[nNextMinoType][0][i].X + 2,
			OFFSET_GAME_Y + OFFSET_NEXTMINO_Y + arrMinoData[nNextMinoType][0][i].Y + 1,
			DRAW_SMINO);
	}
}
void CheckKey(void)
{
	int nKey = 0;
	int isHardDrop = FALSE;
	if (_kbhit())
	{
		nKey = _getch();
		if (nKey == KEY_ARROW) 
		{
			changePos.X = 0;
			changePos.Y = 0;
			nKey = _getch();
			switch (nKey)
			{
			case UP:
			{
				while (!CheckCol(CMinoPos.X + changePos.X, CMinoPos.Y + changePos.Y, nCMinoType, nCMinoRotate))
				{
					changePos.Y++;
				}
				changePos.Y--;
				isHardDrop = TRUE;
				break;
			}
			case DOWN:
			{
				changePos.Y++;
				break;
			}
			case LEFT:
			{
				changePos.X--;
				break;
			}
			case RIGHT:
			{	
				changePos.X++;
				break;
			}
			default:
			{
				break;
			}
			}
			
			if (!CheckCol(CMinoPos.X + changePos.X, CMinoPos.Y + changePos.Y, nCMinoType, nCMinoRotate))
			{
				DeleteCMinoArea();
				DeleteShadowMino();
				CMinoPos.X += changePos.X;
				CMinoPos.Y += changePos.Y;
				if (isHardDrop)
				{
					ChangeCtoS();
					CheckLine();
					if (CheckGameOver())
					{
						isGameOver = TRUE;
						return;
					}
					SetNewMinoData();
					UpdateNextMinoInfo();

				}
				DrawEndLine();
				DrawShadowMino();
				DrawCMino();
			}
			
		}
		else if (nKey == X_S ||
			nKey == X_B ||
			nKey == Z_S ||
			nKey == Z_B )
		{
			nChangeRotate = 0;
			switch (nKey)
			{
			case X_S:
			case X_B:
			{
				nChangeRotate = (nCMinoRotate + 1) % MINO_ROTATE_MAX;
				break;
			}
			case Z_S:
			case Z_B:
			{
				nChangeRotate = nCMinoRotate - 1;
				if (nChangeRotate < 0)
				{
					nChangeRotate = MINO_ROTATE_MAX - 1;
				}
				break;
			}
			default:
			{
				break;
			}
			}
			if (!CheckCol(CMinoPos.X , CMinoPos.Y , nCMinoType, nChangeRotate))
			{
				DeleteCMinoArea();
				DeleteShadowMino();
				nCMinoRotate = nChangeRotate;
				DrawEndLine();
				DrawShadowMino();
				DrawCMino();
			}
		}
		else if (nKey == P_S ||
				  nKey == P_B)
		{
			Pause();
		}
		
	}
}

void CheckLine(void)
{
	int isLineFull = FALSE;
	int nBlockCnt = 0;
	int nDeleteLine = 0;
	for (int i = 0; i < GAMEAREA_Y; i++)
	{
		nBlockCnt = 0;
		for (int j = 0; j < GAMEAREA_X; j++)
		{
			if (arrGameMapData[j][i] != MINO_EMPTY)
			{
				nBlockCnt++;
			}
		}
		if (nBlockCnt >= GAMEAREA_X)
		{
			nDeleteLine++;
			for (int y = i; y > ENDLINE; y--)
			{
				for (int x = 0; x < GAMEAREA_X; x++)
				{
					arrGameMapData[x][y] = arrGameMapData[x][y - 1];
					if (arrGameMapData[x][y] == MINO_EMPTY)
					{
						SetTextColor(GAMEMAPCOLOR, GAMEMAPCOLOR);
						GotoxyDraw(OFFSET_GAME_X + x + 1, OFFSET_GAME_Y + y + 1, DRAW_EMPTY);
					}
					else 
					{
						SetTextColor(MINOBGCOLOR, arrMinoColor[arrGameMapData[x][y]]);
						GotoxyDraw(OFFSET_GAME_X + x + 1, OFFSET_GAME_Y + y + 1, DRAW_SMINO);
					}
				}
			}
			for (int x = 0; x < GAMEAREA_X; x++)
			{
				arrGameMapData[x][ENDLINE] = MINO_EMPTY;
				SetTextColor(GAMEMAPCOLOR, GAMEMAPCOLOR);
				GotoxyDraw(OFFSET_GAME_X + x + 1, OFFSET_GAME_Y + ENDLINE + 1, DRAW_EMPTY);
			}
		}
	}
	if (nDeleteLine > 0)
	{
		nScore += POINTUNIT * nDeleteLine;
		UpdateUI(nScore);
		if (nLevel < LEVELMAX)
		{
			nLevelCnt -= nDeleteLine;
		}
		Beep(260, 150);
	}
}

void DrawMapData(void)
{
	SetTextColor(COLOR_BLACK, COLOR_WHITE);
	for (int x = 0; x < GAMEAREA_X; x++)
	{
		for (int y = 0; y < GAMEAREA_Y; y++)
		{
			if (arrGameMapData[x][y] == MINO_EMPTY)
			{
				SetTextColor(COLOR_BLACK, COLOR_BLACK);
				GotoxyDraw(OFFSET_GAME_X + GAMEAREA_X + 25 + x, OFFSET_GAME_Y + y + 1, DRAW_EMPTY);
			}
			else 
			{
				SetTextColor(COLOR_BLACK, arrMinoColor[arrGameMapData[x][y]]);
				GotoxyDraw(OFFSET_GAME_X + GAMEAREA_X + 25 + x, OFFSET_GAME_Y + y + 1, DRAW_SMINO);
			}
		}
	}
}

void ShowDebugData(void)
{
	SetTextColor(COLOR_BLACK, COLOR_WHITE);
	Gotoxy(OFFSET_GAME_X + GAMEAREA_X + 8, OFFSET_GAME_Y);
	printf("BEST SCORE : %d     ", nBestScore);

	Gotoxy(OFFSET_GAME_X + GAMEAREA_X + 8, OFFSET_GAME_Y + 1);
	printf("CURRENT SCORE : %d     ", nScore);

	Gotoxy(OFFSET_GAME_X + GAMEAREA_X + 8, OFFSET_GAME_Y + 2);
	printf("CMINO_POS_X : %d ,CMINO_POS_Y : %d     ", CMinoPos.X, CMinoPos.Y);

	Gotoxy(OFFSET_GAME_X + GAMEAREA_X + 8, OFFSET_GAME_Y + 3);
	printf("CMINO_TYPE : %d     ", nCMinoType);

	Gotoxy(OFFSET_GAME_X + GAMEAREA_X + 8, OFFSET_GAME_Y + 4);
	printf("CMINO_ROTATE : %d     ", nCMinoRotate);

	Gotoxy(OFFSET_GAME_X + GAMEAREA_X + 8, OFFSET_GAME_Y + 5);
	printf("MINOBAG_CNT : %d     ", nMinoBagCnt);

	Gotoxy(OFFSET_GAME_X + GAMEAREA_X + 8, OFFSET_GAME_Y + 6);
	printf("LVUP_CNT : %d     ", nLevelCnt);

	Gotoxy(OFFSET_GAME_X + GAMEAREA_X + 8, OFFSET_GAME_Y + 7);
	if (nLevel == LEVELMAX )
	{
		printf("LV : %d (MAX)     ", nLevel);
	}
	else
	{
		printf("LV : %d     ", nLevel);
	}

	Gotoxy(OFFSET_GAME_X + GAMEAREA_X + 8, OFFSET_GAME_Y + 8);
	printf("SPD : %d     ", nGameSpeed);
}

void UpdateGameMapArea(int x1, int y1, int x2, int y2)
{
	for (int x = x1; x <= x2; x++)
	{
		for (int y = y1; y <= y2; y++)
		{
			if (arrGameMapData[x][y] == MINO_EMPTY)
			{
				SetTextColor(GAMEMAPCOLOR, GAMEMAPCOLOR);
				GotoxyDraw(OFFSET_GAME_X + x + 1, OFFSET_GAME_Y + y + 1, DRAW_EMPTY);
			}
			else
			{
				SetTextColor(MINOBGCOLOR, arrMinoColor[arrGameMapData[x][y]]);
				GotoxyDraw(OFFSET_GAME_X + x + 1, OFFSET_GAME_Y + y + 1, DRAW_SMINO);
			}
		}
	}
}

void Pause(void)
{
	
	for (int x = UI_PAUSE_POS_X1; x <= UI_PAUSE_POS_X2; x++)
	{
		for (int y = UI_PAUSE_POS_Y1; y <= UI_PAUSE_POS_Y2; y++)
		{
			if (x == UI_PAUSE_POS_X1 ||
				x == UI_PAUSE_POS_X2 ||
				y == UI_PAUSE_POS_Y1 ||
				y == UI_PAUSE_POS_Y2)
			{
				SetTextColor(PAUSEUICOLOR, PAUSEUI_TEXTCOLOR);
				GotoxyDraw(OFFSET_GAME_X + x + 1, OFFSET_GAME_Y + y + 1, DRAW_PAUSE_UI);
			}
			else
			{
				SetTextColor(PAUSEUICOLOR, PAUSEUICOLOR);
				GotoxyDraw(OFFSET_GAME_X + x + 1, OFFSET_GAME_Y + y + 1, DRAW_EMPTY);
			}
		}
	}
	SetTextColor(PAUSEUICOLOR, PAUSEUI_TEXTCOLOR);
	int strposX = UI_PAUSE_POS_X1 + 2;
	int strposY = ((UI_PAUSE_POS_Y1 + UI_PAUSE_POS_Y2) / 2);
	GotoxyDraw(OFFSET_GAME_X + strposX, OFFSET_GAME_Y + strposY, "일시 정지 중");
	GotoxyDraw(OFFSET_GAME_X + strposX, OFFSET_GAME_Y + strposY + 2, "  아무키나");
	GotoxyDraw(OFFSET_GAME_X + strposX, OFFSET_GAME_Y + strposY + 3, " 입력하세요");

	if (_getch() == KEY_ARROW)
	{
		_getch();
	}
	UpdateGameMapArea(UI_PAUSE_POS_X1, UI_PAUSE_POS_Y1, UI_PAUSE_POS_X2, UI_PAUSE_POS_Y2);
	DrawShadowMino();
	DrawCMino();
}

void DrawShadowMino(void)
{
	SetTextColor(GAMEMAPCOLOR, SHADOWMINO_COLOR);
	nShadowMino_y = 0;
	while (!CheckCol(CMinoPos.X, CMinoPos.Y + nShadowMino_y, nCMinoType, nCMinoRotate))
	{
		nShadowMino_y++;
	}
	nShadowMino_y--;
	nShadowMino_y += CMinoPos.Y;
	for (int i = 0; i < MINO_BLOCK_CNT; i++)
	{
		GotoxyDraw
		(OFFSET_GAME_X + CMinoPos.X + arrMinoData[nCMinoType][nCMinoRotate][i].X + 1,
			OFFSET_GAME_Y + nShadowMino_y + arrMinoData[nCMinoType][nCMinoRotate][i].Y + 1,
			DRAW_SHADOWMINO);
	}
}

void DeleteShadowMino(void)
{
	SetTextColor(GAMEMAPCOLOR, GAMEMAPCOLOR);
	for (int i = 0; i < MINO_BLOCK_CNT; i++)
	{
		GotoxyDraw
		(OFFSET_GAME_X + CMinoPos.X + arrMinoData[nCMinoType][nCMinoRotate][i].X + 1,
			OFFSET_GAME_Y  + nShadowMino_y + arrMinoData[nCMinoType][nCMinoRotate][i].Y + 1,
			DRAW_EMPTY);
	}
}

void InitHead(void)
{
	head = NULL; //헤드가 NULL이면 데이터가 없다는 의미
}
void InsertNode(int nType)
{
	C_NODE* newNode = (C_NODE*)malloc(sizeof(C_NODE));
	newNode->nMinoType = nType;
	if (!head)
	{
		head = newNode;
		head->after = head;
	}
	else
	{
		C_NODE* next = head->after;
		head->after = newNode;
		newNode->after = next;
	}
}
int GetDataFromNode(unsigned int nAfterCnt)
{
	if (!head)
	{
		return ERR;
	}
	int nData = 0;
	if (head->after == head) //데이터가 단 한개
	{
		nData = head->nMinoType;
		free(head);
		head = NULL;
		return nData;
	}
	C_NODE* getNode = head;
	C_NODE* beforeNode = NULL;
	
	for (unsigned int i = 0; i <= nAfterCnt; i++)
	{
		beforeNode = getNode;
		getNode = getNode->after;
	}
	nData = getNode->nMinoType;
	beforeNode->after = getNode->after;
	free(getNode);
	head = beforeNode;
	return nData;
}
void DeleteAllNode(void)
{
	if (!head)
	{
		return;
	}
	C_NODE* findNode = head->after;
	C_NODE* deleteNode = findNode;
	while (findNode != head)
	{
		deleteNode = findNode;
		findNode = findNode->after;

		free(deleteNode);
	}
	free(head);
	head = NULL;
}

void DeleteUIArea(void)
{
	SetTextColor(UIAREA_COLOR, UIAREA_COLOR);
	for (int i = 0; i < UIAREA_Y; i++)
	{
		GotoxyDraw(UIPOS_X, UIPOS_Y + i, DRAW_EMPTY_UILINE);
	}
}

void DrawUIFrame(void)
{
	SetTextColor(UIFRAME_COLOR, UIFRAME_COLOR);
	for (int i = 0; i < UIAREA_Y + 2; i++)
	{
		for (int j = 0; j < UIAREA_X + 2; j++)
		{
			GotoxyDraw(UIPOS_X - 1 + j, UIPOS_Y - 1 + i, DRAW_UIFRAME);
		}
	}
	for (int i = 0; i < GAMEAREA_X + 2; i++)
	{
		GotoxyDraw(UIPOS_X  -  GAMEAREA_X - 3 + i, UIPOS_Y + UIAREA_Y, DRAW_UIFRAME);
	}
}

void UpdateUI(unsigned int point)
{
	if (ShowLvUp)
	{
		return;
	}
	int tmp = point;
	if (tmp >= 999)
	{
		tmp = 999;
	}
	int out1 = tmp % 10;
	tmp /= 10;
	int out10 = tmp % 10;
	tmp /= 10;
	int out100 = tmp % 10;

	DeleteUIArea();
	SetTextColor(UITEXT_COLOR, UITEXT_COLOR);
	for (int i = 0; i < arrUIDataSize[out100]; i++)
	{
		GotoxyDraw(UIPOS_X + arrUIData[out100][i].X + (0 * 10), UIPOS_Y + arrUIData[out100][i].Y, DRAW_UI);
	}
	for (int i = 0; i < arrUIDataSize[out10]; i++)
	{
		GotoxyDraw(UIPOS_X + arrUIData[out10][i].X + (1 * 10), UIPOS_Y + arrUIData[out10][i].Y, DRAW_UI);
	}
	for (int i = 0; i < arrUIDataSize[out1]; i++)
	{
		GotoxyDraw(UIPOS_X + arrUIData[out1][i].X + (2 * 10), UIPOS_Y + arrUIData[out1][i].Y, DRAW_UI);
	}
}

void DrawUI_ShowLVUP(void)
{
	int color = 0;
	for (int i = 0; i < arrUIDataSize[UI_LVUP_INDEX]; i++)
	{
		color = rand() % MINO_TYPE_MAX;
		SetTextColor(arrMinoColor[color], arrMinoColor[color]);
		GotoxyDraw(UIPOS_X + arrUIData[UI_LVUP_INDEX][i].X , UIPOS_Y + arrUIData[UI_LVUP_INDEX][i].Y, DRAW_UI);
	}
}

void GetBestScore(void)
{
	FILE* file = NULL;
	if (!fopen_s(&file, "score", "rt"))
	{
		fscanf_s(file, "%d", &nBestScore);
		fclose(file);
	}
	else
	{
		nBestScore = 0;
	}
}

void SaveBestScore(void)
{
	if (nScore > nBestScore)
	{
		FILE* file = NULL;
		if (!fopen_s(&file, "score", "wt"))
		{
			fprintf(file, "%d", nScore);
			fclose(file);
		}
	}
}

void ShowEnd(void)
{
	SetTextColor(UI_END_FRAME_BG_COLOR, UI_END_FRAME_COLOR);
	for (int i = UI_END_X; i < UI_END_X + UI_END_SIZE_X; i++)
	{
		for (int j = UI_END_Y; j < UI_END_Y + UI_END_SIZE_Y; j++)
		{
			if ((i == UI_END_X) || (i == UI_END_X + UI_END_SIZE_X - 1) ||
				(j == UI_END_Y) || (j == UI_END_Y + UI_END_SIZE_Y - 1))
			{
				GotoxyDraw(i, j, DRAW_UI_END_FRAME);
			}
			else
			{
				GotoxyDraw(i, j, DRAW_EMPTY);
			}
		}
	}
	GotoxyDraw(UI_END_X + 11, UI_END_Y + 2, "G A M E   O V E R");

	if (nScore > nBestScore)
	{
		Gotoxy(UI_END_X + 7, UI_END_Y + 7);
		printf("최고 기록 갱신 !!!");
		Gotoxy(UI_END_X + 7, UI_END_Y + 9);
		printf("이번 점수 : %d", nScore);
	}
	else
	{
		Gotoxy(UI_END_X + 7, UI_END_Y + 7);
		printf("이번 점수 : %d", nScore);
		Gotoxy(UI_END_X + 7, UI_END_Y + 9);
		printf("최고 점수 : %d", nBestScore);
	}

	int nElapse = 0;
	while (!_kbhit())
	{
		
		if (nElapse < 500)
		{
			GotoxyDraw(UI_END_X + 5, UI_END_Y + 15, "아무 키나 누르면 시작화면으로 돌아갑니다..");
		}
		else if (nElapse < 1000)
		{
			GotoxyDraw(UI_END_X + 5, UI_END_Y + 15, DRAW_EMPTY_UILINE_END);
		}
		else
		{
			nElapse = 0;
		}

		nElapse += FRAME_UNIT;
		Sleep(FRAME_UNIT);
	}
	_getch();
}

void Exit(void)
{
	system("cls");
	SetTextColor(EXIT_BG_COLOR, EXIT_COLOR);

	for (int i = UI_END_X; i < UI_END_X + UI_END_SIZE_X; i++)
	{
		for (int j = UI_END_Y; j < UI_END_Y + UI_END_SIZE_Y; j++)
		{
			if ((i == UI_END_X) || (i == UI_END_X + UI_END_SIZE_X - 1) ||
				(j == UI_END_Y) || (j == UI_END_Y + UI_END_SIZE_Y - 1))
			{
				GotoxyDraw(i, j, DRAW_UI_END_FRAME);
			}
			else
			{
				GotoxyDraw(i, j, DRAW_EMPTY);
			}
		}
	}
	GotoxyDraw(UI_END_X + 8, UI_END_Y + 7, "게임 프로그램을 종료합니다.");
	Gotoxy(0, UI_END_Y + UI_END_SIZE_Y + 1);
	exit(0);
}

void SubUIUpdate(void)
{
	SetTextColor(SUBUI_BG_COLOR, SUBUI_COLOR);
	Gotoxy(OFFSET_GAME_X + GAMEAREA_X + 8, OFFSET_GAME_Y + 3);
	printf("BEST SCORE : %d       ", nBestScore);
	Gotoxy(OFFSET_GAME_X + GAMEAREA_X + 8, OFFSET_GAME_Y + 5);
	if (nLevel == LEVELMAX)
	{
		printf("LEVEL : %d(MAX)   ", nLevel);
	}
	else
	{
		printf("LEVEL : %d       ", nLevel);
	}
	Gotoxy(OFFSET_GAME_X + GAMEAREA_X + 8, OFFSET_GAME_Y + 7);
	printf("    ↓↓↓↓↓CURRENT SCORE↓↓↓↓↓");
}

void ShowKeyExplain(void)
{
	SetTextColor(COLOR_BLACK, COLOR_YELLOW);
	GotoxyDraw(OFFSET_GAME_X + GAMEAREA_X + 18, OFFSET_GAME_Y + 1, "   △   : Hard Drop");
	GotoxyDraw(OFFSET_GAME_X + GAMEAREA_X + 18, OFFSET_GAME_Y + 2, " ◁  ▷ : Left / Right");
	GotoxyDraw(OFFSET_GAME_X + GAMEAREA_X + 18, OFFSET_GAME_Y + 3, "   ▽   : Soft Drop");
	GotoxyDraw(OFFSET_GAME_X + GAMEAREA_X + 18, OFFSET_GAME_Y + 4, "  Z, X  : Rotate");
	GotoxyDraw(OFFSET_GAME_X + GAMEAREA_X + 18, OFFSET_GAME_Y + 5, "    P   : Pause");
}