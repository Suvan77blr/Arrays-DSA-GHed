
// Modified 0803251623 (Orig 081124). 
/* P8 : Linear Srch
    > Iterative Logic.
    > Recursive Logic.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int linearSrch_Iterative(vector<int>& arr, int key);
        int linearSrch_Recursive(vector<int>& arr, int key, int currIndex);
};

int Solution :: linearSrch_Iterative(vector<int>& arr, int key)
{
    int n = arr.size();
    for(int i=0; i<n; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int Solution :: linearSrch_Recursive(vector<int>& arr, int key, int currIndex) 
{
    if(currIndex >= arr.size())
        return -1;
    if(arr[currIndex] == key)
        return currIndex;
    else
        return linearSrch_Recursive(arr, key, currIndex+1);
}
int main(void) {
    int n;
    cout << "Enter the array size : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the " << n << " elements of arr: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the 'key' to search : ";
    cin >> key;

    // Calling the logic!
    int indexLoc = Solution().linearSrch_Iterative(arr, key);
    // int indexLoc = Solution().linearSrch_Recursive(arr, key, 0);

    cout << "\nSearch result for \'" << key << "\' : ";
    if(indexLoc == -1) {
        cout <<  "Not Found :(\n";
    }
    else {
        cout << indexLoc << "th Index!\n";
    }
    return 0;
}