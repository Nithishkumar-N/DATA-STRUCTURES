#include <stdio.h>
#include <string.h>

#define size 20

int Stack[size], top = -1;
char infix[size], post[size];

void Push(char sym)
{
    top = top + 1;
    Stack[top] = sym;
}

char Pop()
{
    char e;
    e = Stack[top];
    top = top - 1;
    return e;
}

char Top()
{
    return Stack[top];;
}

int Priority(char sym)
{
  int p = 0;
  switch(sym)
  {
    case '(':
    p = 0;
    break;
    case '+':
    case '-':
    p = 1;
    break;
    case '*':
    case '/':
    case '%':
    p = 2;
    break;
    case '^':
    p = 3;
    break;
  }
return p;
}

int main()
{
    int i;
    printf("Enter the infix expression : ");
    scanf("%s",infix);
    for(i = 0; i < strlen(infix); i++)
 {
        if(infix[i] >= 'a' && infix[i] <= 'z')
            printf("%c", infix[i]);
        else if(infix[i] == '(')
            Push(infix[i]);
        else if(infix[i] == ')')
    {
        while(Top() != '(')
        printf("%c", Pop());
        Pop();
    }
    else
    {
        while(Priority(infix[i])<=Priority(Top()) && top!=-1)
        printf("%c", Pop());
        Push(infix[i]);
    }
 }
    
    for(i = top; i >= 0; i--)
        printf("%c", Pop());
    return 0;
}
