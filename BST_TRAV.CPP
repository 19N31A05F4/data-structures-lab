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
	void display_bst();
	void preeorder(node*);
	void inorder(node*);
	void postorder(node*);
};
bst::bst()
{
root=NULL;
}
void bst::insert_node()
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
void bst::display_bst()
{
	if(root==NULL)
		cout<<"\nBinary Search Tree is Empty\n";
	else
	{
		int ch;
		cout<<"Binart Tree Traversals.....\n";
		cout<<"1.Pree order\n2.Inorder\n3:PostOrder\n";
		cout<<"Enter Your Chice:";
		cin>>ch;
		switch(ch)
		{
		case 1: cout<<"Pree order Tree Traversal\n ";
			preeorder(root);
			break;
		case 2: cout<<"Inorder Tree Traversal ";
			inorder(root);
			break;
		case 3: cout<<"Inorder Tree Traversal ";
			postorder(root);
			break;
		}


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
void bst::preeorder(struct node*t)
{
	if(t!=NULL)
	{
		cout<<" "<<t->data;
		preeorder(t->lchild);
		preeorder(t->rchild);
	}
}
void bst::postorder(struct node*t)
{
	if(t!=NULL)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		cout<<" "<<t->data;
	}
}
int main()
{
bst bt;
int i;
	while(1)
	{       cout<<"\n*** Binary Search Tree ***\n";
		cout<<"1.Insert Node\n2.display\n3.Clear Screen\n4.exit\n";
		cout<<"Enter Choice:";
		cin>>i;
		switch(i)
		{

			case 1:bt.insert_node();
					break;
				break;
			case 2:bt.display_bst();
				break;
			case 3:system("cls");
				break;
			case 4:exit(0);
			default:cout<<"Enter correct choice";
		}
	}
}

