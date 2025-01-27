#include <iostream>
#include <vector>
using namespace std;

void displayVector(vector<int>& arr){
    cout << "[ ";
    for(const auto& ele : arr){
        cout << ele << " ";
    }
    cout << "]\n";
}

void reverse(vector<int>& arr, int start, int end){
    int temp;
    while(start < end){
        end--;
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
    }
}

void rot_by_d(vector<int>& arr, int n, int d){
    reverse(arr, n-d, n);
    reverse(arr, 0, n-d);
    reverse(arr, 0, n);
}

int main(void){
    int n,d;
    cout << "Enter \'n\' : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the \'" << n << "\' elements : ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << "Enter rot-factor \'d\' : ";
    cin >> d;

    cout << "Original Vector : ";
    displayVector(arr);

    rot_by_d(arr, n, d);

    cout << "D-Rotated Vector : ";
    displayVector(arr);
}