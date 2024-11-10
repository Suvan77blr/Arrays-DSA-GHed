
// 091124
// P11 : Missing Number - BRUTE Soln.

#include <iostream>
#include <vector>
using namespace std;

int findMissingNum(vector<int>& arr, int n){
    int res;
    for(int i = 1; i<=n; i++){
        bool flag = false;
        for(int j = 0; j<n-1; j++){
            if(arr[j] == i){
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            res = i;
            break;
        }
    }
        return res;
}

int main(void){
    int n;
    cout << "Enter \'n\' : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the " << n-1 << " elements : ";
    for(int i = 0; i<n-1; i++){
        cin >> arr[i];
    }

    int missing_no = findMissingNum(arr, n);
    cout << "Missing number : " << missing_no << endl;

    cout << "EOP!\n";
    return 0;
}