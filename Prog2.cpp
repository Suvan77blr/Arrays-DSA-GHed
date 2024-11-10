#include <iostream>

using namespace std;

int* inputArr(int n);
void displayArr(int * arr, int n);

int getSubarrayCount(int n){
	return n*(n+1)/2;
}

void printSubarray(int * arr,int n){
	cout << "Printing all the sub-arrays : " << endl;	
		for(int i = 0; i<n; i++)
		{
			for( int j = i; j<n; j++)
	//		for( int j = n-1; j>=i; j--)
			{
				//cout << "\tarr[" << i << " : " << j << "]" << endl;
				//displayArr(arr+i, j+1);
				displayArr(arr+i, (j-i)+1);
			}
			cout << endl;
		}
}

int main(void)
{
	int n;
	cout << "Enter the len of array : ";
	cin >> n;

	int * arr = inputArr(n);
	displayArr(arr, n);
	int count = getSubarrayCount(n);
	cout << "For length " << n << ", sub-array count = " << count << endl;

	printSubarray(arr, n);
	delete[] arr;
	return 0;
}


int* inputArr(int n)
{
	int * arr = new int[n];
	cout << "Enter the " << n << " elements : ";
	for( int i = 0; i<n; i++)
		cin >> arr[i];
	return arr;
}

void displayArr(int * arr, int n)
{
	cout << "[ ";
	for(int i = 0; i<n; i++)
		cout << arr[i] << " ";
	cout << "]" << endl;
}
