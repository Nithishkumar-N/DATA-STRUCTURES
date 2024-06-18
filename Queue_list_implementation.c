#include<stdio.h>
#include<stdlib.h>

struct node{
    int element;
    struct node *next;
}*front=NULL, *rear=NULL;


void enqueue(int x)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->element=x;
    newnode->next=NULL;
    if(rear==NULL)
        front=rear=newnode;
    else
    {
        rear->next=newnode;
        rear=newnode;
    }

}

void dequeue()
{
    if(front==NULL)
        printf("queue underflows");
    else
    {
        struct node*tempnode;
        tempnode=front;
        if(front==rear)
            front=rear=NULL;
        else{
            front=front->next;
        }
        free(tempnode);

    }
}
void display()
{
    if(front==NULL){
        printf("queue is empty");
    }
    else{
        struct node*position;
        position=front;
        while(position!=NULL){
            printf("%d ",position->element);
            position=position->next;
        }
    }
}
int main()
{
    int n,a;
    while(1)
    {
        printf("\n0.exit\n1.enqueue\n2.dequeue\n3.display\n");
        printf("enter yout choice:");
        scanf("%d",&n);
        switch(n){
            case 0:
            exit(0);
            break;

            case 1:
            printf("enter the elment to be inserted:");
            scanf("%d",&a);
            enqueue(a);
            display();
            break;

            case 2:
            dequeue();
            display();
            break;

            case 3:
            display();
            break;
        }
    }
}