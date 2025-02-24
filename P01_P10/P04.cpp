
// Modified 250225-0133 (Orig 051124). 
/* P4 : Removing Duplicates from a sorted array.
        
        - BRUTE : Append all the elements to a set. But SC : O(n).
        - OPTIMAL : Two Ptr Approach. 
            Equal?continue. 
            Else update SLOW and swap.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& arr)
        {
            int n = arr.size();
            int slow=0, fast=1, temp;

            for(; fast<n; fast++)
            {
                if(arr[slow] == arr[fast])
                {
                    continue;
                }
                slow++;
                temp = arr[slow];
                arr[slow] = arr[fast];
                arr[fast] = temp;
            }
            return slow+1;
        }
};

int main(void) {
    int n;
    cout << "Enter the array size : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the " << n << " elements : ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    Solution soln = Solution();

    int k = soln.removeDuplicates(arr);

    cout << "[ ";
    for(int i=0; i<k; i++)
        cout << arr[i] << " ";
    cout << "]\n";
    return 0;
}


// Alternative Approach w/ slight modifications.
int getUnique(int * arr, int n){
    int temp = arr[0], fast = 1, slow = 1;
    while(fast < n){
        if(arr[fast] != temp){
            temp = arr[fast];
            arr[slow] = temp;
            slow++;
        }
        fast++;
    }
    return slow;
}
/*


// new[]:-
int * getArray(int n){
    cout << "Enter the \'" << n << "\' elements : ";
    int * arr = new int[n];
    // int * arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    return arr;
}

*/