#include<stdio.h>
#include<stdlib.h>

int size=8;
int arr[8];
int front,rear=-1;

void enqueue(int x)
{
    if(front==size-1)
      printf("stack overflows");
    else
    {
        rear=rear+1;
        arr[rear]=x;
        if(front==-1)
            front=0;
    }
}

void dequeue()
{
  if(front==-1)
    printf("stack underflows");
  else
  {
    if(front==rear)
        front=rear=-1;
    else
        front=front+1;
  }
}

void display()
{
    if(front==-1)
        printf("stack is empty");
    else
    {
        for(int i=front;i<=rear;i++)
            printf("%d ",arr[i]);
    }
}
int main()
{
    int n,a;
    while(1){
        printf("\n0.exit\n1.enqueue\n2.dequeue\n3.display\n");
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