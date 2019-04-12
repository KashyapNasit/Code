#include<stdio.h>
#include<stdbool.h>
#define SIZE 9

int board[SIZE][SIZE];

bool safe_row(int r,int c,int j)
{
	int i;
	for(i=0;i<9;i++)
		if(board[r][i]==j)
			return false;
	return true;
}

bool safe_col(int r,int c,int j)
{
	int i;
	for(i=0;i<9;i++)
		if(board[i][c]==j)
			return false;
	return true;
}

bool safe_box(int r,int c,int op)
{
	int br=(r/3)*3;
	int bc=(c/3)*3;
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(board[br+i][bc+j]==op)
				return false;
	return true;
}

bool isPossible(int r,int c,int i)
{
	if(safe_col(r,c,i)&&safe_row(r,c,i)&&safe_box(r,c,i))
		return true;
	return false;
}

void printBoard()
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
}

void no_of_zeros(int *r,int *c,int *t)
{
	int i,j;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			if(board[i][j]==0)
			{
				*r=i;
				*c=j;
				*t=1;
				return;
			}
	*t=0;
}

bool sudoku()
{
	int r,c,t,i;
	no_of_zeros(&r,&c,&t);
	if(!t)
		return true;
	for(i=1;i<=9;i++)
	{
		if(isPossible(r,c,i))
		{
			board[r][c]=i;
			bool sol=sudoku();
			if(sol)
				return sol;
			board[r][c]=0;
		}
	}
	return false;
}

int main()
{
	int i,j;
	printf("Enter board\n");
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			scanf("%d",&board[i][j]);
		}
	}
	if(sudoku())
	{
		printf("::Solution::\n");
		printBoard();
	}
	else
	{
		printf("No Board Possible\n");
	}
	return 0;
}
/*
0 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 0 4 2 5 6 7 
8 5 9 7 6 1 0 2 3 
4 0 6 8 5 3 7 9 1 
7 1 3 9 2 4 8 5 6 
9 6 1 5 3 0 2 8 4 
2 8 7 4 1 9 6 3 5 
3 4 5 2 8 0 1 7 9

5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 3 4 2 5 6 7 
8 5 9 7 6 1 4 2 3 
4 2 6 8 5 3 7 9 1 
7 1 3 9 2 4 8 5 6 
9 6 1 5 3 7 2 8 4 
2 8 7 4 1 9 6 3 5 
3 4 5 2 8 6 1 7 9
*/