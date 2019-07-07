/*IMPLEMENTATION OF STACK USING STATIC MEMORY ALLOCATION
*	
*	1)	push()
*	2)	pop()
*	3)	create()
*	4)	traverse()	
*	5)	isEmpty()
*	6)	isFull()
*	7)	size()
*
*
*/

#include<stdio.h>
#define capacity 5

int stack[capacity],top=-1;

int isFull()
{
	if(top==capacity)
	return 1;
	return 0;
}

int isEmpty()
{
	if(top==-1)
	return 1;
	return 0;
}
void push(int element)
{
	if(!isFull())
	stack[++top]=element;
	else
	printf("\nSTACK IS FULL");
}

void pop()
{
	if(!isEmpty())
	top--;
	else
	printf("\nSTACK IS EMPTY");	
}

void size()
{
	printf("\nsize of stack is %d",top);
}
void traverse()
{
	printf("\n");
	for(int i=0;i<top;i++)
	printf("%d\t",stack[i]);
}
int main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	size();
	traverse();
	pop();
	pop();
	size();
	traverse();
}
