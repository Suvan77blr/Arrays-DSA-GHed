
// 060224
// BinSrch Prog 9 : Search in Rotate Sorted Array (w/o Duplicates)

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& arr);
void inputVector(vector<int>& arr, int n);

class Solution{
    public:
        int search(vector<int>& arr, int key) {
            int n = arr.size();
            if(n == 1) {
                return (arr[0] == key) ? 0 : -1;
            }

            int left=0, right=n-1, mid;
            
            while(left <= right) {
                mid = left + (right - left) /2;
                
                if(arr[mid] == key) {
                    return mid;
                }
                
                // Checking if LEFT-HALF is sorted.
                if(arr[left] <= arr[mid])
                {
                    // Checking if Target lies in the LEFT-sorted-Half. => TRIM RIGHT Half.
                    if(arr[left]<=key && key<=arr[mid])
                        right = mid-1;
                    else
                        left = mid+1;       // ELSE => LEFT Half is trimmed.
                }
                
                // Now, RIGHT-HALF will be sorted.
                else {
                    // Checking if Target lies in the RIGHT-sorted-Half. => TRIM LEFT Half.
                    if(arr[mid]<=key && key<=arr[right])   
                        left = mid+1;
                    else
                        right = mid-1;      // Else => RIGHT Half is trimmed.
                }
            }
            return -1;
        }
};

// Main Code.
int main(void)
{   
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    vector<int> arr;
    inputVector(arr, n);

    cout << "Input array : ";
    printVector(arr);

    cout << "Enter target to search : ";
    int target;
    cin >> target;

    Solution obj = Solution();
    int foundIndex = obj.search(arr, target);

    if(foundIndex >= 0){
        cout << "\'" << target << "\' found at index : " << foundIndex << endl;
    }
    else cout << "\'" << target << "\' NOT found in array" << endl;

    return 0;
}

void inputVector(vector<int>& arr, int n) {
    cout << "Enter the " << n << " vector elements : ";
    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        arr.push_back(temp);
    }
}

void printVector(vector<int>& arr){
    cout << "[ ";
    for(const int& ele : arr) {
        cout << ele << " ";
    } cout << "]\n";
}


/*
TEST CASES :-
C1. Input: nums = [4,5,6,7,0,1,2] target = 0
	Output: 4

C2.	Input: nums = [4,5,6,7,0,1,2], target = 3
	Output: -1

C3.	Input: nums = [1], target = 0
	Output: -1
*/