// Default template for Array Problems.

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& arr);

class Solution{
    public:
        // Defined methods for the Solution.
        // void methodSolution(...args);
        // Additional Methods can be added as per the problem requirement.
};

// Main Code.
int main(void)
{   
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    vector<int> arr;
    inputVector(arr, n);

    cout << "Input array : ";
    printVector(arr);

    Solution obj = Solution();
    
    // Method Calls as requried
    // obj.methodSolution(...args);

    return 0;
}

void inputVector(vector<int>& arr, int n) {
    cout << "Enter the " << n << " vector elements : ";
    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        arr.push_back(temp);
    }
}

void printVector(vector<int>& arr){
    cout << "[ ";
    for(const int& ele : arr) {
        cout << ele << " ";
    } cout << "]\n";
}