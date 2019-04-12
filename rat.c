#include<stdio.h>
#include<stdbool.h>
#define SIZE 1000
int fx,fy;
int m,n;
int board[SIZE][SIZE];
int check[SIZE][SIZE];

int dx[]={0,0,  1,1,1,  -1,-1,-1};
int dy[]={-1,1, 0,-1,1,  0,1,-1};

bool isPossible(int x,int y)
{
	if(x>=0&&y>=0&&x<m&&y<n&&!board[x][y]&&!check[x][y])
		return true;
	return false;
}

bool ratmaze(int x, int y)
{
	if(x==fx && y==fy)
	{
		return true;
	}
	int i;
	for(i=0;i<8;i++)
	{
		if(isPossible(x+dx[i],y+dy[i]))
		{
			check[x][y]=1;
			bool sol=ratmaze(x+dx[i],y+dy[i]);
			if(sol)
				return sol;
		}
	}
	return false;
}

int main()
{
	int x,y;
	int i,j;

	printf("Enter size of board: ");
	scanf("%d %d",&m,&n);

	printf("Enter initial coords: ");
	scanf("%d %d",&x,&y);

	printf("Enter final coords: ");
	scanf("%d %d",&fx,&fy);

	printf("Enter maze:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&board[i][j]);
			check[i][j]=0;
		}
	}

	printf("Solving...\n");
	if(ratmaze(x,y))
	{
		printf("Path possible\n");
		//printFinalPath();
	}
	else
	{
		printf("No path possible\n");
	}
	return 0;
}
