
// Modified 250225-0133 (Orig 051124). 
/* P4 : Removing Duplicates from a sorted array.
        
    - BRUTE : Append all the elements to a set. But SC : O(n).
    - OPTIMAL : Two Ptr Approach. 
        Equal?continue. 
        Else UPDATE 'slow' and ASSIGN arr['slow'] <- arr['fast'].
*/

#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

class Solution {
public:
    int removeDuplicates(vi& arr) {
        int n = arr.size();
        int slow=0, fast=1, temp;

        for(; fast<n; fast++) {
            if(arr[slow] == arr[fast])  continue;
            
            slow++;
            arr[slow] = arr[fast];
        }
        return slow+1;
    }
};

int main(void) {
    int n;
    cin >> n;

    vi arr(n);
    for(int i=0; i<n; i++) {    cin >> arr[i];      }

    int k = Solution().removeDuplicates(arr);

    cout << "[ ";
    for(int i=0; i<k; i++)
        cout << arr[i] << " ";
    cout << "]\n";
    return 0;
}

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