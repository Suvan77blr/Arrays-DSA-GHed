
// 091124
// P9 : Union of Two Arrays.

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

int main(void){
    cout << "For Vector 1 : " << endl;
	int n1 = getSize();
	vector<int> v1(n1);
	getVector(v1, n1);

	cout << "For Vector 2 : " << endl;
	int n2 = getSize();
	vector<int> v2(n2);
	getVector(v2, n2);

    vector<bool> temp(n2, false);
    vector<int> u;

    for(int i = 0; i<n1; i++){
        for(int j = 0; j<n2; j++){
            if(v1[i] == v2[j] and temp[j] != true){
                u.push_back(v2[j]);
                temp[j] = true;
                break;
            }
            if(v1[i] < v2[j])
                break;
        }
    }

    displayVector(u);
}