#include<winbgim.h>
#include<stdio.h>
#include<math.h>

#define MAXDINH 20

int dinh[MAXDINH][2];
int n;
FILE *f;
float m[MAXDINH];

void readf()
{
	f=fopen("dagiac.txt","r");
	if(f==NULL) printf("not found");
	else
	{
		fscanf(f,"%d",&n);
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<2; j++)
				fscanf(f,"%d",&dinh[i][j]);
		}
		printf("Tong so dinh: %d\nCac dinh:\n",n);
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<2; j++)
				printf("%5d",dinh[i][j]);
			printf("\n");
		}
		fclose(f);
	}
}

void hesogoc()
{
	printf("\nHe so goc:");
	for(int i=0;i<n;i++)
	{
		int dx=dinh[i+1][0]-dinh[i][0];
		int dy=dinh[i+1][1]-dinh[i][1];
		if(dx==0)
			m[i]=999999;
		else
		{
			if(dy==0)
				m[i]=1;
			else
				m[i]=(float)(dy/dx);
		}
		printf("\n%.1f",m[i]);
	}
	
}

void scanline()
{
	int xgd[MAXDINH];
	int ymin=dinh[0][1];
	int ymax=dinh[0][1];
	for(int i=0;i<n;i++)
	{
		if(ymin>dinh[i][1]) ymin=dinh[i][1];
		if(ymax<dinh[i][1]) ymax=dinh[i][1];
	}
	printf("\nymin=%3d, ymax=%3d",ymin,ymax);
	int y=ymin;
	while(y<=ymax)
	{
		int dem=0;
		for(int i=0;i<n;i++)
		{
			if((y>=dinh[i][1] && y<dinh[i+1][1]) || (y<=dinh[i][1] && y>dinh[i+1][1]))
			{
				//xgd[dem++]=dinh[i][0]+round((y-dinh[i][1])/m[i]);
				printf("%d\n",y-dinh[i][1]);
			}
		}
		/*
		for(int i=0;i<dem-1;i++)
		{
			for(int j=i+1;j<dem;j++)
			{
				if(xgd[i]>xgd[j])
				{
					int tam=xgd[i];
					xgd[i]=xgd[j];
					xgd[j]=tam;
				}
			}
		}
		for(int i=0;i<dem;i++)
		{
			printf("\ny=%d: (%d,%d)",y,xgd[i],y);
		}
		for(int i=0;i<dem-1;i=i+2)
		{
			line(xgd[i],y,xgd[i+1],y);
		}*/
		y++;
	}
}

void vedagiac()
{
	dinh[n][0]=dinh[0][0];
	dinh[n][1]=dinh[0][1];
	for(int i=0;i<n;i++)
	{
		line(dinh[i][0],dinh[i][1],dinh[i+1][0],dinh[i+1][1]);
	}
}

int main()
{
	readf();
	initwindow(600,600);
	vedagiac();
	hesogoc();
	scanline();
	getch();
}
