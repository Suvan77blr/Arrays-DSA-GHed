
// 311224 (30th Midnight)
// Extra-Prog 1 : Squares of Sorted Array .. to be stored in a sorted order. (LeetCode)

#include <iostream>
#include <vector>
#include <algorithm>
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
        void printArray(vector<int>& arr);
        void bruteApproach();
        void optimalApproach();
};

void Solution :: bruteApproach()
{
    cout << "Solution using the BRUTE approach...!\n";

    vector<int> result;
    for(const int& ele : this->arr)
    {
        result.emplace_back(ele * ele);
    }
    sort(result.begin(), result.end());
    this->printArray(result);
}

void Solution :: optimalApproach()
{
    cout << "Solution using the OPTIMAL approach... Leveraging Initial sorted order by TWO PTRS.\n";

    vector<int> result (this->n);
    int left = 0, right = n-1;

    for(int i = n-1; i>=0; i--)
    {
        if(abs(arr[left]) > arr[right])
        {
            result[i] = arr[left] * arr[left];
            left++;
        }
        else
        {
            result[i] = arr[right] * arr[right];
            right--;
        }
    }
    this->printArray(result);
}

void Solution :: printArray(vector<int>& arr)
{
    cout << "[ ";
    for(const int& ele : arr)
    {
        cout << ele << " ";
    }
    cout << "]\n";
}

int main(void)
{
    Solution obj = Solution();
    obj.bruteApproach();
    obj.optimalApproach();

    cout << "\nEOP!\n";
    return 0;
}

Solution :: Solution()
{
    getN();
    getVector();
}

void Solution :: getN()
{
    cout << "Enter the array size : ";
    cin >> this->n;
}

void Solution :: getVector()
{
    cout << "Enter the " << n << " array elements : ";
    int temp;
    for(int i = 0; i<this->n; i++)
    {
        cin >> temp;
        this->arr.emplace_back(temp);
    }
}