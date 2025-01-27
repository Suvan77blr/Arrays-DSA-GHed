
// 021124. Midnight of 1st.
// Checking if the entered array is sorted.

#include <iostream>
using namespace std;

int getSize(){
	int n;
	cout << "Enter the number of elements : ";
	cin >> n;
	return n;
}

int * createArray(int n)
{
	cout << "Enter the \'" << n << "\' elements of the array : ";
	int * arr = new int[n];
	for(int i = 0; i<n; i++)
		cin >> arr[i];
	return arr;
}	

bool isSorted(int * arr, int size)
{
	for(int i = 1; i<size; i++)
		if(arr[i] < arr[i-1])
			return false;
	return true;
}

int main(void)
{
	int n = getSize();

	int * arr = createArray(n);
	bool result = isSorted(arr, n);

	cout << "Array is : " << (result ? "Sorted.\n" : "Unsorted.\n");

	delete[] arr;
	return 0;
}
