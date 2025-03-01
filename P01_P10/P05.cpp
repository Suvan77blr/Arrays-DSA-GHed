
// Modified 0103252322 (Orig 051124). 
/* P5 : Left rotating an array by '1' place.
        - OPTIMAL code.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void leftRotate(vector<int>& arr)
        {
            int temp = arr[0];
            int n = arr.size();
            for(int i=1; i<=n; i++) {
                arr[i-1] = arr[i];
            }
            arr[n-1] = temp;
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

    soln.leftRotate(arr);

    cout << "[ ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "]\n";
    return 0;
}