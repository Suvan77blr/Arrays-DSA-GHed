

// Modified 250225-0110 (Orig 021124 - MidN of 01). 
/* P2 : 2nd Largest Element in an array.
        - Getting the sec_maxi index only.
        
        - BRUTE : Sort and Traverse in reverse.     => O(NlogN + N)
        - BETTER : 2 Pass Solution.                 => O(2n)
        
        * OPTIMAL : One Pass Soln.                  => O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int getSecLargestElementIndex(vector<int>& arr) 
        {  
            int n = arr.size();
            
            // int sec_maxi_pos;
            int sec_maxi_pos = -1, maxi_pos = 0;
            for(int i=0; i<n; i++) {
                if(arr[i] > arr[maxi_pos])
                {
                    sec_maxi_pos = maxi_pos;
                    maxi_pos = i;
                }
                if(arr[i] > arr[sec_maxi_pos] && arr[i] != arr[maxi_pos])
                {
                    sec_maxi_pos = i;
                }
            }
            return sec_maxi_pos;
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
    int secLargestEleIndex = soln.getSecLargestElementIndex(arr);

    if(secLargestEleIndex == -1) {
        cout << "2nd Maxi element : " << secLargestEleIndex << endl;
    }
    else {
        cout << "2nd Maxi element : " << arr[secLargestEleIndex] << endl;
    }

    return 0;
}

/*
	TC : {7, 2, 4, 7, 1, 5};
 */