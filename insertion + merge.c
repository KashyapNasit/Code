#include<stdio.h>
#include<time.h>
#include<math.h>

int size;
double lg;

void insertionSort(int arr[], int l, int r)
{
  int i,j,k,n=r-l;
  int temp[r-l+10];
  for(i=l;i<=r;i++){
    temp[i-l]=arr[i];
  }
  for(i=1;i<=n;i++)
  {
    int key=temp[i];
    for(j=i-1;j>=0 && key<temp[j];j--)
    {
      temp[j+1]=temp[j];
    }
    temp[j+1]=key;
  }
  for(i=l;i<=r;i++)
  {
    arr[i]=temp[i-l];
  }
}


void merge(int arr[], int l, int m, int u)
{
  int i=l,j=m+1,k=0,t;
  int res[u-l+10];
  while(i<=m&&j<=u)
  {
    if(arr[i]<arr[j])
    {
      res[k++]=arr[i++];
    }
    else if(arr[i]>arr[j])
    {
      res[k++]=arr[j++];
    }
    else
    {
      res[k++]=arr[i++];
      res[k++]=arr[j++];
    }
  }
  while(i<=m)
  {
    res[k++]=arr[i++];
  }
  while(j<=u)
  {
    res[k++]=arr[j++];
  }
  for(t=0;t<k;t++)
  {
    arr[l+t]=res[t];
  }
}
    

void mergeSort(int arr[], int l, int u)
{
  if(u-l < lg)
  {
    insertionSort(arr,l,u);
  }
  else
  {
    int t = (l+u)/2;
    mergeSort(arr,l,t);
    mergeSort(arr,t+1,u);
    merge(arr,l,t,u);
  }
}

int main()
{
    int i,n;
    printf("Enter n: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    size = n;
    lg = log(size)/log(2);
    mergeSort(arr,0,n-1);
    printf("Output: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
