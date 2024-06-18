#include<stdio.h>
#include<stdlib.h>
int size=8;
int arr[8];
int top=-1;

void push(int x){
if(top==size-1)
    printf("stack overflows");
else{
    top=top+1;
    arr[top]=x;    
}
}

void pop()
{
    if(top==-1)
        printf("stack underflows");
    else{
        top=top-1;

    }

}

void display()
{
    if(top==-1)
       printf("stack underflows");
    else
    {
       for(int i=top;i>=0;i--)
            printf("%d\n",arr[i]); 
    }
    
}
int main()
{
    int n,a;
    while(1){
        printf("\n 0.exit\n 1.push the element\n 2.pop the element\n 3.display the element\n");
        printf("enter your choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 0:
                exit(0);
                break;
            case 1:
                printf("enter the element to be push:");
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