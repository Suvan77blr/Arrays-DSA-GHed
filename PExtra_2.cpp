
// 040125 (Started on 020125)

/* Extra Prog-2 : Duplicate Zeros
    * Given a fixed length integer array, duplicate each occurrence of zero, shifting the remaining elements to the right.
    * NOTE : the elements beyond the length of the original array are not written.
    * IN-Place modification is to be done.

*/


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
        void duplicateZeros();
        void moveRight(vector<int>& arr, int index);

};

void Solution :: duplicateZeros()
{
    for(int i = 0; i<n; i++)
    {
        if(arr[i] == 0)
        {
            moveRight(arr, i+1);
            arr[i+1] = 0;
            i++;
        }
    }
    printVector();
}

void Solution :: moveRight(vector<int>& arr, int index)
{
    for(int i = arr.size() - 2; i>=index; i--)
    {
        arr[i+1] = arr[i];
    }
}

// Main Code.
int main(void)
{    
    Solution obj = Solution();
    obj.duplicateZeros();
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

