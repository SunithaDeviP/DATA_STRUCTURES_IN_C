/*QUEUE USING ARRAYS*/

#include<stdio.h>
#define capacity 5
int queue[capacity];
int front=0,rear=0;

int isFull()
{
	if(rear==capacity)
	return 1;
	return 0;
}

int isEmpty()
{
	if(rear==front)
	return 1;
	else
	return 0;
}
void insert(int x)
{
	if(!isFull())
	queue[rear++]=x;
	else
	printf("\nQUEUE IS FULL");
}

void delete_()
{
	if(!isEmpty())
	front++;
	else
	printf("\nQUEUE IS EMPTY");
}

void display()
{
	printf("\n");
	for(int i=front;i<rear;i++)
	{
		printf("%d\t",queue[i]);
	}
}
int main()
{
	insert(1);
	insert(1);
	insert(1);
	insert(1);
	insert(1);
	//insert(1);

	display();
	delete_();
	delete_();
	delete_();
	delete_();
	delete_();
//	delete_();
	display();
}
