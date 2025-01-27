
// 280125
// BinSrch Prog 4 : Search Insert Position.

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
		void printVector();

		int searchInsertPosition();	
		bool bFound;            // Used to set the 'result' string to either Found OR Insert.
};

int Solution :: searchInsertPosition()
{
	int left = 0, right = n-1, mid;
	int lb = n;     // If the element isn't presetn then the Lower-Bound of the 'key' element will be returned;

	while(left <= right)
	{
		mid = left + ((right-left) /2);

		if(arr[mid] == this->key)
		{
			this->bFound = true;
			return mid;
		}
		else
		{
			if(arr[mid] > key)
			{
				lb = mid;
				right = mid-1;
			}
			else
			{
				left = mid+1;
			}
		}
	}
	return lb;
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

	int indexFound = obj.searchInsertPosition();
	string result = obj.bFound ? "is Found" : "can be Inserted";
	cout << "Key element " << result << " at : " << indexFound << endl;
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
	this->bFound = false;
}

Solution :: Solution(vector<int>& arr, int n, int key)
{
	this->n = n;
	this->arr = arr;
	this->key = key;
	this->bFound = false;
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
