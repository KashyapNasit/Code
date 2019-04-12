#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	int size;
	struct node *parent,*lchild,*rchild;
};
typedef struct node NODE;

int s;

int max(int a, int b)
{
	if(a>b)
		return a;
	return b;
}

int height(NODE *root)
{
	if(!root)
		return 0;
	return max(height(root->lchild),height(root->rchild))+1;
}

int balanceFactor(NODE *root)
{
	return height(root->lchild) - height(root->rchild);
}

NODE *insert(NODE *root, int i)
{
	if(!root)
	{
		NODE *p=(NODE *)malloc(sizeof(NODE));
		p->info=i;
		p->parent=root;
		p->lchild=p->rchild=NULL;
		return p;
	}
	if(i>root->info)
	{
		root->rchild=insert(root->rchild,i);
	}
	else if(i<root->info)
	{
		root->lchild=insert(root->lchild,i);
	}
	else
	{
		printf("REPEATATION NOT ALLOWED\n");
		s--;
	}
	int bfactor = balanceFactor(root);
	if(bfactor==2)								//l- case
	{
		if(balanceFactor(root->lchild)==1)		//ll case
		{
			NODE *b=root->lchild;
			NODE *c=root->lchild->lchild;
			b->parent=root->parent;
			root->parent=b;
			root->lchild=b->rchild;
			b->rchild=root;
			return b;
		}
		else if(balanceFactor(root->lchild)==-1)//lr case
		{
			NODE *b=root->lchild;
			NODE *c=root->lchild->rchild;
			c->parent=root->parent;
			root->parent=b->parent=c;
			b->rchild=c->lchild;
			root->lchild=c->rchild;
			c->lchild=b;
			c->rchild=root;
			return c;
		}
	}
	else if(bfactor==2)							//r- case
	{
		if(balanceFactor(root->rchild)==1)		//rr case
		{
			NODE *b=root->rchild;
			NODE *c=root->rchild->rchild;
			b->parent=root->parent;
			root->parent=b;
			root->rchild=b->lchild;
			b->lchild=root;
			return b;
		}
		else if(balanceFactor(root->rchild)==-1)//rl case
		{
			NODE *b=root->rchild;
			NODE *c=root->rchild->lchild;
			c->parent=root->parent;
			root->parent=b->parent=c;
			b->lchild=c->rchild;
			root->rchild=c->lchild;
			c->rchild=b;
			c->lchild=root;
			return c;
		}
	}
	return root;
}

int size(NODE *root)
{
	if(!root)
		return 0;
	return root->size;
}

int augment(NODE *root)
{
	if(!root)
		return 0;
	if(root->lchild)
		root->lchild->size = augment(root->lchild);
	if(root->rchild)
		root->rchild->size = augment(root->rchild);
	root->size = size(root->lchild) + size(root->rchild) + 1;
	return root->size;
}

void preorder(NODE *root)
{
	if(!root)	return;
	printf("%d ",root->info);
	preorder(root->lchild);
	preorder(root->rchild);
}

void inorder(NODE *root)
{
	if(!root)	return;
	inorder(root->lchild);
	printf("%d ",root->info);
	inorder(root->rchild);
}

int iton(NODE *root, int i)
{
	if(!root)
		return -1;
	int cr = size(root->lchild) + 1;
	if(i==cr)
		return root->info;
	else if(i<cr)
		return iton(root->lchild,i);
	else
		return iton(root->rchild,i-cr);
}

int ntoi(NODE *root, int rank, int n)
{
	if(!root)
		return -1;
	if(root->info==n)
		return rank+size(root->lchild)+1;
	else if(root->info>n)
		return ntoi(root->lchild,rank,n);
	else
		return ntoi(root->rchild,rank+size(root->lchild)+1,n);
}

int main()
{
	NODE *root=NULL;
	int i;
	printf("Enter size of array: ");
	scanf("%d",&s);
	printf("Enter array: ");
	int arr[s];
	for(i=0;i<s;i++)
	{
		scanf("%d",&arr[i]);
		root=insert(root,arr[i]);
	}
	root->size = augment(root);
    printf("CONSTRUCTED TREE:\nPreorder: ");
	preorder(root);
	printf("\nInorder: ");
	inorder(root);
	printf("\n");
	while(1)
	{
		printf("Enter i: ");
		scanf("%d",&i);
		printf("Number with rank %d is: %d\n",i,iton(root,i));
		printf("Enter n: ");
		scanf("%d",&i);
		printf("Number %d is having rank: %d\n",i,ntoi(root,0,i));
	}
}
