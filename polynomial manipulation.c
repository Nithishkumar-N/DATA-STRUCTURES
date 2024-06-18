#include<stdio.h>
#include<stdlib.h>

struct poly{
    int cef;
    int pow;
    struct poly *next;
};

typedef struct poly Poly;

void create(Poly *list)
{
    int choice;
    Poly *newnode,*position;
    position=list;
    do
    {
        newnode=malloc(sizeof(Poly));
        printf("\nenter the co-eff:");
        scanf("%d",&newnode->cef);
        printf("\nenter the power:");
        scanf("%d",&newnode->pow);
        newnode->next=NULL;
        position->next=newnode;
        printf("\nenter 1 to continue:");
        scanf("%d",&choice);
    }while(choice==1);
}

void Add_poly(Poly *poly1, Poly *poly2, Poly *result)
{
    Poly *position,*newnode;
    poly1=poly1->next;
    poly2=poly2->next;
    result->next=NULL;
    position=result;
    while(poly1 !=NULL && poly2 !=NULL)
    {
        newnode=malloc(sizeof(Poly));
        if(poly1->pow==poly2->pow)
        {
            newnode->cef=poly1->cef+poly2->cef;
            newnode->pow=poly1->pow;
            poly1=poly1->next;
            poly2=poly2->next;
        }
        else if(poly1->pow>poly2->pow)
        {
            newnode->cef=poly1->cef;
            newnode->pow=poly1->pow;
            poly1=poly1->next;
        }
        else if(poly1->pow<poly2->pow)
        {
           newnode->cef=poly2->cef;
           newnode->pow=poly2->pow;
           poly2=poly2->next; 
        }
        newnode->next=NULL;
        position->next=newnode;
        position=newnode;
    }
    while(poly1 !=NULL || poly2 !=NULL)
    {
        newnode=malloc(sizeof(Poly));
        if(poly1 !=NULL)
        {
            newnode->cef=poly1->cef;
            newnode->pow=poly1->pow;
            poly1=poly1->next;
        }
        if(poly2 !=NULL)
        {
            newnode->cef=poly2->cef;
            newnode->pow=poly2->pow;
            poly2=poly2->next;
        }
        newnode->next=NULL;
        position->next=newnode;
        position=newnode;
    }
}

void display(Poly *list)
{
    Poly *position;
    position=list->next;
    while(position!=NULL)
    {
        printf("%dx^%d",position->cef,position->pow);
        position=position->next;
        if(position!=NULL &&position->cef>0)
            printf("+");
    }
}

int main()
{
    Poly *poly1=malloc(sizeof(Poly));
    Poly *poly2=malloc(sizeof(Poly));
    Poly *result=malloc(sizeof(Poly));
    poly1->next=NULL;
    poly2->next=NULL;
    printf("\nenter value of poly1");
    create(poly1);
    printf("the poly1 is:");
    display(poly1);
    printf("\nenter value of poly2");
    create(poly2);
    printf("the poly2 is:");
    display(poly2);
    Add_poly(poly1,poly2,result);
    printf("\nthe final polynomial equation is:");
    display(result);
    return 0;


}
