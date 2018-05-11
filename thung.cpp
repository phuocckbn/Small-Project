#include"thung.h"
#include<windows.h>

void drawbaskets(baskets &thung,char map[100][100])
{
	map[thung.td_baskets.x][thung.td_baskets.y]=char(220);
	map[thung.td_baskets.x][thung.td_baskets.y+1]=char(220);
	map[thung.td_baskets.x][thung.td_baskets.y+2]=char(220);
	map[thung.td_baskets.x][thung.td_baskets.y+3]=char(220);
	map[thung.td_baskets.x][thung.td_baskets.y+4]=char(220);
	map[thung.td_baskets.x+1][thung.td_baskets.y+1]=char(220);
	map[thung.td_baskets.x+1][thung.td_baskets.y+2]=char(220);
	map[thung.td_baskets.x+1][thung.td_baskets.y+3]=char(220);
	map[thung.td_baskets.x+2][thung.td_baskets.y+2]=char(220);
}
void logic(baskets &thung)
{
	
	//di chuyen thung
		
			if(GetAsyncKeyState(VK_RIGHT))
			{
				if(thung.td_baskets.y<65)
				{
					thung.td_baskets.y=thung.td_baskets.y+18;
				}else (thung.td_baskets.y=12);		
			}
				
			else if(GetAsyncKeyState(VK_LEFT))
			{
				if(thung.td_baskets.y>15)
				{
					thung.td_baskets.y=thung.td_baskets.y-18;
				}else (thung.td_baskets.y=67);
			}
	
			
}
