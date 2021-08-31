#include<iostream>
 using namespace std; 
#define max 4
template <class T>
 class CircularQ
 {    
 T cq[max];   
  int front,rear;
 public:    
 CircularQ();
 void insertQ();     
 void deleteQ();     
 void displayQ(); 
}; 
template <class T> 
CircularQ<T>::CircularQ()
 {    
 front=rear=-1; 
 } 
template <class T>
 void CircularQ<T>::insertQ() 
{ 
int num;  
 if(front==(rear+1)%max)    
 {           
  cout<<"Circular Queue is full\n";  
   }        
 else    
 {    
 cout<<"Enter an element";   
  cin>>num;   
  if(front==-1)     
    rear=front=0;   
  else       
  rear=(rear+1)%max;   
  cq[rear]=num;   
  cout<<num <<" is inserted ...";   
  } 
}
 template <class T> 
void CircularQ<T>::deleteQ()
 { 
int num;   
  if(front==-1)        
 cout<<"Queue is empty";    
 else     
{   
  num=cq[front];    
 cout<<"Deleted item is "<< num;    
 if(front==rear)        
 front=rear=-1;    
 else         
front=(front+1)%max;    
 } 
} 
template <class T> 
void CircularQ<T>::displayQ()
 { 
int i;    
 if(front==-1)        
 cout<<"Queue is empty";    
 else    
 {      
cout<<"Queue elements are\n";   
 for(i=front;i<=rear;i++)     
    cout<<cq[i]<<"\t";     }    
 if(front>rear)    
 {       
 for(i=front;i<max;i++)           
  cout<<cq[i]<<"\t";       
  for(i=0;i<=rear;i++)            
  cout<<cq[i]<<"\t";    
 } 
} 
int main() 
{ 
CircularQ<int> obj; 
int choice; 
    while(1) 
    {         
        cout<<"\n*** Circular Queue Operations***\n"; 
        cout<<"\n1.insert Element into CircularQ";      
        cout<<"\n2.Delete Element from CircularQ";       
        cout<<"\n3.Display Elements in CircularQ";        
        cout<<"\n4.Exit ";         
        cout<<"\nEnter Choice:";      
        cin>>choice;        
        switch(choice)        
       {             
	 case 1: obj.insertQ();                   
		  break;             
	 case 2: obj.deleteQ();                     
		  break;             
         case 3: obj.displayQ();             
	          break;            
	 case 4: exit(0);        
}     
}
}