#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	int freq;
	struct node *lchild,*rchild;
	char info;
};
typedef struct node NODE;

int HS;
int lchild(int a)
{
	return 2*a;
}
int rchild(int a)
{
	return 2*a+1;
}
int parent(int a)
{
	return a/2;
}

void min_heapify(NODE *pq[],int a)
{
	int l=lchild(a);
	int r=rchild(a);
	int min=a;
	if(l<=HS && pq[l]->freq < pq[min]->freq)
		min = l;
	if(r<=HS && pq[r]->freq < pq[min]->freq)
		min = r;
	if(a!=min)
	{
		NODE *t=pq[a];
		pq[a]=pq[min];
		pq[min]=t;
		min_heapify(pq,min);
	}
}

void insert(NODE *pq[],NODE *n)
{
	pq[++HS]=n;
	int i=HS;
	while(i>1 && pq[i]->freq < pq[parent(i)]->freq)
	{
		NODE *t=pq[i];
		pq[i]=pq[parent(i)];
		pq[parent(i)]=t;
		i=parent(i);
	}
}

void create_min_heap(int freq[], char info[], int n, NODE *pq[])
{
	int i=0;
	HS=n;
	for(i=1;i<=n;i++)
	{
		pq[i]=(NODE *)malloc(sizeof(NODE));
		pq[i]->freq = freq[i-1];
		pq[i]->lchild = pq[i]->rchild = NULL;
		pq[i]->info = info[i-1];
	}
	for(i=n/2;i>=1;i--)
	{
		min_heapify(pq,i);
	}
}

NODE *ExtractMin(NODE *pq[])
{
	if(!HS)
		return NULL;
	NODE *t=pq[1];
	pq[1]=pq[HS];
	pq[HS]=t;
	HS--;
	min_heapify(pq,1);
	return t;
}

void preorder(NODE *r)
{
	if(!r)
		return;
	printf("%c ",r->info);
	preorder(r->lchild);
	preorder(r->rchild);
}

NODE *HFE(int freq[], char info[], int n)
{
	int i;
	NODE *pq[100];
	NODE *x,*y;
	create_min_heap(freq,info,n,pq);
	for(i=0;i<n;i++)
	{
		x = ExtractMin(pq);
		y = ExtractMin(pq);
		if(!y)
			break;
		NODE *z = (NODE *)malloc(sizeof(NODE));
		z->lchild = x;
		z->rchild = y;
		z->freq = x->freq + y->freq;
		z->info = '#';
		insert(pq,z);
	}

	// printf("done %d\n",x->freq);
	// preorder(x);
	return x;
}

bool encode(NODE *root, char str[], int lb, char symbol)
{
	if(!root)
		return false;
	if(root->info == symbol)
	{
		printf("%s",str);
		return true;
	}
	bool res;
	str[lb]='0';
	str[lb+1]='\0';
	res = encode(root->lchild,str,lb+1,symbol);
	if(res)
		return res;
	str[lb]='1';
	res = encode(root->rchild,str,lb+1,symbol);
	if(res)
		return res;
	str[lb]='\0';
	return false;
}

int main()
{
	int n,i;
	printf("Enter no of items: ");
	scanf("%d",&n);
	char info[100];
	int freq[100];
	printf("Enter info and freq of items resp.\n");
	for(i=0;i<n;i++)
	{
		scanf(" %c %d",&info[i], &freq[i]);
	}
	NODE *root = HFE(freq,info,n);
	printf("Huffman tree's preorder:\n");
	preorder(root);
	printf("\n");
	printf("Enter a string: ");
	char str[100];
	char res[100];
	scanf("%s",str);
	printf("Encoded string: ");
	for(i=0;str[i]!='\0';i++)
	{
		encode(root,res,0,str[i]);
	}
	printf("\n");
	return 0;
}

/*
3 a 50 b 20 c 30
*/