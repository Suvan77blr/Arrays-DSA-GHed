
// Prog to Right-Rotate by 'd'.

#include <iostream>
#include <vector>
using namespace std;

void displayVector(vector<int>& arr);
void reverse(vector<int>& arr, int start, int end);

void rot_by_d(vector<int>& arr, int n, int d){
    if(n==0 || d==0) return;
    d = d%n;
    if(d == 0) return;

    reverse(arr, n-d, n-1);
    reverse(arr, 0, n-d-1);
    reverse(arr, 0, n-1);
}

int main(void){
    int n, d;
    cin >> n;       // cout << "Enter \'n\' : ";
    cin >> d;       // cout << "Enter rot-factor \'d\' : ";

    vector<int> arr(n);
    for(int i=0; i<n; i++){    cin >> arr[i];    }

    cout << "Original Vector : ";
    displayVector(arr);

    rot_by_d(arr, n, d);

    cout << "D-Rotated Vector : ";
    displayVector(arr);
}

void reverse(vector<int>& arr, int start, int end){
    // end--;
    while(start < end){
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;    end--;
    }
}

void displayVector(vector<int>& arr){
    cout << "[ ";
    for(const auto& ele : arr){    cout << ele << " ";      }
    cout << "]\n";
}
