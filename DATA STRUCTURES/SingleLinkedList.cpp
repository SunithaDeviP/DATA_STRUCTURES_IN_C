/*SINGLY LINKED LIST*/


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};
struct node *root = NULL;

void traverse()
{
	system("cls");
	printf("\n");
	struct node *temp;
	
	temp=root;
	if(temp==NULL)
	{
		printf("\nNO ELEMENTS TO DISPLAY ");
		
	}
	else
	{
	
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->link;
	}
}
}

void addDataAtBegin()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the element : ");
	scanf("%d",&temp->data);
	temp->link =NULL;
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
	temp->link = root;
	root=temp;
	}
	traverse();
}
int length()
{
	int len=0;
	struct node* temp;
	temp=root;
	while(temp !=NULL)
	{ 
	len++;  
		temp=temp->link;
		
	}
	
	return len;
}
void append()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the data : ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		struct node *next;
		next=root;
		while(next->link != NULL)
		{
			next=next->link;
		}
		next->link=temp;
	}
	traverse();
}


void addAfter()
{
	int location;
	struct node*temp,*p;
	printf("\nENER THE LOCATION : ");
	scanf("%d",&location);
	int len =length();
	if(location>len)
	{
		printf("\nINVALID LOCATION\n");
		printf("\nCURRENTLY LIST IS HAVING %d\n",len);
	}
	else{
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nENTER THE ELEMENT TO BE ADDED : ");
	scanf("%d",&temp->data);
	p=root;
	int i=0;
	while(i<location)
	{
		p=p->link;
		i++;
	}
	temp->link = p->link;
	p->link=temp;
	}
	traverse();
}

void deleteAtEnd()
{
		int loc;
		if(root==NULL)
		{
			printf("\nNO ELEMENT TO DELETE ");
		}
		else
		{
			struct node*temp;
			int len = length();
			if(len ==1)
			{
				temp = root;
				root = NULL;
				free(temp);
			}
			else
			{
				temp = root;
				int i=1;
				while(i<len-1){
					temp=temp->link;
					i++;
				}
				struct node *p = temp->link;
				temp->link = NULL;
				free(p);
			}
			traverse();
		}
		
}

void deleteAtBegin()
{
	struct node*temp;

		if(root ==NULL)
		{
			printf("\nNO ELEMENT TO DELETE");		
		}
		else
		{
				
		temp=root; 
		root=temp->link;
		temp->link= NULL;
		traverse();
	}
		
}

void deleteAtMiddle()
{
	struct node *p=root,*q;
		int i=1;
		if(root == NULL)
		{
			printf("\nNo Element to delete ");
		}
		else
		{
			int loc ;
			printf("\nEnter the location ");
			scanf("%d",&loc);
		while(i<loc-1)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);
		traverse();
		}
}
void swap(int data1,int data2)
{
	//THREE CASES POSSIBLE 
	/*
		CASE 1 : ANYONE NODE IS A START NODE
		CASE 2 : ANYONE NODE IS A LAST NODE
		CASE 3 : BOTH THE NODES ARE INTERMEDIATE NODES
	*/
	struct node *p,*prev,*pX,*pY,*prevX,*prevY;
	p=root;
	prev = NULL;
	while(p!=NULL && p->data!=data1)
	{
		prev=p;
		p=p->link;
	}
	pX=p;
	prevX=prev;
	p=root;
	prev=NULL;
	
	while(p!=NULL && p->data!=data2)
	{
		prev=p;
		p=p->link;
	}
	pY=p;
	prevY=prev;
	
	if(pX==NULL ||pY==NULL)
	return;
	if(prevX!=NULL)
		prevX->link=pY;
	else
		root=pY;
	
	if(prevY!=NULL)
		prevY->link = pX;
	else
		root=pX;
		
	struct node*temp = pX->link;
	pX->link = pY->link;
	pY->link=temp;
}

void reverse()
{
	struct node *current=root,*prev=NULL,*next=NULL;
	while(current)
	{
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	root = prev;
}
int main()
{
	int choice;
	while(1)
	{
		
		printf("\n\nSingle Linked List Operations : \n\n");
		printf("1. Append\n");
		printf("2. Add Data At Begin\n");
		printf("3. Add Data After The Element\n");
		printf("4. Length\n");
		printf("5. DeleteAtBegin\n");
		printf("6. DeleteAtMiddle\n");
		printf("7. DeleteAtEnd\n");
		printf("8. Traverse\n");
		printf("9. Swap Two Elements\n");
		printf("10.Reverse Single Linked List");
		printf("11.Quit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	append();break;
			case 2:	addDataAtBegin();break;
			case 3:	addAfter();break;
			case 4:	length();printf("\nLength = %d",length());break;
			case 5: deleteAtBegin();break;
			case 6: deleteAtMiddle();break;
			case 7:	deleteAtEnd();break;
			case 8: traverse();break;
			case 9: swap(1,2);break;
			case 10: reverse();break;
			case 11:	exit(1);break;
			default : printf("\nINVALID CHOICE");
		}
	}
}
