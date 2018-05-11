#include <iomanip>
#include <string.h>
#include <iostream>
#include <sstream>
#include<windows.h>
#include<conio.h>
#include<unistd.h>
#include<cstdlib>
#include<ctime>
#include"trung.h"
#include"item.h"
#include"map.h"
#include"thung.h"
#include"tienich.h"
#include"Object.h"
using namespace std;


int doc=20;
int ngang=80;
char map[100][100];

int hp=3;

int diem=0;

eggs trung;

danhsach DS;


toado td_chicken;
items item;

int main() 
{
	baskets thung ={17,12};
	int dem=0;
	int dem2=0;
	int dem1=0;
	int item_sl=0;
	int checkitems=0;
	
	srand((unsigned int)time(NULL));
	while(hp>0)
	{
		Sleep(150);
	
		xoamanhinh();
		
	
		
        khoitao(doc,ngang,map);
        logic(thung);
        drawbaskets(thung,map);
        
        
        if(dem1<=2&&(dem2%30==0||dem2==0))
        {
        	khoitaotrung(DS,thung,dem1,map);
        	dem1++;
        }
        dem2++;
        
        for(int i=0;i<dem1;i++)
        {
        	if(DS.trungs[dem1].temp==0)
        	{
        		logictrung(diem,thung,DS.trungs[i],hp);
        	    draweggs(DS.trungs[i],map);
        	}else DS.trungs[dem1].temp--;
        	
        }
        if(dem2%80==0&&diem!=0)
        {
        	item_sl=1;
        	xulyitems(item);
        }
        if(item_sl==1)
        {
        	if(checkitems==0)
        	{
        		logicitems(item,thung,hp,checkitems);
        	    drawitems(item,map);
        	}
        	
        }
        if(checkitems==1)
        {
        	checkitems=0;
        	item_sl=0;
        }
        
        
        
		
        draw(map,doc,ngang);
        
        gotoxy(0,40);
        cout<<"diem : "<<diem<<endl;
        cout<<"mau : "<<hp;
        
        if(dem2==600)
        {
        	dem2==0;
        }
        if(dem1==100)
		{
			dem1=4;
			
		}
		
        
	}//het vong lap
	system("cls");
	gotoxy(10,10);
	if(diem<20)
	{
		cout<<"You are terrible";
	}
	else if(diem<=20&&diem<60)
	{
		cout<<"That's so wonderfull. Say oh year!!";
	}else cout<<"You are legend. Say year year";
	Sleep(1000000);
	
	
	
    
   
   
  
   
 
   
  
   
   
 
    return 0;
}

