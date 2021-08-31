#include<iostream>
using namespace std;
template <class T>
struct cnode
{
T data;
struct cnode<T> *link;	
};

template <class T>
class clist
{
	int data;
	struct cnode<T>*head;
	public:
		clist()
		{
			head=NULL;
		}
void display()
{
	struct cnode<T>*t;
	if(head==NULL)
	{
			cout<<"clist is Empty\n"; 
	}
	 else
	 {	t=head;
		while(t->link!=head)
		{	cout<<t->data<<"->";
			t=t->link;
		}
		cout<<t->data<<"->";
	 }
}
struct cnode<T>*create_cnode(int n)
{
struct cnode<T> *t;
	t=new struct cnode<T>;
	t->data=n;
	t->link=NULL;
return t;
}

void insert_end()
{
struct cnode<T> *t,*temp;
int n;
	cout<<"Enter data into cnode:";
	cin>>n;
	temp=create_cnode(n);	
	if(head==NULL)
	{
		head=temp;
		temp->link=temp;
	}
	else
	{	t=head;
		while(t->link!=head)
		{	
			t=t->link;
		}
		t->link=temp;	
		temp->link=head;
	}
}	
void insert_front()
{
struct cnode <T>*t,*temp;
	cout<<"Enter data into cnode:";
	cin>>data;
	temp=create_cnode(data);	
	if(head==NULL)
	{
		head=temp;
		temp->link=temp;
	}
	else
	{	
		t=head;
		//code to find last node 
		while(t->link!=head)
		{	
			t=t->link;
		}
		temp->link=head;
		head=temp;
		t->link=temp;	//linking last and first node
	}	
}
void delete_end()
{
struct cnode<T>*cur,*prev;
	cur=prev=head;
	if(head==NULL)
		cout<<"clist is Empty\n";
	else
	{	cur=prev=head;
		if(head->link==NULL)
		{
			cout<<"cnode "<<cur->data<<" Deletion is success";
			delete(cur);	
			head=NULL;
		}
		else
		{	while(cur->link!=head)
			{	prev=cur;
				cur=cur->link;
			}
			prev->link=head;//points to head
			cout<<"cnode "<<cur->data<<" Deletion is success\n";
			delete(cur);
		}
	}
}
void delete_front()
{
struct cnode<T>*t1,*t2;
	if(head==NULL)
		cout<<"clist is Empty\n";
	else
	{	
	
		if(head->link==head)
		{
			t1=head;	
			cout<<"cnode "<<t1->data<<" Deletion is success\n";
			delete(t1);
			head=NULL;		
		}
		else
		{
			t1=head;
			t2=head;
			//code to find last node 
			while(t2->link!=head)
			{	
				t2=t2->link;
			}
			head=head->link;//updating head
			t2->link=head;//point to first node;	
			cout<<"cnode "<<t1->data<<" Deletion is success\n";
			delete(t1);
			}
	}
	cout<<"Current List of Nodes\n";
	display();
}
int cnode_count()
{
struct cnode<T>*t;
int c=1;
	t=head;
	 if(head==NULL)
	 	cout<<"clist is Empty\n"; 
	 else
	 {	
	cout<<"Current List of Nodes\n";
	 display();
	 cout<"\n";
	 while(t->link!=head)
		{	c++;
			t=t->link;
		}
		return c;
	 }
}
void Insert_at_pos(int pos)
{struct cnode<T>*cur,*prev,*temp;
int c;
	if(head==NULL)
		cout<<"clist is Empty\n"; 
	 else
	 {  
		if(pos==1)
		{	
			cout<<"Enter data into node:";
			cin>>data;
			temp=create_cnode(data);
			prev=cur=head;
			//update last node pointer
			while(cur->link!=head)
			{
			 prev=cur;
			 cur=cur->link;	
			}
			cur->link=temp;//Allowing it to point to first node
			//updating at front
			temp->link=head;
			head=temp;
		}
		else
		{	c=1;
			prev=cur=head;
			while(c<pos)
			{	c++;
				prev=cur;
				cur=cur->link;
			}
			cout<<"Enter data into Node:";
			cin>>data;
			temp=create_cnode(data);	
			prev->link=temp;
			temp->link=cur;
		}
	}
}
void Delete_at_pos(int pos)
{
struct cnode<T>*cur,*prev,*t,*temp;
int c=1;
	 if(head==NULL)
	 {
			cout<<"circular list is Empty\n"; 
	 }
	 else
	 {  prev=cur=t=head;
		if(pos==1)
		{
			if(head==head->link)//single node case
			{
				cout<<t->data <<" is deleted successfully\n";
				delete t;
				head=NULL;
			}
			else
			{
			 //update last node pointer
			while(cur->link!=head)
			{
			 prev=cur;
			 cur=cur->link;	
			}
		    head=head->link;
			cur->link=head;
			cout<<t->data <<"is deleted successfully\n";
		    delete t;
			}	
		}
		else
		{
			while(c<pos)
			{	c++;
				prev=cur;
				cur=cur->link;
			}
			prev->link=cur->link;
			cout<<cur->data <<"is deleted successfully\n";
			delete cur;
		}
	 }
	 cout<<"Current List of Nodes\n";
	display();
}


};
int main()
{
int ncount,ch,pos;
clist <int> L;
	while(1)
	{
		cout<<"\n ***Operations on Circular Linked clist***"<<endl;
		cout<<"\n1.Insert node at End"<<endl;
		cout<<"2.Insert node at Front"<<endl;
		cout<<"3.Delete node at END"<<endl;
		cout<<"4.Delete node at  Front"<<endl;
		cout<<"5.Display nodes "<<endl;
		cout<<"6.Node Count"<<endl;	  
		cout<<"7.Insert at a position "<<endl;
		cout<<"8.Delete at a position "<<endl;
		cout<<"9.Exit "<<endl;
		cout<<"10.Clear Screen "<<endl;
		cout<<"Enter Your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:	L.insert_end();
					break;
			case 2:	L.insert_front();
					break;	
			case 3:L.delete_end();
					break;	
			case 4:L.delete_front();
					break;	
			case 5://display contents
					L.display();
					break;
			case 6: ncount=L.cnode_count();
					cout<<"\nNode count is "<<ncount<<endl;
					break;
			case 7: cout<<"Enter position to insert:";
					cin>>pos;
					L.Insert_at_pos(pos);
					break;
			case 8: cout<<"Enter position to Delete:";
					cin>>pos;
					L.Delete_at_pos(pos);
					break;
			case 9:exit(0);
			case 10:system("cls");//clear for Linux
					break;
			default:cout<<"Invalid choice";
		}
	}
}