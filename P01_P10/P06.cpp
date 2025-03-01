
// Modified 0103252349 (Orig 071124). 
/* P6 : Left rotating an array by 'D' place.
        - Initial Approach : we can move the entire array by 'd' place, shifting '1' place at a time.
        - BRUTE : Stores the 1st D elements in another array.
                    > Shift all others by 'i-d'.
                    > Store back the earlier stored 'd' elements.
        
        - OPTIMAL code.
                    > reverse(0, d);
                    > reverse(d, n);
                    > reverse(0, n);
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void reverse(vector<int>& arr, int start, int end)
        {
            int temp;
            while(start <= end)
            {
                end--;
                temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
                start++;
            }
        }

        void leftRotateByD(vector<int>& arr, int d)
        {
            int n = arr.size();
            reverse(arr, 0, d);
            reverse(arr, d, n);
            reverse(arr, 0, n);
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
    
    int d;
    cout << "Enter the left-rotation factor : ";
    cin >> d;

    Solution soln = Solution();

    soln.leftRotateByD(arr, d);

    cout << "[ ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "]\n";
    return 0;
}
