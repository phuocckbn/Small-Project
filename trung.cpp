#include"trung.h"
#include<cstdlib>

void draweggs(eggs &trung,char map[100][100])
{
	map[trung.td_eggs.x][trung.td_eggs.y]=15;
}
void logictrung(int &diem,baskets &thung,eggs &trung ,int &hp)
{
	if(trung.td_eggs.x<20)
	{
		
		trung.td_eggs.x++;
	}
	else 
	{
		hp--;
		
		xulytrung(trung);
		trung.temp= 10;
		
	}
	//va cham
	if((trung.td_eggs.x==thung.td_baskets.x||trung.td_eggs.x==thung.td_baskets.x+1)&&trung.td_eggs.y>=thung.td_baskets.y&&trung.td_eggs.y<=thung.td_baskets.y+5)
	{
		
		diem++;
		
		xulytrung(trung);
		trung.temp=10;
	}
}
void xulytrung(eggs &trung)
{
	//image_egg.draw_eggs=(char)2;
	
	int b=rand() % 4 + 1;
	switch(b)
	{
		case 1: trung.td_eggs.y=14;break;
		case 2: trung.td_eggs.y=32;break;
		case 3: trung.td_eggs.y=50;break;
		case 4: trung.td_eggs.y=68;break;
		
	} 
	trung.td_eggs.x= 4;
	
}
void khoitaotrung(danhsach &DS,baskets &thung,int &dem1,char map[100][100])
{
	
	
	
		xulytrung(DS.trungs[dem1]);
		//logictrung(diem,thung,DS.trungs[i],hp);
		draweggs(DS.trungs[dem1],map);
		DS.trungs[dem1].temp=0;
	

	
}
