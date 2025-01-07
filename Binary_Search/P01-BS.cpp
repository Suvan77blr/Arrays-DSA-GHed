
// 070124.
// BinSrch Prog 1 : Basic BinSrch - Iterative & Recursive.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
	private:
		int n;
		vector<int> arr;
		int key;
		void setN();
		void setVector();
		void setKey();

	public:
		Solution();
		Solution(vector<int>& arr, int n, int key);
		vector<int> getVector(); 
		void printVector();
		int binSrch_Iterative();
		int binSrch_Recursive(const vector<int>& arr, int left=0, int right=-1, int key=-1);


};

int Solution :: binSrch_Iterative()
{
	int left = 0, right = this->n-1, mid;

	while(left <= right)
	{
		mid = (left + right) / 2;
		if(arr[mid] == key)
			return mid;
		else{
			if(arr[mid] < key)
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	return -1;
}

int Solution :: binSrch_Recursive(const vector<int>& arr, int left, int right, int key)
{
	if(arr.empty())
	{
		return 404;
	}
	if(right == -1)
	{
		right = this->n - 1;
	}

	if(key == -1)
	{
		key = this->key;
	}
	
	if( left > right)
		return -1;	

	int mid = (left+right) / 2;
	if(arr[mid] == key)
		return mid;
	else
	{
		if(arr[mid] > key)
			return binSrch_Recursive(arr, left, mid-1, key);
		else
			return binSrch_Recursive(arr, mid+1, right, key);
	}
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

	// int indexFound = obj.binSrch_Iterative();
	int indexFound = obj.binSrch_Recursive(obj.getVector());

	if(indexFound == -1)
		cout << "Key element NOT found in the Array.\n";
	else if(indexFound == 404)
		cout << "EMPTY ARRAY!\n";
	else
		cout << "Key element found at index : " << indexFound << endl;

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
		this->setKey();
	}
}

Solution :: Solution(vector<int>& arr, int n, int key)
{
	this->n = n;
	this->arr = arr;
	this->key = key;
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

void Solution :: setKey()
{
	cout << "Enter the key element to search : ";
	cin >> this->key;
}

vector<int> Solution :: getVector()
{
	return this->arr;
}
	
