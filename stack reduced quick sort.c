#include<stdio.h>
#include<time.h>
#include<math.h>

void swap(int *a, int *b)
{
  int t = *a;
  *a=*b;
  *b=t;
}

int partition(int arr[] ,int l ,int r)
{
  int i,j;
  int pivot = arr[r];
  int ll=l-1;
  for(i=l;i<=r-1;i++)
  {
    if(arr[i]<=pivot)
    {
      ll++;
      swap(&arr[i],&arr[ll]);
    }
  }
  ll++;
  swap(&arr[r],&arr[ll]);
  return ll;
}

void stack_reduced_quick_sort(int arr[], int l, int r)
{
  while(l<r)
  {
    int p = partition(arr,l,r);
    if((p-l)<(r-p))
    {
      stack_reduced_quick_sort(arr,l,p-1);
      l=p+1;
    }
    else
    {
      stack_reduced_quick_sort(arr,p+1,r);
      r=p-1;
    }
  }
}

int main()
{
    int i,n;
    int arr[100];
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter array: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    stack_reduced_quick_sort(arr,0,n-1);
    printf("Output: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
