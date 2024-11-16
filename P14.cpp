
// Started from 131124 -> 171124
// P14 : Finding the largest subarray len with sum 'k'. 
// Optimal version yet to be coded.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Program
{
    private:
        int n;
		long long k;
        vector<int> arr;

    public:
        Program();
		Program(int n, vector<int>& arr, int k);
        void runBrute();
        void runBetter();
        void runOPtimal();

        void displayVector();
};

Program :: Program(){
    cout << "\tEnter the size of the vector : ";
	cin >> n;

	int temp;
	cout << "\tEnter the " << n << " vector elements : ";
	for(int i = 0; i<n; i++){
		// cin >> arr[i];
		cin >> temp;
		arr.push_back(temp);
	}
}

Program :: Program(int n, vector<int>& arr, int k)
{
	this->n = n;
	this->k = k;
	this->arr = arr;
}

void Program :: displayVector(){
	cout << "[ ";
	for(const int& ele : arr){
		cout << ele << " ";
	}cout << "]\n";
}

void Program :: runBrute()
{
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
    cout << "Max-len of sum \'" << k << "\' : " << len << endl;  
    cout << "END of BRUTE." << endl;
    return;
}


void Program :: runBetter()
{
	unordered_map<long long, int> ump; 	// {prefix-sum-value, index}

	long long sum = 0;
	int maxLen = 0;
	for(int i=0 ; i<n; i++)
	{
		sum += arr[i];

		if(sum == k){
			// maxLen += (i+1);
			maxLen = max(maxLen, i+1);
		}


		ump.insert({sum, i});

		int check = sum - k;

		if(ump.find(check) != ump.end())
		{
			int currLen = i-ump[check];
			// if((currLen > maxLen))
			// 	maxLen = currLen;
			maxLen = max(maxLen, currLen);
		}
	}

    cout << "Max-len of sum \'" << k << "\' : " << maxLen << endl;  

	cout << "\nEND of BETTER." << endl;
	return;

}

int main(void)
{
	vector<int> arr {1, 2, 1, 3, 1, 1, 1, 4, 2, 3};
    Program * obj = new Program(10, arr, 6);
	// obj->runBrute();
	obj->displayVector();
	obj->runBetter();
    delete obj;
	cout << "EOP!\n";
}