// evaluation of postfix using stacks

#include <stdio.h> 
#include <conio.h> 
#include <ctype.h> 
#define MAX 100 

float numberStack[MAX]; 
int top = -1; 

void push(float numberStack[], float val); 
float pop(float numberStack[]); 
float evaluatePostfixExp(char expression[]); 

int main() 
{ 
	float expValue;
	char expression[100];
	printf("\nEnter any postfix expression : ");
	gets(expression);

	expValue = evaluatePostfixExp(expression);
	printf("\nValue of the postfix expression = %.2f", expValue);
	getch();
	return 0;
} 

float evaluatePostfixExp(char expression[]) 
{ 
	int i=0; 
	float op1, op2, value; 
	
	while(expression[i] != '\0') 
	{  
		if(isdigit(expression[i])) {
			// since an expression has both numeric values and operators
			// first need to check whether the element is a digit or not
			push (numberStack, (float)(expression[i]-'0')); 
		}
		else  
		{   
			// when the element is not a digit, pop top two digits from the stack
			op2 = pop(numberStack);   
			op1 = pop(numberStack);   
			
			switch(expression[i])   
			{    
				case '+':     
					value = op1 + op2;     
					break;    
				case '–':     
					value = op1 - op2;     
					break;    
				case '/':     
					value = op1 / op2;     
					break;    
				case '*':     
					value = op1 * op2;     
					break;    
				case '%':     
					value = (int)op1 % (int)op2;     
					break;   
			}
			// push the calculated value back into the stack
			push(numberStack, value); 
		}  
		i++; 
	} 
	return(pop(numberStack)); 
} 

void push(float numberStack[], float val) 
{ 
	if (top == MAX-1)  
		printf("\nSTACK OVERFLOW"); 
	else 
	{  
		top++;  
		numberStack[top]=val; 
	} 
} 

float pop(float numberStack[]) 
{ 
	float val = -1; 
	if (top == -1)  
		printf("\n STACK UNDERFLOW"); 
	else 
	{  
		val=numberStack[top];  
		top--; 
	} 
	return val; 
}