
// 101124 (midnigth of 11th)
// P10 : Intersection of 2 arrays.

#include <iostream>
#include <vector>
using namespace std;


int getSize(){
	cout << "\tEnter the size of the vector : ";
	int n;
	cin >> n;
	return n;
}

void getVector(vector<int>& v, int n){
	cout << "\tEnter the " << n << " vector elements : ";
	for(int i = 0; i<n; i++){
		cin >> v[i];
	}
}

void displayVector(vector<int> v){
	cout << "[ ";
	for(const int& ele : v){
		cout << ele << " ";
	}cout << "]\n";
}

vector<int> intersection(vector<int>& v1, int n1, vector<int>& v2, int n2){
    vector<int> res;

    int i=0,j=0;
    while(i<n1 && j<n2){
        if(v1[i] == v2[j]){
            res.push_back(v1[i]);
            i++; j++;
        }
        else{
            if(v1[i] < v2[j]){
                i++;
            }
            else{
                j++;
            }
        }
    }

    return res;
}

int main(){

    cout << "For Vector 1 : \n";
    int n1 = getSize();
    vector<int> v1(n1);
    getVector(v1, n1);

    cout << "For Vector 2 : \n";
    int n2 = getSize();
    vector<int> v2(n2);
    getVector(v2, n2);

    vector<int> result = intersection(v1, n1, v2, n2);
    
    cout << "Results : \n";
    cout << "Vector 1 : ";
    displayVector(v1);

    cout << "Vector 2 : ";
    displayVector(v2);
    
    cout << "Intersection Vec : ";
    displayVector(result);

    cout << "EOP!\n";
    return 0;
}