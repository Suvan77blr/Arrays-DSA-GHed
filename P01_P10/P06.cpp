
// 071124 (originally learnt on 051124)
// P6 : Left Rotating the array by 'D' positions.

#include <iostream>
#include <vector>
//using namespace std;

inline int getSize(){
	std :: cout << "Enter the number of elements : ";
	int n;
	std :: cin >> n;
	return n;
}

void getInput(std::vector<int>& arr, int n){
	std :: cout << "Enter the " << n << " elements : ";
	int temp;
	for(int i = 0; i<n; i++)
	{
		std :: cin >> temp;
		arr.push_back(temp);
	}
}

void displayVector(std::vector<int>& arr){
	std :: cout << "[ ";
	for(auto iter : arr){
		std :: cout << iter << " ";
	}
	std :: cout << "]\n";
}

void reverse(std::vector<int>& arr, int start, int end){
	int temp;
	while(start < end){
		end--;
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;

		start++; 
	}
}

void shift_by_D(std::vector<int>& arr, int n, int d)
{
	reverse(arr, 0, d);
	reverse(arr, d, n);
	reverse(arr, 0, n);
}

int main(void){
	int n = getSize();

	std :: vector<int> arr;

	getInput(arr, n);


	std :: cout << "Original Vector : ";
	displayVector(arr);

	int d;
	std :: cout << "The value of \'d\' : ";
	std :: cin >> d;
	shift_by_D(arr, n, d);

	std :: cout << "Vector left-shifted by " << d << " : ";
	displayVector(arr);

	std :: cout << "EOP!\n";
	return 0;
}

/*


*/