
// Modified 0103252349 (Orig 071124). 
/* P6 : Left rotating an array by 'D' place.
        - Initial Approach : we can move the entire array by 'd' place, shifting '1' place at a time.
        - BRUTE : Stores the 1st D elements in another array.
                    > Shift all others by 'i-d'.
                    > Store back the earlier stored 'd' elements.
        
        - OPTIMAL code.
                    > reverse(0, d); OR rev(0, d-1);
                    > reverse(d, n); OR rev(d, n-1);
                    > reverse(0, n); OR rev(0, n-1);
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverse(vector<int>& arr, int start, int end);

    void leftRotateByD(vector<int>& arr, int d)
    {
        int n = arr.size();
        if(n==0 || d==0) return;
        d = d%n;                // Normalizing the 'd'.
        if(d == 0) return;

        reverse(arr, 0, d-1);
        reverse(arr, d, n-1);
        reverse(arr, 0, n-1);
    }
};

int main(void) {
    int n;      cin >> n;
    int d;      cin >> d;       // cout << "Enter the left-rotation factor : ";

    vector<int> arr(n);         // cout << "Enter the " << n << " elements : ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    Solution().leftRotateByD(arr, d);

    cout << "[ ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "]\n";
    return 0;
}

void Solution :: reverse(vector<int>& arr, int start, int end)
{
    // end--;   // If end is not part of array.
    while(start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++; end--;
    }
}