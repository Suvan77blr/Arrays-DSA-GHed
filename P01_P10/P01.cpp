
// 311024.
// P1 : Largest Element in an array.

#include <iostream>
#include <climits>
using namespace std;

int main(void)
{
	int arr[] = {3, 2, 1, 5, 2};
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Current array : ";

	int maxi = INT_MIN;
	for(int i = 0; i<size; i++)
	{
		if(maxi < arr[i])
			maxi = arr[i];
		printf("%d ",arr[i]);
	}
	printf("\n");

	cout << "Max element in Array : " << maxi << endl;
	printf("EOP!\n");
	return 0;
}
