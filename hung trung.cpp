#include <iomanip>
#include <string.h>
#include <iostream>
#include <sstream>
#include<windows.h>
#include<conio.h>
#include<unistd.h>
#include<cstdlib>
#include<ctime>
 
using namespace std;


struct toado
{
	int x;
	int y;
};
//trangthai tt_baskets;

struct baskets
{
    
	toado td_baskets;
	
};
struct eggs
{
	
	toado td_eggs;
	char draw_eggs;
	
};

int doc=20;
int ngang=80;
char map[100][100];
int size_bk=7;
int hp=3;

eggs trung;
toado td_chicken;

void drawchicken(int x,int y)
{
	map[x][y]='<';
	map[x][y+1]='2';
	map[x+1][y]='^';
	map[x+1][y+1]='(';
	map[x+1][y+2]='*';
	map[x+1][y+3]=')';
	map[x+1][y+4]='^';
}
void drawbaskets(baskets &thung)
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
void khoitao(int doc, int ngang)
{
	
	for(int i=0;i<doc;i++)
	{
		for(int j=0;j<ngang;j++)
		{
			if(i==0)
			{
				map[i][j]=(char)220;
			}
			else if(j==0||j==ngang-1)
			{
				map[i][j]=(char)219;
			}else {
				
				map[i][j]=' ';
			}	
		}
	
	
    }
    drawchicken(2,12);
    drawchicken(2,30);
    drawchicken(2,48);
    drawchicken(2,66);
    
	/*for(int i=0;i<3;i++)//khoi tao cai thung
	{
		for(int j=0;j<size_bk;j++)
		{
			//if(j<=size_bk-i-1&&j>=i)
			//{
			//	thung.draw_bk[i][j]=220;
			//}else thung.draw_bk[i][j]=' ';
		}
	}*/
	/*khoi tao con ga
	char array[10]="~(.)~";
	strcpy(array,quacquac.draw_chicken);*/
	
	//khoi tao qua trung
	trung.draw_eggs=79;
	srand(time(NULL));
	int a=rand() % 4+1;
	switch(a)
	{
		case 1: trung.td_eggs.x=10;break;
		case 2: trung.td_eggs.x=30;break;
		case 3: trung.td_eggs.x=50;break;
		case 4: trung.td_eggs.x=70;break;
	} 
	trung.td_eggs.y= 3;
	
	
}

void draw(char map[100][100])// xu li hinh anh output
{
	for(int i=0;i<doc;i++)
	{
		for(int j=0;j<ngang;j++)
		{
			
			cout<<map[i][j];
			
			
		}
		cout<<endl;
	}
}

 
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

void logic(baskets &thung)
{
	
	//di chuyen thung
		
			if(GetAsyncKeyState(VK_RIGHT))
			{
				if(thung.td_baskets.y<80)
				{
					thung.td_baskets.y++;//=thung.td_baskets.y++;
				}		
			}
				
			else if(GetAsyncKeyState(VK_LEFT))
			{
				if(thung.td_baskets.y>2)
				{
					thung.td_baskets.y--;//=thung.td_baskets.y--;
				}
			}
	//qua trung		
			
}
	
	
		

	

void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X=0;
	Position.Y=0;
	SetConsoleCursorPosition(hOut,Position);
}
int main() 
{
	baskets thung ={17,12};
	while(hp>0)
	{
		XoaManHinh();
		
		
		logic(thung);
        khoitao(doc,ngang);
        drawbaskets(thung);
        draw(map);
        
	}
	
    
   
   
  
   gotoxy(10,2);
 
   //system("pause");
   sleep(200);
   
   
 
    return 0;
}



