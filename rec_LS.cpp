#include<iostream>
using namespace std;
int Rec_Lsearch(int list[ ],int n,int key);
int main()
{
int n,i,key,list[25],pos;
	cout<<"enter no of elements\n";
	cin>>n;
	cout<<"enter "<<n<<" elements ";
	for(i=0;i<n;i++)
		cin>>list[i];
	cout<<"enter key to search";
	cin>>key;
	pos=Rec_Lsearch(list,n-1,key);
	if(pos==-1)
		cout<<"\nelement not found";
	else
			cout<<"\n element found at index "<<pos;
}
int Rec_Lsearch(int list[],int n,int key)
{
	if(n<0)
		return -1;
	if(list[n]==key)
		return n;
	else
		return Rec_Lsearch(list,n-1,key);
}
