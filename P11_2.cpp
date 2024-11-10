#include <iostream>
#include <vector>
using namespace std;

void displayVector(vector<int>& arr){
    cout << "[ ";
    for(const int& ele : arr){
        cout << ele << " ";
    }cout << "]\n";
}

int main(void){
    int n;
    cout << "Enter \'n\' : ";
    cin >> n;
    
    vector<int> arr(n-1);
    cout << "Enter the \'" << (n-1) << "\' elements : ";
    for(int i = 0; i<n-1; i++){
        cin >> arr[i];
    }

    vector<bool> hash(n+1, false);
    // for(int i=0; i<n-1; i++){
    //     hash[arr[i]] = true;
    // }

    for(const int ele : arr){
        hash[ele] = true;
    }

    int result;
    for(int i=1; i<hash.size(); i++){
        if(hash[i] == false){
            result = i;
            break;
        }
    }

    cout << "Orig Vector : ";
    displayVector(arr);

    cout << "\nMissing Number : " << result << endl;
}