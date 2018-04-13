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

int hp=3;
int temp=0;
int diem=0;

eggs trung;
struct danhsach
{
	eggs trungs[30];
	
};
danhsach DS;
int soluong=0;//so luong qua trung
int dem1=0;
toado td_chicken;

void draweggs(eggs &trung)
{
	map[trung.td_eggs.x][trung.td_eggs.y]=220;
}
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
			if(i==0||i==doc)
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
				if(thung.td_baskets.y<65)
				{
					thung.td_baskets.y=thung.td_baskets.y+18;
				}		
			}
				
			else if(GetAsyncKeyState(VK_LEFT))
			{
				if(thung.td_baskets.y>15)
				{
					thung.td_baskets.y=thung.td_baskets.y-18;
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
void xulytrung(eggs &trung)
{
	//image_egg.draw_eggs=(char)2;
	srand(time(NULL));
	int a=rand() % 4+1;
	switch(a)
	{
		case 1: trung.td_eggs.y=14;break;
		case 2: trung.td_eggs.y=32;break;
		case 3: trung.td_eggs.y=50;break;
		case 4: trung.td_eggs.y=68;break;
	} 
	trung.td_eggs.x= 4;
	
}
void logictrung(int &diem,baskets &thung,eggs &trung ,int &hp)
{
	if(trung.td_eggs.x<20)
	{
		
		trung.td_eggs.x++;
	}
	else 
	{
		xulytrung(trung);
		hp--;
	}
	//va cham
	if(trung.td_eggs.x==thung.td_baskets.x&&trung.td_eggs.y>=thung.td_baskets.y&&trung.td_eggs.y<=thung.td_baskets.y+5)
	{
		
		diem++;
		xulytrung(trung);
	}
}
void khoitaotrung(danhsach &DS,baskets &thung,int &dem1)
{
	
	
	
		xulytrung(DS.trungs[dem1]);
		//logictrung(diem,thung,DS.trungs[i],hp);
		draweggs(DS.trungs[dem1]);
	
	//Sleep(200);
	//anymore(DS,thung);
	
}
int main() 
{
	baskets thung ={17,12};
	int dem=0;
	int dem2=0;
	
	while(hp>0)
	{
		XoaManHinh();
		
		
	
		logic(thung);
        khoitao(doc,ngang);
        drawbaskets(thung);
        
        dem2++;
        if(dem2%15==0)
        {
        	khoitaotrung(DS,thung,dem1);
        	dem1++;
        }
        
        //logictrung(diem,thung,trung,hp);
        //draweggs(trung);
        for(int i=0;i<=dem1;i++)
        {
        	logictrung(diem,thung,DS.trungs[i],hp);
        	draweggs(DS.trungs[i]);
        }
        
        
		if(dem1==5)
		{
			dem1=0;
		}
        draw(map);
        
        gotoxy(0,40);
        cout<<"diem : "<<diem<<endl;
        cout<<"mau : "<<hp;
        Sleep(200);
        if(dem2==50)
        {
        	dem2==0;
        }
        
	}
	XoaManHinh();
	
	
	
    
   
   
  
   
 
   
  
   
   
 
    return 0;
}

