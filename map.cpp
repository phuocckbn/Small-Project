#include"map.h"
#include"Object.h"
#include<iostream>
using namespace std;
void drawchicken(int x,int y,char map[100][100])
{
	map[x][y]='<';
	map[x][y+1]='2';
	map[x+1][y]='^';
	map[x+1][y+1]='(';
	map[x+1][y+2]='*';
	map[x+1][y+3]=')';
	map[x+1][y+4]='^';
}
void draw(char map[100][100],int doc,int ngang)// xu li hinh anh output
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
void khoitao(int doc, int ngang,char map[100][100])
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
    drawchicken(2,12,map);
    drawchicken(2,30,map);
    drawchicken(2,48,map);
    drawchicken(2,66,map);
    
	
	
	
	
}
