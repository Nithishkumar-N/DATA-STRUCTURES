#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *left;
	int element;
	struct node *right;
};

typedef struct node Node;

Node *insert(Node *tree,int e)
{
	Node *newnode=malloc(sizeof(Node));
	if(tree==NULL)
	{
		newnode->element=e;
		newnode->left=NULL;
		newnode->right=NULL;
		tree=newnode;
	}
	else if(e<tree->element)
		tree->left=insert(tree->left,e);
	else if(e>tree->element)
		tree->right=insert(tree->right,e);
	return tree;
}
	
void inorder(Node *tree)
{
	if(tree!=NULL)
	{
		inorder(tree->left);
		printf("%d ",tree->element);
		inorder(tree->right);
	}
}

void preorder(Node *tree)
{
	if(tree!=NULL)
	{
		printf("%d ",tree->element);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void postorder(Node *tree)
{
	if(tree!=NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf("%d ",tree->element);
	}
}

int main()
{
	int n,e,i,c;
	Node *tree=NULL;
	printf("Enter number of nodes in tree:");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&e);
		tree=insert(tree,e);
	}
	while(1)
	{
		printf("0.exit\n1.inorder\n2.preorder\n3.postorder");
		printf("Enter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
				exit(0);
				break;
			case 1:
				inorder(tree);
				printf("\n");
				break;
			case 2:
				preorder(tree);
				printf("\n");
				break;
			case 3:
				postorder(tree);
				printf("\n");
				break;
		}
	}
return 0;
}
				