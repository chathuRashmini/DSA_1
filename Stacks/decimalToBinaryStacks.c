// convert decimal numbers into binary numbers using a stack

#include<stdio.h> 
#include<math.h>
#define max 20

int top = -1; //top of the stack is indexed to -1
int numberStack[max]; // an integer stack with the size of 'max'
void push(int); 
int pop(void); 

int main() 
{
    int i, num, x, flag=0, s, bin=0, factor;
     
    printf("Enter any decimal number: ");
    scanf("%d", &num);
     
    while(num > 0)
    {
        if(num == 1)
            push(num);
        else
        {
            x = num%2; 
            // since we take the modulous here, x is either 0 or 1
            push(x);
        }
        num = num/2;
        flag++;
    }

    for(i=0; i<flag; i++) // going through the stack
    {
        s = pop();
        bin = bin + s*pow(10, (flag-1-i));
    }

    printf("\nEquivalent Binary number is --> %d",bin);
    return 0;
}

void push(int n)
{
    // function to push a number into the stack
    if(top == max-1)
    {
        printf("Error! Overflow"); 
        // since the maximum number of elements that stack can store = max
    }
    numberStack[++top] = n;
}

int pop(void)
{
    int y;
    if(top == -1)
    {
        printf("Error! Underflow");
        // popping cannot be done if there are no elements in the satck
    }

    y = numberStack[top]; // take the element at the top of the stack
    top = top - 1;
    return y;
}