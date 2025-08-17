
// 170825.
/*
    P04_2: Removing Duplicates, atmost 2 are allowed.
        Soln1: Using map<int, int> to store freq of each.
               - Any mp[num] > 2, trim it to mp[num] = 2 and replace it in the original array.
               
        Soln2: Two Pointers.
               - 
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
using vi =  vector<int>;
void displayVector(vi& arr, int n);

// Solution1: Using 2 pointers.
int removeDuplicates_Soln1(vi& arr, int n) {
    if(n <= 2) return n;

    int slow = 2;
    for(int fast = 2; fast<n; fast++) {
        if(arr[slow-2] == arr[fast]) continue;
        arr[slow] = arr[fast];
        slow++;
    }
    return slow;
}

int removeDuplicates_Soln2(vi& arr, int n) {
    map<int, int> mp;
    for(int num: arr) {
        mp[num]++;
    }

    int idx = 0;
    for(auto it: mp) {
        if(it.second > 2) { it.second = 2;  }
        while(it.second-- > 0) {
            arr[idx++] = it.first;
        }
    }
    return idx;
}

int main(void) {
    int n;  cin >> n;

    vi arr(n);
    for(int i=0; i<n; i++) {    cin >> arr[i];     }

    cout << "Orig Vec: ";
    displayVector(arr, n);
    
    int newLength = removeDuplicates_Soln1(arr, n);
    // int newLength = removeDuplicates_Soln2(arr, n);

    cout << "NEW Vec: ";
    displayVector(arr, newLength);
}

void displayVector(vi& arr, int n) {
    cout << "[ ";
    for(int i=0; i<n; i++) { cout << arr[i] << " "; }
    cout << "]\n";

}