
// 120124
// BinSrch Prog2 : LowerBound

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	private:
		int n;
		vector<int> arr;
		void getN();
		void getVector();

	public:
		Solution();
		Solution(vector<int>& arr, int n);
		void displayVector();
		int getLowerBound(int x);

};

void Solution :: displayVector()
{
	cout << "[ ";
	for(const int& ele : this->arr)
		cout << ele << " ";
	cout << "]\n";
}

int Solution :: getLowerBound(int x)
{
	int ans = this->arr.size();
	int left=0, right=this->n, mid;

	while(left <= right)
	{
		mid = (left + right) / 2;
		if(arr[mid] >= x)
		{
//			ans = min(ans, mid);
			ans = mid;
			right = mid-1;
		}
		else
		{
			left = mid+1;
		}
	}
	return ans;
}
	






int main(void)
{
	Solution obj = Solution();

	cout << "Array : ";
	obj.displayVector();

	int x;
	cout << "Enter search element : ";
	cin >> x;

	int lb = obj.getLowerBound(x);
	cout << "Lower Bound of \'" << x << "\' : " << lb << endl;

	return 0;
}

void Solution :: getN()	
{ 
	cout << "Enter array size : ";
	cin >> this->n;
}

void Solution :: getVector()
{
	cout << "Enter the " << this->n << " array elements : ";
	int temp;
	for(int i=0; i<this->n; i++)
	{
		cin >> temp;
		this->arr.emplace_back(temp);
	}
}

Solution :: Solution()
{
	this->getN();
	this->getVector();
}

Solution :: Solution(vector<int>& arr, int n)
{
	this->n = n;
	this->arr = arr;
}
