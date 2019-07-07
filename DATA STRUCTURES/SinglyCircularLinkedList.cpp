/*singly circular linked list*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

struct node *last =NULL;

void display()
{
	printf("\n");
	if(last==NULL)
		printf("\nLIST IS EMPTY");
	else 
	{
		struct node *p=last->next;
		do
		{
			printf("%d\t",p->data);
			p=p->next;
		}while(p!=last->next);
	}
}
void addToEmpty(int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=temp;
	last=temp;
	
}
void addAtBegin(int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;

		temp->next = last->next;
		last->next=temp;
	
}

void addAtEnd(int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=last->next;
	last->next=temp;
	last = temp;
}

void addAfter(int after,int data)
{
	struct node *temp,*p=last->next;
	do{
	if(p->data==data)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=data;
		temp->next=p->next;
		p->next=temp;
		if(p==last)
			last=temp;
		break;
	}
	p=p->next;	
	}while(p->next!=last->next);
}


int main()
{
	addToEmpty(1);
	for(int i=1;i<=5;i++)
	addAtBegin(i);
	display();
	for(int i=6;i<=10;i++)
	addAtEnd(i);
	display();
	addAfter(100,1);
	addAfter(100,2);
	display();
}
