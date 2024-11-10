
// 051124
// P5 : Left rotating an array by '1' place.

#include <iostream>
using namespace std;

class Array
{
	int n;
	int * arr;

	public:	
		Array();
		void LRot_by_one();
		void display();
		~Array();
};

Array :: Array(){
	std :: cout << "Enter the number of elements of the array : ";
	std :: cin >> n;

	arr = new int[n];

	std :: cout << "Enter the \'" << n << "\' array elements : \n";
	for(int i = 0; i<n; i++)
	{
		std :: cin >> arr[i];
	}
}

void Array :: LRot_by_one(){
	int temp = arr[0];
	for(int i = 1; i<n; i++){
		arr[i-1] = arr[i];
	}
	arr[n-1] = temp;
}

void Array :: display(){
	std :: cout << "[ ";
	for(int i = 0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << "]\n";
}

Array :: ~Array(){
	delete[] arr;
}


int main(void)
{
	Array obj1;
	std :: cout << "Orig Arr : ";
	obj1.display();

	obj1.LRot_by_one();

	std :: cout << "After 1 Rot : ";
	obj1.display();

	return 0;
}
