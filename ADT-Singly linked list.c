#include<stdio.h>
#include<stdlib.h>
struct node{
	int element;
	struct node *next;
};

struct node *find(struct node *list,int x)
{
    struct node *position;
    position=list->next;
    while(position->element!=x && position->next!=NULL)
        position=position->next;
    return position;
}

struct node *prev(struct node *list, int e)
{
    struct node *position;
    position=list->next;
    while(position->next->element!=e && position->next!= NULL)
        position=position->next;
    return position;
}

void insert_beg(struct node *list,int e)
{
	struct node *newnode;
	newnode=malloc(sizeof(struct node));
	newnode->element=e;
	newnode->next=list->next;
	list->next=newnode;
}

void insert_mid(struct node *list,int p,int e)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    struct node *position;
    position=find(list,p);
    newnode->element=e;
    newnode->next=position ->next;
    position->next=newnode;
}

void insert_last(struct node *list, int e)
{
    struct node *newnode,*position;
    newnode=malloc(sizeof(struct node));
    newnode->element=e;
    newnode->next=NULL;
    position=list;
    while(position->next!=NULL)
            position=position->next;
    position->next=newnode;
    }
    
void del_begg(struct node *list)
{
    if(list->next!=NULL)
    {
        struct node *tempnode;
        tempnode=malloc(sizeof(struct node));
        tempnode=list->next;
        list->next=tempnode->next;
        free(tempnode);
    }
    else
    printf("its empty");
}

 void del_midd(struct node *list,int e)
{
    struct node *pre,*position;
    pre=prev(list,e);
    position=pre->next;
    pre->next=position->next;
    free(position);
    
}

void del_last(struct node *list)
{
    struct node *temp,*position;
    position=list;
    while(position->next->next!=NULL){
        position=position->next;
    }
    temp=position->next;
    position->next=NULL;
    free(temp);
}


void display(struct node *list)
{
	struct node *position;
	position=list;
	while(position->next!=NULL)
	{
    position=position->next;
	printf("%d ",position->element);
	}
}

int main()
{
    
	int n,p,a,b,c,d;
	struct node *list;
	list=malloc(sizeof(struct node));
	list->next=NULL;
	while(1) {
    printf("\n 1.insert at begining\n 2.insert at middle\n 3.inser at last\n 4.deletion at begining\n 5.deletion at middle\n 6.deletion at last\n");
    printf("enter your choice:");
	scanf("%d",&n);
	switch(n){
	case 0:
	exit(0);
	break;
	
	case 1:	
	    printf("eneter the element to insert_beg:");
	    scanf("%d",&a);
    	insert_beg(list,a);
    	display(list);
	    break;
	
	case 2:
	printf("enter the element to insertmidd:");
    scanf("%d",&b);
	printf("eneter element after which to be inserted: ");
    scanf("%d",&p);
    insert_mid(list,p,b);
    display(list);
	break;
	
	case 3:
	printf("enter the element to be at last:");
	scanf("%d",&c);
	insert_last(list,c);
	display(list);
	break;
	
	case 4:
	del_begg(list);
	display(list);
	
	case 5:
	printf("enter the element to be deleted:");
	scanf("%d",&d);
	del_midd(list,d);
	display(list);
	break;
	
	case 6:
	del_last(list);
	display(list);
	break;
	}
  }
}