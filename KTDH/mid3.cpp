#include<stdio.h>
#include<graphics.h>
//m<1
/*
void mid(int xa, int ya, int xb, int yb, int color)
{
	int x=xa;
	int y=ya;
	int A=(yb-ya); 
	int B=-(xb-xa);
	float M=(float)A-B/2;
	for(;x<=xb;x++)
	{
		printf("x=%d, y=%d, M=%.1f\n",x,y,M);
		putpixel(x,y,color);
		if(M<0)
		{
			M=M+A-B;
			y=y-1;
		}
		else
		{
			M=M+A;
			y=y;
		}
		delay(50);
	}
}

int main()
{
	initwindow(300,300);
	mid(20,80,120,30,2);
	getch();
}*/
