
// 030225
// BinSrch Prog 7 : First&Last Position of X.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
	private:
		int n;
		vector<int> arr;
		int X;
		void setN();
		void setVector();
		void setX();

	public:
		Solution();
		Solution(vector<int>& arr, int n, int X);		
		void printVector();

		int lowerRange(int target);
		int upperRange(int target);
		vector<int> searchRange(vector<int>& arr, int target);
};

int Solution :: lowerRange(int target) {
	int left = 0, right = this->n-1, mid;
	// int lowIndex = -1;
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

int Solution :: upperRange(int target) {
	int left=0, right=this->n-1, mid;

	while( left <= right)
	{
		mid = left + ((right - left ) /2);
		if(arr[mid] == target)
		{
			if(mid == n-1 || arr[mid+1]!=target)
			{
				return mid;
			}
			else{
				left = mid+1;
			}
		}
	
		if(arr[mid] > target)
		{
			right = mid-1;
		}
		else{
			left = mid+1;
		}
	}
	return -1;
}

vector<int> Solution :: searchRange(vector<int>& arr, int target)
{
	int n = arr.size();
	vector<int> result; 
	// {
	// 	lowerBound(target), upperBound(target);
	// }
	int lowRange = lowerRange(target);
	// result.emplace_back();
	// result.emplace_back(upperRange(target));
	if(lowRange == -1)
	{
		result.emplace_back(-1);
		result.emplace_back(-1);
	}
	else{
		result.emplace_back(lowRange);
		result.emplace_back(upperRange(target));
	}
	return result;
}

void Solution :: printVector()
{
	cout << "[ ";
	for( const int& ele : this->arr)
	{
		cout << ele << " ";
	}cout << "]\n";
}

int main()
{
	Solution obj = Solution();

	cout << "Input Array : ";
	obj.printVector();

	
	
	// cout << "X element " << result << " at : " << indexFound << endl;
	return 0;
}

Solution :: Solution()
{
	this->setN();
	if(this->n == 0)
	{
		this->arr = {};
	}
	else
	{
		this->setVector();
		this->setX();
	}
}

Solution :: Solution(vector<int>& arr, int n, int X)
{
	this->n = n;
	this->arr = arr;
	this->X = X;
}

void Solution :: setN()
{	
	cout << "Enter array size : ";
	cin >> this->n;
}

void Solution :: setVector()
{
	cout << "Enter the " << n << " array elements : ";
	int temp;
	for(int i = 0; i<n; i++)
	{
		cin >> temp;
		this->arr.emplace_back(temp);
	}
}

void Solution :: setX()
{
	cout << "Enter the X element to search : ";
	cin >> this->X;
}

/*
TEST CASES :-
C1. Input: nums = [5,7,7,8,8,10], target = 8
	Output: [3,4]

C2.	Input: nums = [5,7,7,8,8,10], target = 6
	Output: [-1,-1]

C3.	Input: nums = [], target = 0
	Output: [-1,-1]
*/