#include<iostream>
using namespace std;
void insertion_sort(int a[],int n)
{
int i,t,pos;
for(i=0;i<n;i++)
{
t=a[i];
pos=i;
while(pos>0&&a[pos-1]>t)
{
a[pos]=a[pos-1];
pos--;
}
a[pos]=t;
}
}
int main()
{
int n,i;
int list[30];
cout<<"enter no of elements\n";
cin>>n;
cout<<"enter "<<n<<" numbers ";
for(i=0;i<n;i++)
cin>>list[i];
insertion_sort(list,n);
cout<<" after sorting\n";
for(i=0;i<n;i++)
cout<<list[i]<<endl;
return 0;
}