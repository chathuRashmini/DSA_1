// convert infix to postfix using stacks

#include <stdio.h> 
#include <conio.h> 
#include <ctype.h> 
#include <string.h> 
#define MAX 100

char numberStack[MAX];
int top= -1;

void push(char numberStack[], char); 
char pop(char numberStack[]);
void InfixtoPostfix(char source[], char target[]); 
int getPriority(char); 

int main() 
{
	char infix[100], postfix[100]; 
	
	printf("\n Enter any infix expression : "); 
	gets(infix); 
	strcpy(postfix, ""); // asign an empty string (character array) to the postfix

	InfixtoPostfix(infix, postfix); 
	
	printf("\n The corresponding postfix expression is : "); 
	puts(postfix); 
	getch(); 
	return 0; 
} 

void InfixtoPostfix(char source[], char target[]) 
{
	int i=0, j=0; 
	char temp; 
	strcpy(target, ""); 
	
	while(source[i] != '\0') // when source is not empty
	{
		if( source[i]=='(' )
		{
			push(numberStack, source[i]);   
			i++;  
		}
		else if( source[i] == ')' )  
		{   
			while ( (top != -1) && ( numberStack[top] != '(' ) )   
			{    
				target[j] = pop(numberStack);    
				j++;   
			}   
			if (top == -1)   
			{    
				printf("\n INCORRECT EXPRESSION");
				// becuse a closing paranthesis cannot exit without an opening parenthesis   
				exit(1);
			}   
			temp = pop(numberStack); //remove left parenthesis   
			i++;
		}  
		else if( isdigit(source[i]) || isalpha(source[i]) )
		{   
			target[j] = source[i];   
			j++;   
			i++;  
		}  
		else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%')  
		{   
			while ((top != -1) && (numberStack[top] != '(') && (getPriority(numberStack[top]) > getPriority(source[i])))   
			{    
				target[j] = pop(numberStack);    
				j++;   
			}   
			push(numberStack, source[i]);   
			i++;  
		}  
		else
		{   
			printf("\n INCORRECT ELEMENT IN EXPRESSION");   
			exit(1);  
		} 
	} 
	while ((top != -1) && (numberStack[top] != '(')) 
	{  
		target[j] = pop(numberStack);  
		j++; 
	} 
	target[j]='\0'; 
} 

int getPriority(char op) 
{ 
	if(op == '/' || op == '*' || op =='%')  
		return 1; 
	else if(op == '+' || op == '–')  
		return 0; 
} 

void push(char numberStack[], char val) 
{ 
	if (top == MAX-1)  
		printf("\n STACK OVERFLOW"); 
	else 
	{  
		top++;  
		numberStack[top]=val; 
	} 
} 

char pop(char numberStack[]) 
{ 
	char val=' '; 
	
	if (top == -1)  
		printf("\n STACK UNDERFLOW"); 
	else 
	{  
		val=numberStack[top];  
		top--; 
	} 
	return val; 
}