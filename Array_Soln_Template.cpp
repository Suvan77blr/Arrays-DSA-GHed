// Default template for Array Problems.

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    private:
        int n;
        vector<int> arr;
        void getN();
        void getVector();

    public:
        Solution();
        Solution(vector<int>& arr, int n);

        void printVector();
        // Additional Methods can be added as per the problem requirement.

};

// Main Code.
int main(void)
{    
    Solution obj = Solution();
    obj.printVector();
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

Solution :: Solution(){
    getN();
    getVector();
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

