#include<iostream>
using namespace std;
template <class T>
struct node
{
    T data;
    struct     node<T>*next;
};
template <class T>
class queue
{
    T item;
    node<T> *front,*rear;
public:
    queue();
    void EnQueue();
    void DeQueue();
    void Display();
};
template <class T>
queue<T>::queue()
{
    front=rear=NULL;
}
template <class T>
void queue<T>::EnQueue()
{
node<T>*p;
    cout<<"Enter an element to be inserted:";
    cin>>item;
    p=new node<T>;
    p->data=item;
    p->next=NULL;
    if(front==NULL)
    {
        rear=front=p;
    }
    else
    {
        rear->next=p;
        rear=p;
    }
    cout<<"\nInserted into Queue Sucesfully ... \n";
}
template <class T>
void queue<T>::DeQueue()
{
node<T>*t;
    if(front==NULL)
        cout<<"\nQueue is Underflow";
    else
    {
        item=front->data;
        t=front;
        front=front->next;
        cout<<"\n"<<item<<" is deleted from Queue ... \n";
    }
delete(t);
}
template <class T>
void queue<T>::Display()
{
node<T>*t;
    if(front==NULL)
        cout<<"\nQueue Under Flow";
    else
    {
        cout<<"\nElements in the Queue are ... \n";
        t=front;
        while(t!=NULL)
        {
        cout<<"|"<<t->data<<"|<-";
        t=t->next;
        }
    }
}
int main()
{
int choice;
queue<int>q1;
    while(1)
    {
        cout<<"\n\n***Menu for operations on Queue***\n\n";
        cout<<"1.Insert\n2.Delete\n3.DISPLAY\n4.EXIT\n";
        cout<<"Enter Choice:";
        cin>>choice;
        switch(choice)
        {
        case 1: q1.EnQueue();
            break;
        case 2: q1.DeQueue();
            break;
        case 3: q1.Display();
            break;
        case 4: exit(0);
        default: cout<<"Invalid choice...Try again...\n";
        }
    }
}
