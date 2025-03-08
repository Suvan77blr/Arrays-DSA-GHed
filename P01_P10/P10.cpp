
// Modified 0803251606 (Orig 101124). 
/* P10 : Intersection of two sorted arrays

    - BRUTE
        > Make use of a 'marked array' for one of the given arrays.
        > For every element in either of the arrays, the existance of it in the other is checked and 'marked' accordingly.
        > For handling repeatation, we need to ensure that the 'marked' element is not counted.
        > The marked elements are also added to another, final array.

    - OPTIMAL code.
        > Iterate across both the arrays.
        > For each element,
            - check if one is equal to the other.
                If yes, we add it to final answer & increment both pointers.
            - check if one is less than the other.
                If yes, we increment the less ele's array and rerun the steps.
                Otherwise, we increment the other array and rerun.
        > We stop and break, when one of the arrays is exhausted.            
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> getIntersection_OptimalCode(vector<int>& arr1, vector<int>& arr2);        
        vector<int> getIntersection_BruteForce(vector<int>& arr1, vector<int>& arr2);        
        bool eleExistsInRef(vector<int>& arrRef, vector<bool>& marked, int checkEle);
};

vector<int> Solution :: getIntersection_OptimalCode(vector<int>& arr1, vector<int>& arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    int i=0, j=0;
    vector<int> interVec;
    while(i<n1 && j<n2) {
        if(arr1[i] == arr2[j])
        {
            interVec.push_back(arr1[i]);
            i++; j++;
            continue;
        }
        
        if(arr1[i] < arr2[j]) {
            i++;
        }
        else j++;
    }
    return interVec;
}

vector<int> Solution :: getIntersection_BruteForce(vector<int>& arr1, vector<int>& arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    // Choosing the min sized array for the 'marked' array.

    // bool choice = true if n1 < n2 else false;   
    bool choice = (n1<n2);
    
    // Accordingly nRef (size for reference) & nIter(size for iteration : opposite) is got.
    int nRef = choice ? n1 : n2;
    int nIter = choice ? n2 : n1;
    vector<bool> marked (nRef, false);

    // arrRef : array for reference is got similarly.
    // arrIter : array for iteration is got in the opposite manner.
    vector<int> arrRef = choice ? arr1 : arr2;
    vector<int> arrIter = choice ? arr2 : arr1;

    vector<int> interVec;

    for(int i=0; i<nIter; i++)
    {
        if(eleExistsInRef(arrRef, marked, arrIter[i])) {
            marked[i] = true;
            interVec.push_back(arrIter[i]);
        }
    }
    return interVec;
}

bool Solution :: eleExistsInRef(vector<int>& arrRef, vector<bool>& marked, int checkEle)
{
    int n = arrRef.size();
    for(int i=0; i<n; i++){
        if(arrRef[i]==checkEle && marked[i] == false)
            return true;
        if(arrRef[i] > checkEle)
            break;
    }
    return false;
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

    // vector<int> IntersectionVec = soln.getIntersection_BruteForce(arr1, arr2);
    vector<int> IntersectionVec = soln.getIntersection_OptimalCode(arr1, arr2);

    cout << "\nResult : [ ";
    for(const int ele : IntersectionVec)
        cout << ele << " ";
    cout << "]\n";
    return 0;
}
