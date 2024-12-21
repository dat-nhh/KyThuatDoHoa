#include<graphics.h>
#include<stdio.h>

// khai bao bien
int xwmin = 100;
int xwmax = 300;
int ywmin = 100;
int ywmax = 300;

void khoitao()
{
	setcolor(15);// white
	setlinestyle(1,0,2);//width = 2
	rectangle(xwmin,ywmax,xwmax,ywmin);
}

void inmang(int a[])
{
	for(int i=0; i<4; i++)
	{
		printf("%5d",a[i]);
	}
}

float MIN(float a, float b)
{
	return (a<b)?a:b;
}

float MAX(float a, float b)
{
	return (a>b)?a:b;
}

void LiangBasky(int xa, int ya, int xb, int yb)
{
	// in ra man hinh toa do cua A(xa,ya) va B(xb,yb)
	printf("Xa= %d, Ya= %d, Xb= %d, Yb= %d",xa,ya,xb,yb);
	// ve doan thang noi 2 diem A(xa,ya) va B(xb,yb)
	setcolor(13);//pink
	line(xa,ya,xb,yb);
	//xay dung pk va qk
	int dx=xb-xa;
	int dy=yb-ya;
	int p[4]={-dx,dx,-dy,dy};
	int q[4]={xa-xwmin,xwmax-xa,ya-ywmin,ywmax-ya};
	//in ra man hinh mang pk va qk
	printf("\npk[]:"); inmang(p);
	printf("\nqk[]:"); inmang(q);
	//tim t1, t2 dua vao pk>0 hoac pk<0
	float t1=0;
	float t2=1;
	for(int i=0; i<4; i++)
	{
		if(p[i]<0)// xac dinh t1 = max(0,qk/pk) khi pk<0
		{
			t1=MAX(t1,(float)q[i]/p[i]);
		}
		else// xac dinh t2 = min(1,qk/pk) khi pk>0
		{
			t2=MIN(t2,(float)q[i]/p[i]);
		}
	}
	// in ra t1 va t2
	printf("\nt1 = %.5f, t2 = %.5f",t1,t2);
	// the vao pt1 tim x0, y0
	int x0 = xa + t1*dx;
	int y0 = ya + t1*dy;
	// the vao pt1 tim x1, y1
	int x1 = xa + t2*dx;
	int y1 = ya + t2*dy;
	// in ra x0, y0, x1, y1
	printf("\nX0 = %d, Y0 = %d, X1 = %d, Y1 = %d",x0,y0,x1,y1);
	//ve doan thang noi 2 giao diem
	setcolor(2);//GREEN
	line(x0,y0,x1,y1);// lay th cua bai code trc viet lai doan ve
}

int main()
{
	initwindow(400,400);
	khoitao();
	LiangBasky(150,280,360,150);//A trong, B phai
	//LiangBasky(150,140,150,450);//A trong, B tren
	//LiangBasky(200,140,60,140);//A trong, B trai
	//LiangBasky(200,140,200,70);//A trong, B duoi
	
	//A ngoai + B trong
	//LiangBasky(360,150,150,280);//B trong, A phai
	//LiangBasky(150,450,150,140);//B trong, A tren
	//LiangBasky(60,140,200,140);//B trong, A trai
	//LiangBasky(200,70,200,140);//B trong, A duoi
	
	//A trai + B phai
	//LiangBasky(70,200,350,200);//A trai, B phai
	
	//A tren + B duoi
	//LiangBasky(200,40,200,360);//A tren, B duoi
	
	//A trai + B tren
	//LiangBasky(70,200,240,400);//A trai, B tren
	//A trai + B duoi
	//LiangBasky(70,200,240,35);//A trai, B duoi
	
	//A phai + B tren
	//LiangBasky(370,200,140,320);//A phai, B tren
	
	//A phai + B duoi
	//LiangBasky(370,200,140,35);//A phai, B duoi
	//A goc tren, trai + B ben trong
	//LiangBasky(50,30,150,140);//B trong, A tren, trai
	//LiangBasky(10,80,150,140);//B trong, A tren, trai
	
	//A goc duoi, trai + B ben trong
	//LiangBasky(80,430,150,140);//B trong, A duoi, trai
	//LiangBasky(10,430,150,140);//B trong, A duoi, trai
	//A goc tren, phai + B ben trong
	//LiangBasky(450,30,200,170);//B trong, A tren, phai
	//LiangBasky(330,10,200,170);//B trong, A tren, phai
	
	//A goc duoi, phai + B ben trong
	//LiangBasky(450,430,200,170);//B trong, A duoi, phai
	//LiangBasky(330,410,200,170);//B trong, A duoi, phai
	//A trai, B tren: ngoai cua so cat
	//LiangBasky(30,200,140,450);//A trai, B tren	
	getch();
}
