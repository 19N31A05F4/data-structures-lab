#include<stdlib.h>
#include<iostream>
using namespace std;
#define max 4
template <class T>
class queue
{
T q[max],item;
int front,rear;
public: queue();
void insert_q();
void delete_q();
void display_q();
};
template <class T>
queue<T>::queue()
{
front=rear=-1;
}
template <class T>
void queue<T> ::insert_q()
{
    if(front>rear)
        front=rear=-1;
if(rear==max-1)
    cout<<"queue Overflow...\n";
else
{
    if(front==-1)
    front=0;
    rear++;
    cout<<"Enter an item to be inserted:";
    cin>>item;
    q[rear]=item;
    cout<<"inserted Sucesfully..into queue..\n";
}
}

 

template <class T>
void queue<T>::delete_q()
{
    if((front==-1&&rear==-1)||front>rear)
    {
    front=rear=-1;
    cout<<"queue is Empty .. \n";
    }
    else
    {
    item=q[front];
    front++;
    cout<<item<<" is deleted Sucesfully ... \n";
    }
}
template <class T>
void queue<T>::display_q()
{
    if((front==-1&&rear==-1)||front>rear)
    {
        front=rear=-1;
        cout<<"queue is Empty .. \n";
    }

 

    else
    {
        for(int i=front;i<=rear;i++)
        cout<<"|"<<q[i]<<"|<--";
    }
}
int main()
{
int choice;
queue<int> q;
while(1)
{
cout<<"\n\n*****Menu for operations on QUEUE*****\n\n";
cout<<"1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n";
cout<<"Enter Choice:";
cin>>choice;
switch(choice)
{
case 1: q.insert_q();
break;
case 2: q.delete_q();
break;
case 3: cout<<"Elements in the queue are ... \n";
q.display_q();
break;
case 4: exit(0);
default: cout<<"Invalid choice...Try again...\n";
}
}
}

