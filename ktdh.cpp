#include<graphics.h>
#include<stdio.h>
#include<math.h>

void DDA1(int xa, int ya, int xb, int yb, int color)
{
	float m = float((yb-ya)/(xb-xa));
	int xsau = xb;
	float ysau = yb;
	for(ysau = yb;ysau>=ya; ysau--)
	{
		printf("xsau=%d, ysau=%.0f\n",xsau,round(ysau));
		xsau=xsau-(1/m);
		putpixel(ysau,round(xsau),color);
	}
}

int main()
{
	initwindow(300,300);
	DDA1(30,20,80,120,2); printf("\n");
	getch();
}
