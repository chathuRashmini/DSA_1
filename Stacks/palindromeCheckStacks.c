// checking whether a given string is a palindrome using stacks

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
 
int top = -1, front = 0;
int stack[MAX];
void push(char);
void pop();
 
void main()
{
    int i, choice;
    char s[MAX], b;
    while (1)
    {
        printf("\n\n1-enter string\n2-exit\n");
        printf("\nenter your choice\n");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("\nEnter the String\n");
            scanf("%s", s);
            
            for (i = 0; s[i] != '\0'; i++)
            {
                b = s[i];
                push(b);
            }
            
            for (i = 0; i < (strlen(s) / 2);i++)
            {
                if (stack[top] == stack[front])
                {
                    pop();
                    front++;
                }
                else
                {
                    printf("\n%s is not a palindrome\n", s);
                    break; 
                }
            }
            
            if ((strlen(s) / 2)  ==  front)
                printf("\n%s is palindrome\n",  s);
            
            front  =  0;
            top  =  -1;
            break;
        
        case 2:
            exit(0);
        
        default:
            printf("\nEnter correct choice\n");
        }
    }
}

void push(char a) // to push a character into stack
{
    top++;
    stack[top]  =  a;
}

void pop() // to delete an element in stack
{
    top--;
}
