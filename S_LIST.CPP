#include<iostream>
#include<stdlib.h>
using namespace std;
template <class T>
struct node
{
	T data;
	struct node<T> *link;
};
template <class T>
class list
{
int item;
struct node<T>*head;
public:
	list();
	struct node<T>*create_node(int n);
	void insert_end();
	void insert_front();
	void Insert_at_pos(int pos);
	void delete_end();
	void delete_front();
	void Delete_at_pos(int pos);
	void search();
	int Node_count();
	void display();
};
template <class T>
list<T>::list()
{
	head=NULL;
}

template <class T>
struct node<T>* list<T>::create_node(int n)
{
	struct node<T>*t;
	t=new struct node<T>;
	t->data=n;
	t->link=NULL;
	return t;
}
template <class T>
void list<T>::insert_end()
{
struct node<T> *t,*temp;
int n;
	cout<<"Enter data into node:";
	cin>>n;
	temp=create_node(n);
	if(head==NULL)
		head=temp;
	else
	{
		t=head;
		while(t->link!=NULL)
			t=t->link;
		t->link=temp;
	}
}
template <class T>
void list<T>::insert_front()
{
struct node <T>*t,*temp;
	cout<<"Enter data into node:";
	cin>>item;
	temp=create_node(item);
	if(head==NULL)
		head=temp;
	else
	{
		temp->link=head;
		head=temp;
	}
}

template <class T>
void list<T>::Insert_at_pos(int pos)
{
struct node<T>*cur,*prev,*temp;
int c=1,nc;
	cout<<"Enter data into node:";
	cin>>item;
	temp=create_node(item);
	if(head==NULL)
		head=temp;
	else
	{
		nc=Node_count();
		if(pos>nc)
		{
			cout<<"Invalid position!!!!\n";
			cout<<"Try Positions from 1 to"<<nc;
		}
		else
		{
		prev=cur=head;
		if(pos==1)
		{
			temp->link=head;
			head=temp;
		}
		else
		{
			while(c<pos)
			{
				c++;
				prev=cur;
				cur=cur->link;
			}
			prev->link=temp;
			temp->link=cur;
		}
		}
	}
}
template <class T>
void list<T>::delete_end()
{
struct node<T>*cur,*prev;
	cur=prev=head;
	if(head==NULL)
		cout<<"List is Empty\n";
	else
	{ 
		cur=prev=head;
		if(head->link==NULL)
		{
			cout<<"node "<<cur->data<<" Deletion is sucess";
			free(cur);
			head=NULL;
		}
		else
		{ 
			while(cur->link!=NULL)
			{ 
				prev=cur;
				cur=cur->link;
			}
			prev->link=NULL;
			cout<<"node "<<cur->data<<" Deletion is sucess";
			free(cur);
		}
	}
}
template <class T>
void list<T>::delete_front()
{
struct node<T>*t;
	if(head==NULL)
		cout<<"List is Empty\n";
	else
	{
		t=head;
		head=head->link;
		cout<<"node "<<t->data<<" Deletion is sucess";
		delete(t);
	}
}
template <class T>
void list<T>::Delete_at_pos(int pos)
{
struct node<T>*cur,*prev,*temp;
int c=1,nc;
	if(head==NULL)
	{
		cout<<"List is Empty\n";
	}
	else
	{       nc=Node_count();
		if(pos>nc)
		{
		cout<<"Invalid position!!!!\n";
		cout<<"Try Positions from 1 to"<<nc;
		}
		else
		{
		prev=cur=head;
		if(pos==1)
		{
			head=head->link;
			cout<<cur->data <<"is deleted sucesfully";
			delete cur;
		}
		else
		{
			while(c<pos)
			{
				c++;
				prev=cur;
				cur=cur->link;
			}
			prev->link=cur->link;
			cout<<cur->data <<"is deleted sucesfully";
			delete cur;
		}
	}
	}
}
template <class T>
void list<T>::search()
{
int key,pos,loc,found=0;
struct node<T>*temp;
	cout<<"Enter value to be searched in the list";
	cin>>key;
	if(head==NULL)
		cout<<"List is empty\n";
	else
	{
		temp=head;
		pos=1;
		while(temp!=NULL)
		{
			if(temp->data==key)
			{
				found=1;
				loc=pos;
				break;
			}
			pos++;
			temp=temp->link;
		}
		if(found==1)
			cout<<"Key "<<key<<" is found at "<<loc;
		else
			cout<<"Key Not found in the list\n";
	}
}
template <class T>
int  list<T>::Node_count()
{
struct node<T>*t;
int c=0;
	t=head;
	if(head==NULL)
	{
		cout<<"List is Empty\n";
	}
	else
	{
		while(t!=NULL)
		{
			c++;
			t=t->link;
		}
	}
   return c;
}
template<class T>
void list<T>:: display()
{
struct node<T>*t;
	if(head==NULL)
	{
		cout<<"List is Empty\n";
	}
	else
	{
		t=head;
		while(t!=NULL)
		{
			cout<<t->data<<"->";
			t=t->link;
		}
	}
}
int main()
{
int ch,pos,ncount;
	list <int> L;
	while(1)
	{
		cout<<"\n*********************************\n";
		cout<<"|   Operations on Linked List   |";
		cout<<"\n*********************************\n";
		cout<<"\n1.Insert node at End"<<endl;
		cout<<"2.Insert node at Front"<<endl;
		cout<<"3.Delete node at End"<<endl;
		cout<<"4.Delete node at Front"<<endl;
		cout<<"5.Insert at a position "<<endl;
		cout<<"6.Delete at a position "<<endl;
		cout<<"7.Node Count"<<endl;
		cout<<"8.Search for a key in the list "<<endl;
		cout<<"9.Display nodes "<<endl;
		cout<<"10.Clear Screen "<<endl;
		cout<<"11.Exit "<<endl;
		cout<<"Enter Your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1: L.insert_end();
					break;
			case 2: L.insert_front();
					break;
			case 3:L.delete_end();
					break;
			case 4:L.delete_front();
					break;
			case 5: cout<<"Enter position to insert";
					cin>>pos;
					L.Insert_at_pos(pos);
					break;
			case 6: cout<<"Enter position to Delete a Node:";
					cin>>pos;
					L.Delete_at_pos(pos);
					break;
			case 7: ncount=L.Node_count();
				    cout<<"Nodes in the list="<<ncount<<endl;
					break;
			case 8: L.search();
					break;
			case 9: L.display();
					break;
			case 10:system("cls");
					break;
			case 11:exit(0);
			default:cout<<"Invalid choice";
		}
	}
 }

