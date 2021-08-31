#include<iostream>
using namespace std;
void merge(int a[ ],int low,int mid,int high)
{
int temp[100];
int i,j,k;
	i=low;
	j=mid+1;
	k=low;
	while((i<=mid)&&(j<=high))
	{
		if(a[i]<=a[j])
		{
			temp[k]=a[i];
			++i;
		}
		else
		{
			temp[k]=a[j];
			++j;
		}
			++k;
	}
	if(i>mid)
	{
	while(j<=high)
	{
		temp[k]=a[j];
		++j;
	    ++k;
	}
    }
	else
	{
		while(i<=mid)
		{
			temp[k]=a[i];
			++i;
			++k;
		}
	}
	for(int i=low;i<=high;i++)
		a[i]=temp[i];
}

void mergesort(int a[],int low,int high)
{
int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
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
	mergesort (list,0,n-1);
	cout<<" after sorting\n";
	for(i=0;i<n;i++)
		cout<<list[i]<<"\t";
return 0;
}
