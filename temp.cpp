

// 131124
// tmp (p14) : finding the longest subarray with sum k.

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	cout << "Enter \'n\' : ";
	cin >> n;

	vector<int> arr (n);
	cout << "Enter the " << n << " elements : ";
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}

	int k;
	cout << "Enter \'k\' : ";
	cin >> k;

	int sum = 0, tempLen = 0, len = 0;

	for(int slow = 0; slow<n; slow++)
	{
		sum = 0;
		tempLen = 0;
		for(int fast = slow; fast < n; fast++)
		{
			sum += arr[fast];
			tempLen++;

			if(sum > k)
			{
				break;
			}
			if(tempLen > len)
			{
				len = tempLen;
			}
		}
	}

	cout << len << endl;
}




// #include <iostream>
// #include <vector>
// using namespace std;

// int getSize(){
// 	cout << "\tEnter the size of the vector : ";
// 	int n;
// 	cin >> n;
// 	return n;
// }

// void getVector(vector<int>& v, int n){
// 	cout << "\tEnter the " << n << " vector elements : ";
// 	for(int i = 0; i<n; i++){
// 		cin >> v[i];
// 	}
// }

// void displayVector(vector<int> v){
// 	cout << "[ ";
// 	for(const int& ele : v){
// 		cout << ele << " ";
// 	}cout << "]\n";
// }

// int main(){
// 	cout << "INPUT : " << endl;
// 	int n = getSize();
// 	vector<int> arr(n);
// 	getVector(arr, n);
	
// 	int k;
// 	cout << "Enter \'k\' : ";
// 	cin >> k;

// 	int len = 0, sum = 0;
// 	int slow = 0;
// 	for(int slow = 0; slow < n; slow++)
// 	{
// 		for(int fast = slow+1; fast < n; fast++)
// 		{
// 			int temp;
// 			sum += arr[fast];
// 			temp++;
// 			if(sum > k)
// 			{
// 				temp = sum = 0;
// 				break;
// 			}
// 			if(temp > len)
// 				len = temp;
// 		}
// 	}
// 	cout << "Max sub-array length of value " << k << " : " << len << endl;

// 	cout << "EOP!" << endl;
// 	return 0;
// }
