#include<iostream>
using namespace std;
void selection_sort (int list[],int n)
{
int min,temp,i,j;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(list[j]<list[min])
                min=j;
        }
        temp=list[i];
        list[i]=list[min];
        list[min]=temp;
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
    selection_sort(list,n);
    cout<<" after sorting\n";
    for(i=0;i<n;i++)
        cout<<list[i]<<endl;
return 0;
}
