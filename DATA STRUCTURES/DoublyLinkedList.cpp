/*DOUBLY LINKED LIST*/
/*

	IMPORTANT OPERATION
	===================
	
	1)	INSERTION 
	2)	DELETION
	3)	TRAVERSE
	
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev,*next;
};

struct node *start = NULL;

void insertAsFirstNode(int data)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data= data;
	temp->prev=NULL;
	temp->next=NULL;
	if(start==NULL)
		start=temp;
	else
	{
		start->prev = temp;
		temp->next = start;  
		start =temp;
	}
}

struct node* find(int data)
{
	//return the address of the exact node
	struct node *p=start;
		while(p)
		{
			if(p->data==data)
				return p;
			p=p->next;
		}
		return NULL;
}


void insertElementAfterNode(int data,int prevData)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
		struct node *p=find(prevData);
		//check whether the element is present in list or not
		
		if(p!=NULL)
		{
		temp->prev=p;
		temp->next=p->next;
		if(p->next!=NULL)
			p->next->prev=temp;
		p->next=temp;
		}
		else
		{
			printf("\ninvalid insertion");
		}
	}


void insertAsLastNode(int data)
{
	struct node *p=start,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	temp->data=data;
	if(start==NULL)
		start=temp;
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next= temp;
		temp->prev=p;
	}
}

void deleteFirstNode()
{
	struct node *temp;
	if(start == NULL)
		printf("\nLIST IS EMPTY");
	else
	{
		temp = start;
		start = start->next;
		start->prev=NULL; 
		free(temp);
		
	}
}

void deleteLastNode()
{
	struct node *temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->prev->next=NULL;
	free(temp);
}

void deleteAfter(int data)
{
	struct node *p =find(data);
	if(p==NULL)
	printf("\nNO SUCH ELEMENT");
	else if(p->prev==NULL){
		start = p->next;
		free(p);
	}
	else if(p->next==NULL){
		p->prev->next=p->next;
		free(p);
	}
	else
	{ 
		p->next->prev=p->prev;
		p->prev->next=p->next;
		free(p);  
	}
}
void viewList()
{
	struct node*t;
	if(start==NULL)
	printf("\nLIST IS EMPTY");
	else
	{
		printf("\n");
		t=start;
		while(t)
		{
			printf("%d\t",t->data);
			t=t->next;
		}
	}
}

int main()
{
	insertAsFirstNode(5);
	insertAsFirstNode(6);
	insertAsFirstNode(7);
	viewList();
	deleteFirstNode();
	deleteFirstNode();
	viewList();
	insertAsLastNode(1);
	insertAsLastNode(2);
	insertAsLastNode(3);
	viewList();
	insertElementAfterNode(100,1);
	insertElementAfterNode(200,2);
	insertElementAfterNode(300,3);
	viewList();
	deleteLastNode();
	deleteLastNode();
	deleteLastNode();
	viewList();
	deleteAfter(5);
	viewList();
	deleteAfter(1);
	deleteAfter(100);
	deleteAfter(200);
	viewList();
}
