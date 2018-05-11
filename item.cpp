#include"item.h"
#include<cstdlib>
void xulyitems(items &item)
{
		int a=rand() % 4 + 1;
	        switch(a)
	       {
		      case 1: item.td_items.y=14;break;
		      case 2: item.td_items.y=32;break;
		      case 3: item.td_items.y=50;break;
		      case 4: item.td_items.y=68;break;
		
	       } 
	       item.td_items.x=4;
}
void logicitems(items &item,baskets &thung,int &hp,int &checkitems)
{
	if(item.td_items.x<20)
	{
		item.td_items.x++;
		
	}else 
	{
		checkitems=1;
	}
	 if((item.td_items.x==thung.td_baskets.x||item.td_items.x==thung.td_baskets.x+1)&&item.td_items.y>=thung.td_baskets.y&&item.td_items.y<=thung.td_baskets.y+5)
	{
		if(hp<5)
		{
			hp++;
			checkitems=1;
		}
	}
	
	
}
void drawitems(items &item,char map[100][100])
{
	map[item.td_items.x][item.td_items.y]=219;
}
