
// Modified 0103252326 (Orig 091124). 
/* P5_1 : Right rotating an array by '1' place.
        - OPTIMAL code.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void rightRotate(vector<int>& arr)
        {
            int n = arr.size();
            int temp = arr[n-1];    // Store the last ele.

            for(int i=n-2; i>=0; i--)
            {
                arr[i+1] = arr[i];
            }
            arr[0] = temp;
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

    soln.rightRotate(arr);

    cout << "[ ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "]\n";
    return 0;
}
