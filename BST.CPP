#include<stdlib.h>
#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
	int data;
	struct	node*lchild;
	struct	node*rchild;
};

class bst
{
private:
	int item;
       struct node *root;
public: bst();
	void insert_node();
	void delete_node();
	void display_bst();
	void search();
	void inorder(node*);

};
bst::bst()
{
root=NULL;
}

void bst:: insert_node()
{
struct node *new_node,*curr,*prev;
	new_node=new (struct node);
	cout<<"Enter data into new node";
	cin>>item;
	new_node->data=item;
	new_node->lchild=NULL;
	new_node->rchild=NULL;
	if(root==NULL)
		root=new_node;
	else
	{
		curr=prev=root;
		while(curr!=NULL)
		{
			if(new_node->data>curr->data)
			{
				prev=curr;
				curr=curr->rchild;
			}
			else
			{
				prev=curr;
				curr=curr->lchild;
			}
		}
		cout<<"Prev:"<<prev->data<<endl;
		if(prev->data>new_node->data)
			prev->lchild=new_node;
		else
			prev->rchild=new_node;
		}
}
//code to delete a node
void bst::delete_node()
{
if(root==NULL)
	cout<<"Tree is Empty";
else
{
	int key;
	cout<<"Enter the key value to be deleted";
	cin>>key;
	struct node* temp,*parent=NULL,*succ_parent=NULL,*t;
	struct node*temp_succ;
	temp=root;
	while(temp!=NULL)
	{
			if(temp->data==key)
		{    //deleting node with two childern
		    if(temp->lchild!=NULL&&temp->rchild!=NULL)
			{ 	//search for sucessor

				temp_succ=temp->rchild;
				while(temp_succ->lchild!=NULL)
				{
					 succ_parent=temp_succ;
					 temp_succ=temp_succ->lchild;
				}
				temp->data=temp_succ->data;
				temp->rchild=NULL;/*???*/
				delete(temp_succ);
				succ_parent->lchild=NULL;
			       cout<<"Deleted sucess fully";
			       return;
			}
			//deleting a node having one left child
			if(temp->lchild!=NULL&temp->rchild==NULL)
			{
			  if(parent==NULL)
			  {
			  t=temp;
			  root=temp->lchild;
			  }
			  else
			  {
				  t=temp;
				  parent->rchild=temp->lchild;
			  }
			delete(t);
			cout<<"Deleted sucess fully";
			 return;
			}
		       //deleting a node having one right child
			if(temp->lchild==NULL&temp->rchild!=NULL)
			{
			if(parent==NULL)
			{
			temp_succ=temp->rchild;
			while(temp_succ->lchild!=NULL)
			{
			 succ_parent=temp_succ;
			 temp_succ=temp_succ->lchild;
			}
			temp->data=temp_succ->data;//verify
			if(temp_succ->lchild==NULL&&temp_succ->rchild==NULL)
			{
			if(succ_parent==NULL)
				temp->rchild=NULL;
			else
				succ_parent->lchild=NULL;
			}
			else
			{
			root->rchild=temp_succ->rchild;
			}
			//t=temp_succ;
			delete(temp_succ);
			cout<<"Deleted sucess fully";
			  return;
			}
			else
			{  //deleting non root node
			succ_parent=NULL;
			temp_succ=temp->rchild;
			while(temp_succ->lchild!=NULL)
			{
			 succ_parent=temp_succ;
			 temp_succ=temp_succ->lchild;
			}
			temp->data=temp_succ->data;
			if(temp_succ->lchild==NULL&&temp_succ->rchild==NULL)
			{

			   if(succ_parent!=NULL)
				  succ_parent->lchild=NULL;
			   else
			   temp->rchild=NULL;

			}
			else
			{
			temp->rchild=temp_succ->rchild;
			}
			//t=temp_succ;
			delete(temp_succ);
			cout<<"Deleted sucess fully";
			 return;
					}
			}
			 //deleting a node having no child
			if(temp->lchild==NULL&temp->rchild==NULL)
			{
			if(temp->data==root->data)
			{
				root=NULL;
				delete temp;
			}
			else
			{
			if(parent->lchild==temp)
				parent->lchild=NULL;
			else
				parent->rchild=NULL;

			delete(temp);
			cout<<"Deleted sucess fully";
			return;
			}
			}
		}
		else if(temp->data<key)
		       {
			       parent=temp;
			       temp=temp->rchild;
			}
		else if(temp->data>key)
			{
				parent=temp;
				temp=temp->lchild;
			}
	}//end while
  }//end if
 }//end delnode func



void bst::display_bst()
{
	if(root==NULL)
		cout<<"\nBinary Search Tree is Empty\n";
	else
	{
	 cout<<"Inorder Tree Traversal ";
	 inorder(root);
	}
}
void bst::inorder(struct node*t)
{
	if(t!=NULL)
	{
		inorder(t->lchild);
		cout<<" "<<t->data;
		inorder(t->rchild);
	}
}

void bst::search()
{
	if(root==NULL)
		cout<<"\nBinary Search Tree is Empty\n";
	else
	{
	int key;
	int found=0;
	struct node*curr;
		cout<<"Enter key";
		cin>>key;
		curr=root;
		while(curr!=NULL)
		{
			if(key==curr->data)
			{
			cout<<"Key "<<key<<" is found ";
			found=1;
			break;

			}
			else if(key>curr->data)
			{

				curr=curr->rchild;
				found=0;
			}
			else
			{
			    curr=curr->lchild;
			    found=0;
			}

		}

	     if(found==0)
		cout<<"Element not Found\n";

	}
}
int main()
{
bst bt;
int i;
	while(1)
	{       cout<<"\n*** Binary Search Tree ***\n";
		cout<<"1.Insert Node\n2.Delete Node\n3.display\n4.Search\n";
		cout<<"5.Clear Screen\n6.exit\n";
		cout<<"Enter Choice:";
		cin>>i;
		switch(i)
		{

			case 1:bt.insert_node();
					break;
			case 2:bt.delete_node();
				break;
			case 3:bt.display_bst();
				break;
			case 4:bt.search();
				break;

			case 5:system("cls");
				break;
			case 6:exit(0);
			default:cout<<"Enter correct choice";
		}
	}
}

