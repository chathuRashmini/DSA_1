// checking whether paranthesis of an expression is 
// in correct order, using stacks

#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 10

int top = -1;
int st[max];
void push(char);
char pop();

void main()
{
	char exp[max], t;
	int i, flag=1;
	
	printf("\nExpression: ");
	gets(exp);
	
	for(i=0; i<strlen(exp); i++)
	{
		if (exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
		{
			push(exp[i]);
		}
		
		if (exp[i]==')' || exp[i]==']' || exp[i]=='}')
		{
			if (top== -1)
			{
				flag=0;
			}
			else
			{
				t=pop();
				if(exp[i]==')' && (t=='{' || t=='['))
				{
					flag=0;
				}
				if(exp[i]==']' && (t=='{' || t=='('))
				{
					flag=0;
				}
				if(exp[i]=='}' && (t=='(' || t=='['))
				{
					flag=0;
				}
			}
		}
	}
	
	if(top>=0)
	{
		flag=0;
	}
	
	if(flag==0)
	{
		printf("\nINVALID!\n");
	}
	else
	{
		printf("\nVALID!\n");
	}
}

void push(char c)
{
	if (top == (max-1))
	{
		printf("\nOVERFLOW!\n");
	}
	else
	{
		top=top+1;
		st[top]=c;
	}
}

char pop()
{
	if (top == -1)
	{
		printf("\nUNDERFLOW!\n");
	}
	else
	{
		return st[top--];
	}
}