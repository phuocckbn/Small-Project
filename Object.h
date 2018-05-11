#ifndef Object_H_
#define Object_H_


struct toado
{
	int x;
	int y;
};

struct items
{
	toado td_items;
};
struct baskets
{
    
	toado td_baskets;
	
};
struct eggs
{
	
	toado td_eggs;
	char draw_eggs;
	int temp;
	
};
struct danhsach
{
	eggs trungs[30];
	
};


#endif
