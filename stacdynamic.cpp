#include<iostream>
using namespace std;
template<class T>
struct node
{
	T data;
	struct node<T>*link;
};
template<class T>
class stack
{
	int data;
	struct node<T>*top;
	public:
	 stack()
	 {
	 	top=NULL;
	 }
	 void display();
	 void push();
	 void pop();
};
template<class T>
void stack<T>::display()
{
	struct node<T>*t;
	if(top==NULL)
	  cout<<"stack is empty\n";
	else
	{
		t=top;
		while(t!=NULL)
	    {
  	    	cout<<"|"<<t->data<<"|"<<endl;
  	    	t=t->link;
		}
	}
}
template<class T>
void stack<T>::push()
{
  struct node<T>*t,*temp;
  cout<<"enter data into node:";
  cin>>data;
  temp=new struct node<T>;
  temp->data=data;
  temp->link=NULL;
  if(top==NULL)
    top=temp;
   else
   {
   	temp->link=top;
   	top=temp;
	}		
}
template<class T>
void stack<T>::pop()
{
	struct node<T>*t;
	if(top==NULL)
	   cout<<"stack is empty\n";
	   else
	   {
	   	t=top;
	   	top=top->link;
	   	cout<<"node"<<t->data<<"Deletion is success";
	   	delete(t);
	   }
}
int main()
{
	int ch;
	stack<int>st;
	while(1)
	{
		cout<<"\n*** Opeartions on Dynamic stack***"<<endl;
		cout<<"\n1.Push"<<endl;
		cout<<"2.Pop"<<endl;
		cout<<"3.Display"<<endl;
		cout<<"4.Exit"<<endl;
		cout<<"enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:st.push();
			       break;
		    case 2:st.pop();
		           break;
		    case 3:st.display();
			       break;
			case 4:exit(0);
			default:cout<<"Invalid choice";	          
		}
	}
}
