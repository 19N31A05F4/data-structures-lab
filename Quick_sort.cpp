#include<iostream>
using namespace std;
int partition(int x[],int low,int high)
{
int down,up,pivot,t;
	if(low<high)
	{
		down=low;
		up=high;
		pivot=down;
		while(down<up)
		{
			while((x[down]<=x[pivot])&&(down<up))
				down++;
			while(x[up]>x[pivot])
				up--;
			if(down<up)
			{
				t=x[down];
				x[down]=x[up];
				x[up]=t;
			}
		}
		t=x[pivot];
		x[pivot]=x[up];
		x[up]=t;
	}
return up;
}

void quicksort(int x[],int low,int high)
{
int p;
	if(low<high)
	{
		p=partition(x,low,high);
		quicksort(x,low,p-1);
		quicksort(x,p+1,high);
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
	quicksort(list,0,n-1);
	cout<<" after sorting\n";
	for(i=0;i<n;i++)
		cout<<list[i]<<endl;
return 0;
}
