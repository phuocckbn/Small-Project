#include"tienich.h"
#include<windows.h>
void gotoxy(int x, int y)
{
    static HANDLE  h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x,y};
    SetConsoleCursorPosition(h,c);
}
void xoamanhinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X=0;
	Position.Y=0;
	SetConsoleCursorPosition(hOut,Position);
}
