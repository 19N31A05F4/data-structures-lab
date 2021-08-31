#include<iostream>
using namespace std;
#include<stdlib.h>
template <class T>
struct dnode
{
	T data;
	struct dnode<T> *prev;
	struct dnode<T> *next;
};
// ADT for doubly linked list
template <class T>
class dlist
{
public:
	int data;
	struct dnode<T>*head;
	dlist();
	struct dnode<T>*create_dnode(int n);
	void insert_front();
	void insert_end();
	void Insert_at_pos(int pos);
	void delete_front();
	void delete_end();
	void Delete_at_pos(int pos);
	int dnode_count();
	void display();
};
template <class T>
dlist<T>::dlist()
{
	head=NULL;
}
template <class T>
struct dnode<T>*dlist<T>::create_dnode(int n)
{
	struct dnode<T> *t;
	t=new struct dnode<T>;
	t->data=n;
	t->next=NULL;
	t->prev=NULL;
	return t;
}
template <class T>
void dlist<T>::insert_front()
{
struct dnode <T>*t,*temp;
	cout<<"Enter data into dnode:";
	cin>>data;
	temp=create_dnode(data);
	if(head==NULL)
		head=temp;
	else
	{ 
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
}
template <class T>
void dlist<T>::insert_end()
{
struct dnode<T> *t,*temp;
int n;
	cout<<"Enter data into dnode:";
	cin>>n;
	temp=create_dnode(n);
	if(head==NULL)
		head=temp;
	else
	{ 
		t=head;
		while(t->next!=NULL)
			t=t->next;
		t->next=temp;
		temp->prev=t;
	}
}
template <class T>
void dlist<T>::Insert_at_pos(int pos)
{
struct dnode<T>*cr,*pr,*temp;
int c=1;
	cout<<"Enter data into dnode:";
	cin>>data;
	temp=create_dnode(data);
	display();
	if(head==NULL)
	{
		//when list is empty
		head=temp;
	}
	else
	{ 
		int nc;
		nc=dnode_count();
		if(pos>nc)
		{
			cout<<"Invalid position";
			cout<<"Enter a value from 1 to "<<nc<<endl;
		}
		else
		{
			pr=cr=head;
			if(pos==1)
			{ //inserting at pos=1
					temp->next=head;
					head->prev=temp;
					head=temp;
			}
			else
			{
					while(c<pos)
					{ 
						c++;
						pr=cr;
						cr=cr->next;
					}
					pr->next=temp;
					temp->prev=pr;
					temp->next=cr;
					cr->prev=temp;
				}
			}
		}	
}
template <class T>
void dlist<T>:: delete_front()
{
struct dnode<T>*t;
	if(head==NULL)
		cout<<"List is Empty\n";
	else
	{ 
		display();
		t=head;
		head=head->next;
		head->prev=NULL;
		cout<<"dnode "<<t->data<<" Deletion is sucess";
		delete(t);
	}
}
template <class T>
void dlist<T>::delete_end()
{
struct dnode<T>*pr,*cr;
	pr=cr=head;
	if(head==NULL)
	cout<<"List is Empty\n";
	else
	{ 
		cr=pr=head;
		if(head->next==NULL)
		{
			cout<<"dnode "<<cr->data<<" Deletion is sucess";
			delete(cr);
			head=NULL;
		}
		else
		{ 
			while(cr->next!=NULL)
			{ 
				pr=cr;
				cr=cr->next;
			}
			pr->next=NULL;
			cout<<"dnode "<<cr->data<<" Deletion is sucess";
			delete(cr);
		}
	}
}
template <class T>
void dlist<T>::Delete_at_pos(int pos)
{
struct dnode<T>*cr,*pr,*temp;
int c=1;
	display();
	if(head==NULL)
	{
		cout<<"List is Empty\n";
	}
	else
	{
		 pr=cr=head;
		if(pos==1)
		{    
			head=head->next;
			head->prev=NULL	;
			cout<<cr->data <<"is deleted sucesfully";
			delete cr;
		}
		else
		{
		while(c<pos)
		{
			pr=cr;
			cr=cr->next;
			c++;
		}
		pr->next=cr->next;
		cr->next->prev=pr;
		cout<<endl<<cr->data <<"is deleted sucessfully";
		delete cr;
		}
	}

}

template <class T>
int  dlist<T>::dnode_count()
{
struct dnode<T>*t;
	int count=0;
	display();
	t=head;
	if(head==NULL)
		cout<<"List is Empty\n";
	else
	{ 
		while(t!=NULL)
		{ 
			count++;
			t=t->next;
		}
	return count;
	}
}
template <class T>
void dlist<T>::display()
{
struct dnode<T>*t;
	if(head==NULL)
	{
		cout<<"List is Empty\n";
	}
	else
	{ 
		cout<<"Nodes in the linked list are ...\n";
		t=head;
		while(t!=NULL)
		{ 
			cout<<t->data<<"<=>";
			t=t->next;
		}
	}
}
int main()
{
int ch,pos;
dlist <int> DL;
	while(1)
	{
	cout<<"\n***Operations on Doubly List***"<<endl;
	cout<<"1.Insert dnode at End"<<endl;
	cout<<"2.Insert dnode at Front"<<endl;
	cout<<"3.Delete dnode at END"<<endl;
	cout<<"4.Delete dnode at Front"<<endl;
	cout<<"5.Display nodes "<<endl;
	cout<<"6.Count Nodes"<<endl;
	cout<<"7.Insert at a position "<<endl;
	cout<<"8.Delete at a position "<<endl;
	cout<<"9.Exit "<<endl;
	cout<<"10.Clear Screen "<<endl;
	cout<<"Enter Your choice:";
	cin>>ch;
	switch(ch)
	{
	case 1: DL.insert_end();
			break;
	case 2: DL.insert_front();
			break;
	case 3:DL.delete_end();
			break;
	case 4:DL.delete_front();
			break;
	case 5://display contents
			DL.display();
			break;
	case 6: cout<<"Node count is "<<DL.dnode_count();
			break;
	case 7: cout<<"Enter position to insert";
			cin>>pos;
			DL.Insert_at_pos(pos);
			break;
	case 8: cout<<"Enter position to Delete";
			cin>>pos;
			DL.Delete_at_pos(pos);
			break;
	case 9:exit(0);
	case 10:system("cls");//windows cls,  linux clear
		  break;
	default:cout<<"Invalid choice";
	}
}
}
