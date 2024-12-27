
// Has only the better and optimal versions.

// Started this around 15th Nov.
// Finally Completed this on 28th Dec midnight 2.

// P15 : Finding longest subarray w/ a sum 'k'.


#include <iostream>
#include <vector>
using namespace std;

class Solution{
    private:
        int n;
        vector<int> arr;
        int k;

        void getN();
        void getVector();
        void getK();
    public:
        Solution();
        Solution(vector<int>& arr, int n);

        void printVector();
        void optimalSoln();
        void betterSoln();
};

/*
    Optimal Approach : Using 2 pointers.
    * Also finds the number of sub-arrays having the maximum length.
    * T(n) = O(2n).
*/
void Solution :: optimalSoln()
{
    int currSum = 0,maxiLen = 0;
    int slow = 0, fast = 0;
    int subArrayCount = 0;

    while(fast < n)
    {
        cout << "slow = " << slow << ", fast = " << fast << " , currSum = " << currSum << " , maxiLen = " << maxiLen << " | " << endl;
        if(currSum < k)
        {   
            currSum += arr[fast];
            fast++;
        }
        else if(currSum > k)
        {
            currSum -= arr[slow];
            slow++;
        }
        else{

            if(maxiLen == fast-slow+1)
            {
                subArrayCount++;
            }

            if(maxiLen < fast-slow+1)
            {
                maxiLen = fast-slow + 1;
                subArrayCount = 1;
            }
           
            currSum += arr[fast];
            fast++;
            currSum -= arr[slow];
            slow++;
        }
    }
    cout << "Longest length w/ sum as \'"<<k<<"\' : " << maxiLen << endl;
    cout << "Sub-Array Count having length \'" << maxiLen << " \' : " << subArrayCount << endl;
}

#ifndef umap
#include <unordered_map>
#define umap 1
#endif

void Solution :: betterSoln()
{
    cout << "Running BETTER Solution Approach :- " << endl;

    unordered_map<int, int> ump(n);
    int sumArr = 0, currLen = 0;

    for(int i = 0; i<n; i++)
    {
        sumArr += arr[i];
        if(sumArr == k)
            currLen = i;
        int srchSum = sumArr - k;
        if(ump.find(srchSum) != ump.end())
        {
            int tempLen = i - ump[srchSum];
            if(tempLen > currLen)
                currLen = tempLen;
        }

        // For handling both +ve and -ve inputs.
        // If the entry for the current sum already exists, then we don't append the new (sum, index) pair to the hashmap.
        if(ump.find(sumArr) == ump.end())
            ump[sumArr] = i;
    }
    cout << "Longest length w/ sum as \'"<<k<<"\' : " << currLen+1 << endl;
}

// Main Code.
int main(void)
{    
    Solution obj = Solution();
    obj.printVector();
   obj.betterSoln();
//    obj.optimalSoln();
}


// Definitions for the pre-existing constructors & methods of the SolnTemplate
void Solution :: getN(){
    cout << "Enter the size : ";
    cin >> this->n;
}

void Solution :: getVector(){
    cout << "Enter the " << n << " vector elements : ";
    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        this->arr.push_back(temp);
    }
}

void Solution :: getK()
{
    cout << "Enter the value of \'k\' : ";
    cin >> this->k;
}

Solution :: Solution(){
    getN();
    getVector();
    getK();
}

Solution :: Solution(vector<int>& arr, int n){
    this->n = n;
    this->arr = arr;
}

void Solution :: printVector(){
    cout << "Printing the vector ... \n";
    cout << "[ ";
    for(const int& ele : this->arr){
        cout << ele << " ";
    }
    cout << "]\n";
}

