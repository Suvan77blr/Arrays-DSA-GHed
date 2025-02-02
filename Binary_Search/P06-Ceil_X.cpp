
// 280125 ( 030225)
// BinSrch Prog 6 : Ceil(X) Program

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

		int getX();
		int findCeil();	
};

int Solution :: findCeil()
{
	int left = 0, right = this->n-1, mid;
    int ceil;
    ceil = -1;
    
	while(left <= right)
	{
		mid = left + ((right-left) /2 );

		if(arr[mid] >= this->X)
		{
			ceil = arr[mid];
			right = mid-1;
		}
		else left = mid+1;
	}
	return ceil;
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

	int ceil = obj.findCeil();
	cout << "ceil(" << obj.getX() << ") = " << ceil << endl;
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
	cout << "Enter the X element to find ceil() : ";
	cin >> this->X;
}
int Solution :: getX()
{
	return this->X;
}
