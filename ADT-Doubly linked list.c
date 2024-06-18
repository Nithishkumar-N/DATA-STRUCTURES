#include<stdio.h>
#include<stdlib.h>
struct node{
    int element;
    struct node *next;
    struct node *prev;
};
typedef struct node Node;

Node *Find(Node *list,int x)
{
    Node *position;
    position=list->next;
    while(position!=NULL && position->element!=x)
        position=position->next;
    return position;
}

void Ins_beg(Node *list,int e)
{
    Node *newnode;
    newnode=malloc(sizeof(Node));
    newnode->element=e;
    if(list->next==NULL)
        newnode->next=NULL;
    else
    {
        newnode->next=list->next;
        list->next->prev=newnode;
    }
    list->next=newnode;
    newnode->prev=list;
}

void Ins_mid(Node *list,int p,int e)
{
    Node *newnode=malloc(sizeof(Node));
    Node *position;
    position = Find(list,p);
    newnode->element=e;
    newnode->next=position->next;
    newnode->prev=position;
    position->next->prev=newnode;
    position->next;
}

void Ins_last(Node *list,int e)
{
    Node *newnode=malloc(sizeof(Node));
    Node *position;
    newnode->element=e;
    position=list;
    while(position->next!=NULL)
        position=position->next;
    position->next=newnode;
    newnode->prev=position;
}

void Del_beg(Node *list)
{
    if(list->next!=NULL)
    {
    Node *tempnode;
    tempnode=list->next;
    list->next=tempnode->next;
    tempnode->next->prev=list;
    free(tempnode);
       }
    else
        printf("list is empty");
}

void Del_mid(Node *list,int e)
{
    if(list->next!=NULL)
    {
    Node *tempnode,*position;
    position=Find(list,e);
    tempnode=position;
    position->prev->next=position->next;
    position->next->prev=position->prev;
    free(tempnode);
    }
    else
        printf("list is empty");
}


void Del_end(Node *list)
{
    if(list->next!=NULL)
    {
        Node *position;
        Node *tempnode;
        position=list;
        while(position->next!=NULL)
            position=position->next;
        tempnode=position;
        position->prev->next=NULL;
        free(tempnode);
    }
    else
        printf("list is empty");
}

void display(Node *list)
{
    if(list->next!=NULL)
    {
    Node *position;
    position=list;
    while(position->next!=NULL)
        {
            position=position->next;
            printf("%d  ",position->element);
        }
   }
   else
    printf("list is empty");
}

int main()
{
    int n,p,a,b,c,d;
    Node *list=malloc(sizeof(Node));
    while(1)
    {
        printf("\n 0.exit\n 1.insert at begining\n 2.insert at middle\n 3.insert at last\n 4.deletion at begining\n 5.deletion at middle\n 6.deletion at last\n");
        printf("enter your choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 0:
                exit(0);
                break;
            case 1:
                printf("enter the element:");
                scanf("%d",&a);
                Ins_beg(list,a);
                display(list);
                break;
            case 2:
                printf("enter the position after which element to be inserted:");
                scanf("%d",&p);
                printf("enter the element:");
                scanf("%d",&b);
                Ins_mid(list,p,b);
                display(list);
                break;
            case 3:
                printf("enter the element:");
                scanf("%d",&c);
                Ins_last(list,c);
                display(list);
                break;
            case 4:
                Del_beg(list);
                display(list);
                break;
            case 5:
                printf("enter the element to be deleted:");
                scanf("%d",&d);
                Del_mid(list,d);
                display(list);
                break;
            case 6:
                Del_end(list);
                display(list);
                break;
            case 7:
                display(list);
                break;
        }
    }
}