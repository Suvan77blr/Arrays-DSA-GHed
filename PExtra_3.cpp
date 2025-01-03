
// 040125

/* 
    Extra Problem 3 : Remove Element.
        * All occurences of the specified element 'val'.
        * Return the 'k' number of elements that are not equal to 'val'.
    
    * Similar to => PROBLEM 7 : Moving Zeros to the End.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    private:
        vector<int> arr;
        int n;
        void getN();
        void getVector();

    public:
        Solution();
        Solution(vector<int>& arr, int n);
        int removeElement();
        void printVector(int eles_to_display);
};

int Solution :: removeElement()
{
    int ele;
    cout << "Enter the element to remove : ";
    cin >> ele;

    // If an empty array is passed.
    if(arr.size() == 0)
        return 0;

    int slow = -1, fast = 0;
    // Check if the element to remove is present or not.
    for(; fast < arr.size(); fast++)
    {
        if(arr[fast] == ele)
        {
            slow = fast;
            break;
        }
    }

    // If 'ele' is not present => return entire size of 'arr' so that it is fully printed.
    if(slow == -1)
        return arr.size();

    for(fast = slow+1; fast<arr.size(); fast++)
    {
        if(arr[fast] != ele)
        {
            int temp = arr[slow];
            arr[slow] = arr[fast];
            arr[fast] = temp;
            slow++;
        }
    }
    return slow;
}

void Solution :: printVector(int eles_to_display)
{
    int i = 0;
    cout << "[ ";
    for(int i=0; i<eles_to_display; i++)
    {
        cout << this->arr[i] << " " ;

    }cout << "]\n";
}

// Main code.
int main()
{
    Solution obj = Solution();
    int elementCount = obj.removeElement();
    obj.printVector(elementCount);
    return 0;
}

void Solution :: getN(){
    cout << "Enter the vector size : ";
    cin >> this->n;
}

void Solution :: getVector()
{
    int temp;
    cout << "Enter the " << this->n << " vector elements : ";
    for(int i = 0; i<this->n; i++)
    {
        cin >> temp;
        this->arr.emplace_back(temp);
    }
}

Solution :: Solution()
{
    getN();
    getVector();
}



Solution :: Solution(vector<int>& arr, int n)
{
    this->arr = arr;
    this->n = n;
}
