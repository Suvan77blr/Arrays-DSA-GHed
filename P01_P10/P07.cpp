
// Modified 0803251257 (Orig 061124). 
/* P7 : Move all zeros to the end of the array.

    - BRUTE (not implemented)
        > We append all non-zero elements to another array, keeping count of zeros.
        > All the counted zeros are then appended to the new array.
        > return the value of len - zerosCount

    - OPTIMAL code.
        
        > We find the first zero. (i)
        > if i==-1 => no zeros and can exit.
        > Otherwise, then run the 2nd pointer (j) from i+1 to 'n'.
        > Here.. 
            if(arr[j] != 0)
                swap arr[i], arr[j] & increment i.
            else only j will be incremented. 
        > Return the index 'i'.
*/

#include <iostream>
#include <vector>
using namespace std;

#define SWAP(a,b) { \
    a = a + b; \
    b = a - b; \
    a = a - b; \
} \

class Solution {
    public:
        int moveZeros(vector<int>& arr)
        {
            int i, n=arr.size();
            for(i=0; i<n; i++) {
                if(arr[i]==0)
                    break;
            }
            
            if(i == -1) return -1;

            for(int j=i+1; j<n; j++) {
                if(arr[j] != 0) {
                    SWAP(arr[i], arr[j]);
                    i++;
                }
            }
            return i;
        }
};

int main(void) {
    int n;
    // cout << "Enter the array size : ";
    cin >> n;

    vector<int> arr(n);
    // cout << "Enter the " << n << " elements : ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    Solution soln = Solution();

    int k = soln.moveZeros(arr);

    cout << "Result : [ ";
    for(int i=0; i<k; i++)
        cout << arr[i] << " ";
    cout << "]\n";
    return 0;
}
