
// 051124
// P4 : Removing duplicates from a sorted array.

#include <iostream>
using namespace std;


inline int getNumber(){
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    return n;
}

int * getArray(int n){
    cout << "Enter the \'" << n << "\' elements : ";
    int * arr = new int[n];
    // int * arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    return arr;
}

int getUnique(int * arr, int n){
    int temp = arr[0], fast = 1, slow = 1;
    while(fast < n){
        if(arr[fast] != temp){
            temp = arr[fast];
            arr[slow] = temp;
            slow++;
        }
        fast++;
    }
    return slow;
}

int main(void){
    int n = getNumber();
    int * arr = getArray(n);

    int unique = getUnique(arr, n);

    cout << "Unique elements : " << unique;
    cout << "\nSet : [ ";
    for(int i = 0; i<unique; i++){
        cout << arr[i] << " ";
    }
    cout << "]";

    cout << "\nEOP!\n";
    delete[] arr;
    return 0;
}
