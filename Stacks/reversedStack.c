// reversing an stack

#include<stdio.h>
#include<stdlib.h>
#define max 10

void push(int);
int pop();
int st[max];
int top= -1;

void push(int val)
{
	st[++top]=val;
}

int pop()
{
	return(st[top--]);
}

int main()
{
	int n, i, val;
	int a[50];
	
	printf("\nsize: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		scanf("\n%d", &a[i]);
	}
	
	for(i=0; i<n; i++)
	{
		push(a[i]);
	}
	
	for(i=0; i<n; i++)
	{
		val = pop();
		a[i]=val;
	}
	
	printf("\nREVERSED:\n");
	for(i=0; i<n; i++)
	{
		printf("\n%d", a[i]);
	}
}