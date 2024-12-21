#include<stdio.h>
#include<graphics.h>
/*
void bre(int xa, int ya, int xb, int yb, int color)
{
	int dx=xb-xa;
	int dy=yb-ya;
	int x=xa;
	int y=ya;
	int Q=-2*dx-2*dy;
	for(;x<=xb;x++)
	{
		printf("x=%d, y=%d, Q=%d\n",x,y,Q);
		putpixel(x,y,color);
		if(Q<0)
		{
			y=y;
			Q=Q-2*dy;
		}
		else
		{
			y=y-1;
			Q=Q-2*dx-2*dy;
		}
		delay(100);
	}
}

int main()
{
	initwindow(300,300);
	bre(20,80,120,30,2);
	getch();
}*/
