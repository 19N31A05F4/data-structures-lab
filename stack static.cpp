#include<stdlib.h>
#include<iostream>
using namespace std;
#define max 4
template<class T>
class stack
{
private:
int top;
T stk[max],data;
public:
 stack();
void push();
void pop();
void display();
};

template<class T>
stack<T>::stack()
{
top=-1;
}
template<class T>
void stack<T>::push()
{ if(top==max-1)
cout<<"Stack Overflow...\n";
else
{ cout<<"Enter an element to be pushed:";
top++;
cin>>data;
stk[top]=data;
cout<<"Pushed Sucesfully.......\n";
}
}
template<class T>
void stack<T>::pop()
{
if(top==-1)
cout<<"Stack is Underflow";
else
{
data=stk[top];
top--;
cout<<data<<" is poped Sucesfully....\n";
 }
}
template<class T>
void stack<T>::display()
{
if(top==-1)
cout<<"Stack Under Flow";
else
{
cout<<"Elements in the Stack are....\n";
for(int i=top;i>-1;i--)
{
cout<<stk[i]<<"\n";
}
}
}
int main()
{
int choice;
stack <int>st;
while(1)
{
cout<<"\n*****Menu for Stack operations*****\n";
cout<<"1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n";
cout<<"Enter Choice:";
cin>>choice;
switch(choice)
{
case 1: st.push();
break;
case 2: st.pop();
break;
case 3: st.display();
break;
case 4: exit(0);
default:cout<<"Invalid choice...Try again...\n";
}
}
}

