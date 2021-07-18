// implementation of a stack

#include<stdio.h>
#include<stdlib.h>
#define max 50

void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
int display(int st[]);

int st[max];
int top=-1;

int main()
{
	int val, option, ch;
	option = 1;
	while (option)
	{
		printf("\n---------------------------------------------------------------------------------\n");
		printf("\n1. push\n2. pop\n3. peek\n4. display\n5. exit");
		printf("\n---------------------------------------------------------------------------------\n");
		
		printf("\nChoice: ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
				push(st, val);
				break;
				
			case 2:
				pop(st);
				break;
				
			case 3:
				peek(st);
				break;
				
			case 4:
				display(st);
				break;
				
			case 5:
				return 0;
				
			default:
				printf("\nWRONG CHOICE!\n");
				break;
		}
		
		printf("\nOption: ");
		scanf("%d", &option);
	}
}

void push(int st[], int val)
{
	if (top == max-1)
	{
		printf("\nOVERFLOW!\n");
	}
	else
	{
		printf("\nValue: ");
		scanf("%d", &val);
		top++;
		st[top]=val;
	}
}

int pop(int st[])
{
	int val;
	if (top == -1)
	{
		printf("\nOVERFLOW!\n");
	}
	else
	{
		val = st[top];
		printf("\nPopped element: %d\n", val);
		top--;
		return val;
	}
}

int peek(int st[])
{
	int val;
	if (top == -1)
	{
		printf("\nOVERFLOW!\n");
	}
	else
	{
		printf("\npeek: %d\n", st[top]);
	}
}

int display(int st[])
{
	int val, i;
	if (top == -1)
	{
		printf("\nOVERFLOW!\n");
	}
	else
	{
		for (i=top; i>0; i--)
		{
			printf("\t%d", st[i]);
		}
	}
}