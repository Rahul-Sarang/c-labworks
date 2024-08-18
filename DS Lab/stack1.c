#include<stdio.h>
#include<stdlib.h>
#define MAX 4


int stack[MAX];
int top=-1;

int isFull()
{
     return top ==MAX-1;
}

int isEmpty()
{
     return top==-1;
}


void push(int data)
{
    if(isFull())
    {
         printf("stack overflow");
         return;
    }
     top=top+1;
     stack[top]=data;
}


int pop()
{
    if(isEmpty())
    {
         printf("Sack underflow");
         exit(1); 
    }
     int value=stack[top];
     top=top-1;
     return value;
}

int peek()
{
    if(isEmpty())
    {
         printf("Sack underflow");
         exit(1);
    }
     return stack[top];
}


void print()
{
    if(isEmpty())
    {
         printf("Sack underflow\n");
         return;
    }
    for(int i=top;i>=0;i--)
    {
         printf("%d  ",stack[i]);
    }
     printf("\n");
}

void main()
{
    int choice,data;
    
    while(1)
    {
        printf("\n");
        printf("1 . Push\n");
        printf("2 . Pop\n");
        printf("3 . Print the top element\n");
        printf("4 . Print all elements in the stack\n");
        printf("5 . Quit\n");
        printf("Plese enter your choice :");
        scanf ("%d",&choice);
    
        switch(choice)
        {
            case 1: printf("Enter the Element to be push : ");
                    scanf("%d",&data);
                    push(data);
                    break;
            case 2: data=pop();
                    printf("Deleted element from the stack is %d\n",data);
                    break;
            case 3:  printf("The top most element is %d\n",peek());
                     break;
            case 4: print();
                     break;
            case 5: exit(0);
            default: printf("wrong choice");
        }
    }
}