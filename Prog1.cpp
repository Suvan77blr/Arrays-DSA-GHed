/*
	Array Practise Program.
	* Lin, Bin - Srches
	* Reversal Func.


  */

#include <iostream>

#define SWAP(a,b) {		\
	a = a^b;	\
	b = a^b;	\
	a = a^b;	\
}	\

using namespace std;

int* inputArr(int n)
{
	int * arr = new int[n];
	if(n<=10)
	{
		cout << "Enter the " << n << " array elements : ";
		for( int i = 0; i<n ; i++)
			cin >> arr[i];
	}
	
	else{
		for( int i = 0; i<n; i++)
			arr[i] = i+1;
	}

	return arr;
}

void displayArr(int * arr, int n)
{
	cout << " Printing the array : \n\t[ ";
	for(int i = 0; i<n; i++)
		cout << arr[i] << " ";
	cout << "]" << endl;
}

int linSrch(int* arr, int n, int k)
{
	for( int i = 0; i<n; i++)
		if(arr[i] == k)
			return i;
	return -1;
}

int binSrch(int * arr, int n, int key)
{
	int fst = 0, lst = n, mid;
	while(fst <= lst)
	{
		mid = (int)(fst+lst) / 2;
		if(arr[mid] == key)
			return mid;

		if (arr[mid] < key)
			fst = mid + 1;
		else
			lst = mid - 1;
	}
	return -1;
}

void reverseArr(int * arr, int n){
//	int * temp = new int[n];
	int hlf = n/2;
	for(int i = 0; i<hlf; i++)
		SWAP(arr[i], arr[n-i-1]);

//	for(int i
}

/*
int main(void)
{
	int n;
	cout << "Enter the num of elements : ";
	cin >> n;

	int * arr = inputArr(n);

	displayArr(arr,n);

	reverseArr(arr,n);

	cout << "Reversed Array : ";
	displayArr(arr,n);

	int result;
	/* //TIMING SECTION.
	clock_t t1,t2;
	double ptr_Time;

	t1 = clock();
	result = linSrch(arr, n, key);
	t2 = clock();
	ptr_Time = (double)(t2-t1) / (CLOCKS_PER_SEC / 1000);
	printf("Linear Search : %.3fms\n", ptr_Time);

	t1 = clock();
	result = linSrch(arr, n, key);
	t2 = clock();
	ptr_Time = (double)(t2-t1) / (CLOCKS_PER_SEC / 1000);
	printf("Binary Search : %.3fms\n", ptr_Time);
//	/

	delete[] arr;

	cout << "\nEOP!" << endl;

	return 0;
}

*/
