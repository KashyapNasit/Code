#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isPossible(char arr[],int ub,char ch)
{
	int i;
	for(i=0;i<ub;i++)
	{
		if(arr[i]==ch)
			return false;
	}
	return true;
}

void perm(char arr[],int ub,int n,char x[])
{
	if(ub==n)
	{
		printf("%s\n",arr);
		return;
	}
	int i;
	for(i=0;i<n;i++)
	{
		if(isPossible(arr,ub,x[i]))
		{
			arr[ub]=x[i];
			arr[ub+1]='\0';
			perm(arr,ub+1,n,x);
			arr[ub]='\0';
		}
	}
}

int main()
{
	int n,i;
	char x[100];
	char temp[100];
	printf("Enter no. of characters:");
	scanf("%d",&n);
	printf("Enter input characters:\n");
	for(i=0;i<n;i++)
	{
		scanf(" %c",&x[i]);
	}
	printf("All permutations:\n");
	perm(temp,0,n,x);
	return 0;
}