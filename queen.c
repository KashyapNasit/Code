#include<stdio.h>
#include<stdbool.h>
#define SIZE 1000

int n;
int x[SIZE];

int mod(int i)
{
	if(i<0)
		return -1*i;
	return i;
}

bool isPossible(int r,int c)
{
	int i;
	for(i=0;i<r;i++)
		if(x[i]==c)
			return false;
	for(i=0;i<r;i++)
		if(mod(r-i)==mod(c-x[i]))
			return false;
	return true;
}

bool nqueen(int row)
{
	if(row==n)
		return true;
	int col;
	for(col=0;col<n;col++)
	{
		if(isPossible(row,col))
		{
			x[row]=col;
			bool sol = nqueen(row+1);
			if(sol)
				return sol;
		}
	}
	return false;
}

void initBoard()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		x[i]=0;
	}
}

void printBoard()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==x[i])
				printf("1 ");
			else
				printf("0 ");
		}
		printf("\n");
	}
}

int main()
{
	printf("Enter size of board: ");
	scanf("%d",&n);

	initBoard();

	if(nqueen(0))
	{
		printBoard();
	}
	else
	{
		printf("No Board Possible\n");
	}
	
	return 0;
}