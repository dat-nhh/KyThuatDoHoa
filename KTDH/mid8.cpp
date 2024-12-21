#include<stdio.h>
#include<graphics.h>
//m>1

void mid(int xa, int ya, int xb, int yb, int color)
{
	int x=xa;
	int y=ya;
	int A=(yb-ya); 
	int B=-(xb-xa);
	float M=(float)-A/2-B;
	for(;y>=yb;y--)
	{
		printf("x=%d, y=%d, M=%.1f\n",x,y,M);
		putpixel(x,y,color);
		if(M<0)
		{
			M=M-A-B;
			x=x-1;
		}
		else
		{
			M=M-B;
			x=x;
		}
		delay(50);
	}
}

int main()
{
	initwindow(300,300);
	mid(80,120,30,20,2);
	getch();
}
