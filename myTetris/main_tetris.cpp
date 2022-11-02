#include "tetris.h"

int main(void)
{
	char strWinSize[30] = { 0 };
	sprintf_s(strWinSize, 30, "mode con:cols=%d lines=%d", WINDOWSIZE_X + 20, WINDOWSIZE_Y);
	system(strWinSize);
	srand((unsigned int)time(NULL));
	SetNoCursor();
	InitData();


	while (TRUE)
	{
		Title();
		Game();
	}

	getchar();
	return 0;
}