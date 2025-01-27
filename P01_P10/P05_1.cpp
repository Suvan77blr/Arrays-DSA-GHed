
// 091124
// P5_1 : Right Rotating the array by 1.

#include <iostream>
#include <vector>
using namespace std;

void displayVector(vector<int>& v){
    cout << "[ ";
    for(int& ele : v){
        cout << ele << " ";
    }
    cout << "]\n";
}

void rot_by_one(vector<int>& v, int n){
    int temp = v[n-1];
    for(int i = n-1; i>0; i--){
        v[i] = v[i-1];
    }
    v[0] = temp;
}

int main(void){
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    cout << "Enter the \'" << n << "\' elements : ";
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }

    cout << "Original vector : ";
    displayVector(v);

    rot_by_one(v, n);

    cout << "Rotated vector : ";
    displayVector(v);

    cout << "EOP!\n";
}