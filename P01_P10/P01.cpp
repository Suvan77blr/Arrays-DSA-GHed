
// Modified 250225-0055 (Orig 311024). 
// P1 : Largest Element in an array.
//      - Getting the maxi index only.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int getLargestElementIndex(vector<int>& arr) 
        {  
            int n = arr.size();
            int maxi_pos = 0;
            for(int i=1; i<n; i++)
            {
                if(arr[maxi_pos] < arr[i])
                    maxi_pos = i;
            }
            return maxi_pos;
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
    int largestEleIndex = soln.getLargestElementIndex(arr);
    cout << "Largest element : " << arr[largestEleIndex] << endl;

    return 0;
}


/*
Orig Code. 
#include <climits>
int main(void)
{
	int arr[] = {3, 2, 1, 5, 2};
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Current array : ";

	int maxi = INT_MIN;
	for(int i = 0; i<size; i++)
	{
		if(maxi < arr[i])
			maxi = arr[i];
		printf("%d ",arr[i]);
	}
	printf("\n");

	cout << "Max element in Array : " << maxi << endl;
	printf("EOP!\n");
	return 0;
}
*/