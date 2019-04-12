#include<stdio.h>
void IAS(int an[],int s[],int f[],int n)
{
	int i,j,flag,temp;   
	for(i=0;i<n-1;i++)
	{
		flag=1;
		for(j=0;j<n-i;j++)
		{
			if(f[j]>f[j+1])
			{
				temp=f[j+1];
				f[j+1]=f[j];
				f[j]=temp;
				flag=0;
				temp=s[j+1];
				s[j+1]=s[j];
				s[j]=temp;
				temp=an[j+1];
				an[j+1]=an[j];
				an[j]=temp;
			}
		}	
		if(flag==1)
		break;
	}
	int a[10000];
	i=0;
	a[i]=an[i];
	int cur=0;
	int try;
	for(try=1;try<n;try++)
	{
		if(s[try]>=f[cur])
		{
			i++;
			a[i]=an[try];
			cur=try;
		}
	}
	for(cur=0;cur<=i;cur++)
	printf("%d ",a[cur]);
}
int main()
{
	printf("Enter the number of activities: ");
	int n;
	scanf("%d",&n);
	int s[n];
	int f[n];
	int an[n];
	printf("Enter the activity number, start time and finish time of activities respectively:\n");
	int i;
	for(i=0;i<n;i++)
		scanf("%d%d%d",&an[i],&s[i],&f[i]);
	printf("Order of activities: ");
	IAS(an,s,f,n);
	printf("\n");
	return 0;
}
