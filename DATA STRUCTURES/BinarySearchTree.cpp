#include<stdio.h>
#include<stdlib.h>
/*
OPERATIONS ON BST
=================

1) INSERT
2) DELETE
	-> deleting a leaf node (node with no child)
	-> deleting a leaf node (node with one cild)
	-> deleting a node which has two child
		=> replace the node with the highest value in a left subtree
		=> replace the node with the lowest value in the right subtree
3) TRAVERSE (inorder,preorder,postorder)

*/

#include<stdio.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node *root = NULL;

void insert(int data)
{
	struct node *temp, *parent = root;
	temp= (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left =NULL;
	temp->right =NULL;
	if(root==NULL) //if there are no elements in the tree
	{
		root = temp;
	}
	else 
	{
		struct node *current;
		current = root;//current used for traversing the node
		while(current)
		{
			parent =current;//parent is the parent of the node that has to be inserted
			if(temp->data > current->data)
			{
				current = current->right;
			}
			else 
			{
				current = current->left;
			}
			
		}
		if(temp->data > parent->data)
		parent->right = temp;
		else
		parent->left =temp;
	}
}

void delete_(int target)
{
	struct node *current, *parent;
	parent = root;
	current = root;
	while(current->data != target)
	{
		printf("\ndata = %d",current->data);
		parent = current;
		if(target  > current->data) 
		current= current->right;
		else
		current = current->left;
		printf("\ncurrent = %d\tparent = %d",current,parent);
	} 
	if(current->left == NULL && current->right==NULL)
	{
	if(current == parent->right )
		parent->right =NULL;
	else if(current == parent->left )
		parent ->left = NULL;
	}
	else if((current ->left !=NULL && current->right==NULL) || (current->right!=NULL && current->left==NULL) )
	{
		if(current->left !=NULL)
		{
			if(current==parent->right)
				parent->right = current->left;
			else
				parent->left = current->left;
			
			current->left=NULL;
		}
		else if(current->right!=NULL)
		{
			if(current==parent->right)
				parent->right =current->right;
			else
				parent->left = current->right;
				
			current->right=NULL;
		}
		free(current);
	}
	else
	{
		//assigning least value of right subtree 
		struct node *temp1,*temp2;
		temp1=current->right;
		if(temp1)
		{
		if(temp1->left == NULL && temp1->right ==NULL)
		{
			current->data = temp1->data;
			current->right=NULL;
			free(temp1);
		}
		else if(temp->left==NULL &&temp->right!= NULL)
		{
			current->data =temp1->data;
			current->right=temp1->right;
		}
		}
		else
		{
			
		}
	
	}
}

void nodeWithSingleChild(int target)
{
	
}
int main()
{
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	delete_(3);
}
