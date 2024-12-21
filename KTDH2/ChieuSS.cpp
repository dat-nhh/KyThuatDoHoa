#include<stdio.h>
#include<math.h>
#include<graphics.h>

#define maxdinh 20
#define toado "ChopNhon.inp"
#define matranke "ChopNhon.mtk"

int dinh[maxdinh][maxdinh];// toa do cac dinh hinh chop
int n;//so dinh hinh chop
int mtk[maxdinh][maxdinh];//ma tran ke cua cac dinh
FILE *f;

void inmatran(int a[][maxdinh], int hang, int cot)
{
	for(int i=0;i<hang;i++)
	{
		for(int j=0;j<cot;j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
}

void readfile()
{
	f=fopen(toado,"r");
	if(f==NULL) printf("not found");
	else
	{
		fscanf(f,"%d",&n);
		for(int i=0;i<n;i++)//so dinh
		{
			for(int j=0;j<3;j++)//so chieu
				fscanf(f,"%d",&dinh[i][j]);
		}
	}
	fclose(f);
	inmatran(dinh,n,3);
	/////////////////////////
	f=fopen(matranke,"r");
	if(f==NULL) printf("not found");
	else
	{
		fscanf(f,"%d",&n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				fscanf(f,"%d",&mtk[i][j]);
		}
	}
	fclose(f);
	inmatran(mtk,n,n);
}

void oxy(){
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(mtk[i][j]==1)
				line(dinh[i][0],dinh[i][1],dinh[j][0],dinh[j][1]);
		}
	}
}

void oxz(){
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(mtk[i][j]==1)
				line(dinh[i][0],dinh[i][2],dinh[j][0],dinh[j][2]);
		}
	}
}

void oyz(){
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(mtk[i][j]==1)
				line(dinh[i][1],dinh[i][2],dinh[j][1],dinh[j][2]);
		}
	}
}

void chieuxien(float L, int theta)
{
	float T[3][3] = {{1,0,0},{0,1,0},{L*cos(theta*3.1416/180),L*sin(theta*3.1416/180),0}};
	//in ma tran
	for(int i=0;i<=3;i++)
	{
		for(int j=0;j<=3;j++)
		{
			printf("%.2f",T[i][j]);
		}
		printf("\n");
	}
	//nhan 2 ma tran: dinh * T
	int Pnew[maxdinh][maxdinh];
	//khoi tao ma tran Pnew
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			Pnew[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)// hang cua ma tran dinh
	{
		for(int j=0;j<3;j++)// cot ma tran dinh = hang ma tran T
		{
			for(int k=0;k<3;k++)// cot ma tran 
			{
				Pnew[i][j] += round(dinh[i][k]*T[k][j]);
			}
		}
	}
	inmatran(Pnew,n,3);
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(mtk[i][j]==1)
			{
				line(Pnew[i][0],Pnew[i][1],Pnew[j][0],Pnew[j][1]);
			}
		}
	}
}

int main()
{
	readfile();
	initwindow(800,800);
//	oxy();
//	oxz();
//	oyz();
//	chieuxien(0.5,10);
	char buffer[32];
	for(int i=0;i<180;i++)
	{
		chieuxien(0.5,i);
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 10);
		sprintf(buffer,"%d",i);
		outtextxy(0,0,buffer);
		delay(100);
		cleardevice();
	}
	getch();
}
