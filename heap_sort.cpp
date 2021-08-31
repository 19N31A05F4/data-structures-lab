#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
int largest = i; 
int L= 2*i + 1; 
int R= 2*i + 2; 
	if (L < n && arr[L] > arr[largest])
		largest = L;
	if (R < n && arr[R] > arr[largest])
		largest = R;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void heapSort(int arr[], int n)
{ 
int i;
	for ( i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	
	for ( i=n-1; i>=0; i--)
	{
	
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
void printArray(int arr[], int n)
{
	for (int i=0; i<n; ++i)
	cout << arr[i] << " ";
	cout << "\n";
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
	heapSort(list, n);
	cout << "Sorted array is \n";
	printArray(list, n);
return 0;
}
