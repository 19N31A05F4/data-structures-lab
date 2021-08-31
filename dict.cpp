#include<stdlib.h>
#include<iostream>
using namespace std;
class node
{
public: int key;
	int value;
	node*next;
};
class dictionary:public node
{	
int k,data;
	node *head;
public: dictionary();
	void insert_d( );
	void delete_d( );
	void display_d( );
	void search();
};
dictionary::dictionary( )
{	
	head=NULL;
}
//code to push an val into dictionary;
void dictionary::insert_d( )
{ 
node *p,*curr,*prev;
    cout<<"Enter an key and value to be inserted:";
    cin>>k;
    cin>>data;
    p=new node;
    p->key=k;
    p->value=data;
    p->next=NULL;
    if(head==NULL)
      head=p;
    else
    { //inserting pair before head node
		curr=head;
    	if(p->value<head->value)
    	{
			p->next=head;
    		head=p;
    	}
		else
		{	// checking list to find appropriate location
			while((curr->key<p->key)&&(curr->next!=NULL)) 
	      	{	
		   	prev=curr;
	         curr=curr->next;
	      	}
			      	
			if(curr->next==NULL)
	      	{
	      		//inserting at end of the list	
				if(curr->key<p->key)
			    { 
					curr->next=p;
				  	prev=curr;
		      	}
			else
				{ 
				//inserting at a location other than end  of the list	
					p->next=prev->next;
			    	prev->next=p;
		     	}
	        } 
	    	else
	        { 
				p->next=prev->next;
	      		prev->next=p;
	    	}
	    }
		cout<<"\nInserted into dictionary Sucesfully....\n";	
	}
}
void dictionary::delete_d( )
{
node*curr,*prev;
	cout<<"Enter key value that you want to delete...";
	cin>>k;
	if(head==NULL)
		cout<<"\ndictionary is Underflow";
	else
	{
		curr=head;
		while(curr!=NULL)
		{
			if(curr->key==k)
				   break;
			prev=curr;
		   	curr=curr->next;
		}
	}
	if(curr==NULL)
		cout<<"Node not found...";
	else
	{
		if(curr==head)
			head=curr->next;
		else
			prev->next=curr->next;
	 	delete curr;
	 	cout<<"Item deleted from dictionary...";
	 }
}

void dictionary::search()
{
int val;
node*curr,*prev;
	cout<<"Enter value to be searched";
	cin>>val;
	if(head==NULL)
		cout<<"\ndictionary is Underflow";
	else
	{
		curr=head;
		while(curr!=NULL)
		{
			if(curr->value==val)
				   break;
			prev=curr;
		   	curr=curr->next;
		}
	}
	if(curr==NULL)
		cout<<"Node not found...";
	else
	{
		if(curr==head)
			head=curr->next;
		else
			prev->next=curr->next;
	 	cout<<"Value found\n";
	 	cout<<"<"<<curr->key<<","<<curr->value<<">"; 
	 }
}

void dictionary::display_d( )
{
node*t;
	if(head==NULL)
		cout<<"\ndictionary Under Flow";
	else
	{
		cout<<"\nElements in the dictionary are....\n";
		t=head;
	    while(t!=NULL)
		{
		  cout<<"<"<<t->key<<","<<t->value<<">";
		  t=t->next;
		}
	}
}
int main( )
{
int choice;
dictionary d1;
	while(1)
	{
	cout<<"\n\n***Menu for Dictrionay operations***\n\n";
	cout<<"1.Insert\n2.Delete\n3.Search a value \n4.DISPLAY\n5.EXIT\n";
	cout<<"Enter Choice:";
	cin>>choice;
	switch(choice)
	{
	case 1:	d1.insert_d();
			break;
	case 2:	d1.delete_d( );
			break;
	case 3:d1.search();	
			break;
	case 4:
			d1.display_d( );
			break;
	case 5:	exit(0);
	default:cout<<"Invalid choice...Try again...\n";
	}
   }
}

