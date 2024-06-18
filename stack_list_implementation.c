#include<stdio.h>
#include<stdlib.h>

struct node{
    int element;
    struct node *next;

}*list;

void push(int x){
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->element=x;
    if(list==NULL){
        newnode->next=NULL;
       
}
    else{
        newnode->next=list;
        
    }
    list=newnode;
}

void pop()
{
    struct node *tempnode;
    if(list==NULL)
    printf("stack underflows");
    else{
        tempnode=list;
        list=list->next;
        free(tempnode);
    }
}

void display()
{
    struct node *position;
    if(list==NULL)
        printf("stack is empty");
    else{
        position=list;
        while(position!=NULL)
        {
            printf("%d",  position->element);
            position=position->next;
        }
    }
}
int main()
{
    int n,a;
    struct node *list;
    list=malloc(sizeof(struct node));
    while(1)
    {
        printf("\n0.exit\n1.push\n2.pop\n3.pop\n4.display\n");
        printf("enter yout choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 0:
            exit(0);
            break;

            case 1:
            printf("enter the element to be inserted:");
            scanf("%d",&a);
            push(a);
            display();
            break;

            case 2:
            pop();
            display();
            break;

            case 3:
            display();
            break;
        }
    }
}