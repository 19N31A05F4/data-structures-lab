#include<iostream>
using namespace std;
int Lsearch(int list[ ],int n,int key);
int main()
{
int n,i,key,list[50],pos;
	cout<<"enter no of elements\n";
	cin>>n;
	cout<<"enter "<<n<<" elements ";
	for(i=0;i<n;i++)
	cin>>list[i];
	cout<<"enter key to search";
	cin>>key;
	pos=Lsearch(list,n,key);
	if(pos==-1)
		cout<<"\nelement not found";
	else
		cout<<"\n element found at index "<<pos;
}
int Lsearch(int list[ ],int n,int key)
{
int i,pos=-1;
	for(i=0;i<n;i++)
		if(key==list[i])
		{
			pos=i;
			break;
		}
		return pos;
}
