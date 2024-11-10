
// 021124 - Midnight of 1st.
// Second Largest element.

#include <iostream>

#define SWAP(a,b) {\
	a = a^b;	\
	b = a^b;	\
	a = a^b;	\
}
using namespace std;

void sort(int * arr, int size)
{
	cout << "Using Insertion sort!" << endl;
	int min_pos;
	for( int i = 1; i<size-1; i++)
	{
		for( int j = i+1; j > 0; j--)
		{
			if(arr[j] < arr[j-1])
				SWAP(arr[j], arr[j-1]);
		}
	}
}

void display(int * arr, int size)
{
	cout << "[ ";
	for(int i = 0; i<size; i++)
		cout << arr[i] << " ";
	cout << "]\n";
	return;
}

// Brute Force.
void brute(int * arr, int size)
{
	cout << "Brute Force : ";
	sort(arr, size);

	int maxi = arr[size - 1];
	int sec_maxi = -1;
	for(int i = size - 2; i>=0; i--)
		if( arr[i] != maxi)
		{	sec_maxi = arr[i];
			break;
		}
	cout << "Second Maximum element : " << sec_maxi << endl;
}

// Better version.
void better(int * arr, int size)
{
	cout << "Better Version.\n";
	int maxi = arr[0];
	for(int i = 0; i<size; i++)
		if(arr[i] > maxi)
			maxi = arr[i];

	int sec_maxi = -1;
	for(int i = 0; i<size; i++)
	{
		if(arr[i] > sec_maxi && arr[i] != maxi)
			sec_maxi = arr[i];
	}
	cout << "Second Maximum element : " << sec_maxi << endl;
}

void opti(int * arr, int size)
{
	int maxi = arr[0], sec_maxi = -1;
	for(int i = 1; i<size; i++)
	{
		if(arr[i] > maxi)
		{
			sec_maxi = maxi;
			maxi = arr[i];
		}
		if(arr[i] > sec_maxi and arr[i] != maxi)
			sec_maxi = arr[i];
	}
	cout << "Second Maximum element : " << sec_maxi << endl;
}

int main(void)
{
	int arr[] = {7, 2, 4, 7, 1, 5};
	int size = sizeof(arr) / sizeof(arr[0]);

	display(arr, size);

//	brute(arr, size);

	//better(arr, size);

	opti(arr, size);
	
	cout << "EOP!\n";
	return 0;
}
