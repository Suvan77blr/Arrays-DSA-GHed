
// 060225
// BinSrch Prog 8 : Counting Instances of Element in Sorted Array w/ Duplicates.

#include <iostream>
#include <vector>
using namespace std;

void inputVector(vector<int>& arr, int n);
void printVector(vector<int>& arr);

class Solution
{
    public:
		int countElement(vector<int>& arr, int target);
		int lowerRange(vector<int>& arr, int target);
		int upperRange(vector<int>& arr, int target);
};

int Solution :: lowerRange(vector<int>& arr, int target) {
	int n = arr.size();
    int left = 0, right = n-1, mid;
	while(left <= right)
	{
		mid = left + ( (right-left) /2);

		if(arr[mid] == target)
		{
			if(mid==0 || arr[mid-1] != target)
			{
				return mid;
			}
			else{
				right = mid-1;
			}
		}
		if(arr[mid] >= target)
		{
			right = mid-1;
		}
		else{
			left = mid+1;
		}
	}
	return -1;
}

int Solution :: upperRange(vector<int>& arr, int target) {
	int n = arr.size();
    int left=0, right=n-1, mid;

	while( left <= right)
	{
		mid = left + ((right - left ) /2);
		if(arr[mid] == target)
		{
			if(mid == n-1 || arr[mid+1]!=target) {
				return mid;
			}
			else {
				left = mid+1;
			}
		}
	
		if(arr[mid] > target) {
			right = mid-1;
		}
		else{
			left = mid+1;
		}
	}
	return -1;
}

int Solution :: countElement(vector<int>& arr, int target)
{
	int n = arr.size();
    if(n == 1)
    {
        return (arr[0] == target) ? 1 : 0;
    }

	int lb = lowerRange(arr, target);
	if(lb == -1)
	    return 0;

    int ub = upperRange(arr, target);
    
    return ub - lb + 1;
}

void printVector(vector<int>& arr)
{
	cout << "[ ";
	for( const int& ele : arr)
	{
		cout << ele << " ";
	}cout << "]\n";
}

int main()
{
    int n;
	cout << "Enter array size : ";
	cin >> n;
    vector<int> arr;
    inputVector(arr, n);

    int X;
    cout << "Enter the X element to search : ";
	cin >> X;

	cout << "Input Array : ";
	printVector(arr);

    Solution obj = Solution();
    int count = obj.countElement(arr, X);
    cout << "Element \'" << X << "' occurs : " << count << " times.\n";

	return 0;
}

void inputVector(vector<int>& arr, int n)
{
	cout << "Enter the " << n << " array elements : ";
	int temp;
	for(int i = 0; i<n; i++)
	{
		cin >> temp;
		arr.emplace_back(temp);
	}
}

/*
TEST CASES :-
C1. Input: nums = [5,7,7,8,8,10], target = 8
	Output: 2

C2.	Input: nums = [5,7,7,8,8,10], target = 6
	Output: 0

C3.	Input: nums = [0], target = 0
	Output: 1
*/