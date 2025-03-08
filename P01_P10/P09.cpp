
// Modified 0803251413 (Orig 081124). 
/* P9 : Union of two sorted arrays

    - BRUTE
        Add elements of both the arrays into a set, 
        Copy the set to a third vector.

    - OPTIMAL code.
        > Iterate across both the arrays.
        > For each element,
            - check if one is less than the other.
            - Also it shouldn't be equal to the 'back' of the union array.
            => if both above conditions are satisfied, 'push' the ele to the final vector.
        > Break out of comparision loop when one of the arrays have finished.
        > Iterate over remaining elements and append them to unionArr.
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
    public:
        vector<int> getUnion_OptimalCode(vector<int>& arr1, vector<int>& arr2);        
        vector<int> getUnion_BruteForce(vector<int>& arr1, vector<int>& arr2);        
};

vector<int> Solution :: getUnion_OptimalCode(vector<int>& arr1, vector<int>& arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    int i=0, j=0;
    vector<int> unionVec;
    if(arr1[i] <= arr2[j]) {
        unionVec.push_back(arr1[i]);
        i++;
    }
    else {
        unionVec.push_back(arr2[j]);
        j++;
    }

    while(i<n1 && j<n2)
    {
        if(arr1[i] <= arr2[j]) {
            if(arr1[i] != unionVec.back())
            {
                unionVec.push_back(arr1[i]);
            }
            i++;
        }
        else {
            if(arr2[j] != unionVec.back())
            {
                unionVec.push_back(arr2[j]);
            }
            j++;
        }
    }

    // Handling the remaining elements.
    while(i < n1) {
        if(arr1[i] != unionVec.back()) {
            unionVec.push_back(arr1[i]);
        }
        i++;
    }

    while(j < n2) {
        if(arr2[j] != unionVec.back()) {
            unionVec.push_back(arr2[j]);
        }
        j++;
    }

    return unionVec;
}

vector<int> Solution :: getUnion_BruteForce(vector<int>& arr1, vector<int>& arr2)
{
    set<int> temp;
    for(const int ele : arr1){
        temp.insert(ele);
    }
    for(const int ele : arr2){
        temp.insert(ele);
    }
    return vector<int> (temp.begin(), temp.end());
}

int main(void) {
    int n1;
    cout << "Enter the array1 size : ";
    cin >> n1;
    int n2;
    cout << "Enter the array2 size : ";
    cin >> n2;

    vector<int> arr1(n1);
    cout << "Enter the " << n1 << " elements of arr1: ";
    for(int i=0; i<n1; i++) {
        cin >> arr1[i];
    }

    vector<int> arr2(n2);
    cout << "Enter the " << n2 << " elements of arr2: ";
    for(int i=0; i<n2; i++) {
        cin >> arr2[i];
    }

    Solution soln = Solution();

    // vector<int> unionVec = soln.getUnion_BruteForce(arr1, arr2);
    vector<int> unionVec = soln.getUnion_OptimalCode(arr1, arr2);

    cout << "\nResult : [ ";
    for(const int ele : unionVec)
        cout << ele << " ";
    cout << "]\n";
    return 0;
}