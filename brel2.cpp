#include<stdio.h>
#include<graphics.h>
/*
void bre(int xa, int ya, int xb, int yb, int color)
{
	int dx=xb-xa;
	int dy=yb-ya;
	int x=xa;
	int y=ya;
	int Q=2*dx+dy;
	for(;y<=yb;y++)
	{
		printf("x=%d, y=%d, Q=%d\n",x,y,Q);
		putpixel(x,y,color);
		if(Q<=0)
		{
			x=x-1;
			Q=Q+2*dx+2*dy;
		}
		else
		{
			x=x;
			Q=Q+2*dx;
		}
		delay(100);
	}
}

int main()
{
	initwindow(300,300);
	bre(80,20,30,120,2);
	getch();
}*/
