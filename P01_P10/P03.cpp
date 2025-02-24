
// Modified 250225-0118 (Orig 021124 - MidN of 01). 
/* P3 : Checking if the entered array is sorted.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isSorted(vector<int>& arr)
        {
            int n = arr.size();
            for(int i=0; i<n-1; i++)
            {
                if(arr[i] > arr[i+1])
                    return false;
            }
            return true;
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
    bool bSorted = soln.isSorted(arr);
    cout << (bool(bSorted)?"TRUE":"FALSE") << endl;

    return 0;
}

/*
int getSize(){
	int n;
	cout << "Enter the number of elements : ";
	cin >> n;
	return n;
}

int * createArray(int n)
{
	cout << "Enter the \'" << n << "\' elements of the array : ";
	int * arr = new int[n];
	for(int i = 0; i<n; i++)
		cin >> arr[i];
	return arr;
}	

bool isSorted(int * arr, int size)
{
	for(int i = 1; i<size; i++)
		if(arr[i] < arr[i-1])
			return false;
	return true;
}

int main(void)
{
	int n = getSize();

	int * arr = createArray(n);
	bool result = isSorted(arr, n);

	cout << "Array is : " << (result ? "Sorted.\n" : "Unsorted.\n");

	delete[] arr;
	return 0;
}
*/