
// 071124 (originally 061124's)
// P7 : Move all zeros to the end of the array.

#include <iostream>
#include <vector>
//using namespace std;

#define SWAP(a, b) {	\
	a = a^b;	\
	b = a^b;	\
	a = a^b;	\
}	\

void displayVector(std::vector<int>& arr){
	std :: cout << "[ ";
	for(const int num : arr)
	{
		std :: cout << num << " ";
	}
	std :: cout << "]\n";
}	

// Prototype for Brute-Force soln.
void brute_soln(std::vector<int>& arr);
void my_soln(std::vector<int>& arr);

void setToZeros(std::vector<int>& arr){
	//brute_soln(arr);
	//my_soln(arr);

//	/*
	int j = -1;
	for(int i = 0; i < arr.size(); i++){
		if(arr[i]==0)
		{
			j = i;
		}
	}
	if(j == -1)	//No zeros are present.
		return;

	for(int i = j+1; i<arr.size(); i++){
		if(arr[i] != 0){
			SWAP(arr[i], arr[j]);
			j++;
		}
	}
}

int main(void){
	int n = 9;
	std::vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};

	std :: cout << "Orig Vec : ";
	displayVector(arr);

	setToZeros(arr);

	std :: cout << "Zero-ed Vec : ";
	displayVector(arr);

	std :: cout << "EOP!\n";
	return 0;
}

/*
void brute_soln(std::vector<int>& arr){
	std :: vector<int> temp;
	for(const int ele : arr){
		if(ele != 0)
			temp.emplace_back(ele);
	}

	int i = 0;
	for(; i<temp.size(); i++) {
		arr[i] = temp[i];
	}

	for(; i<arr.size(); i++) {
		arr[i] = 0;
	}
}
//	*/


/*
void my_soln(std::vector<int>& arr){
	int slow = 0,fast = 0;
	for(; fast < arr.size(); fast++){
		if(arr[fast]!=0)
		{
			arr[slow] = arr[fast];
			slow++;
		}
	}
	for(; slow < arr.size(); slow++){
		arr[slow] = 0;
	}
}
//	*/
