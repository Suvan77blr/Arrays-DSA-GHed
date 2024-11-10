
// 031124
// NetNinja Sum to get both the 2nd maxi and 2nd Mini element, ~ (P2.cpp)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.

    int maxi = a[0], sec_maxi = INT_MIN;
    int mini = a[0], sec_mini = INT_MAX;

    for(int i=1; i<n; i++)
    {
        if(a[i] > maxi){
            sec_maxi = maxi;
            maxi = a[i];
        }

        if(a[i] > sec_maxi && a[i]!=maxi){
            sec_maxi = a[i];
        }

        if(a[i] < mini){
            sec_mini = mini;
            mini = a[i];
        }
        if(a[i] < sec_mini && a[i]!=mini){
            sec_mini = a[i];
        }
    }

    vector<int> res{sec_maxi, sec_mini};
    return res;
}

int main(void){
	int n;
	cout << "Enter \'n\' : ";
	cin >> n;


	vector<int> arr;
	int temp;
	cout << "Enter the \'"<< n << "\' elements :\n";
	for(int i = 0; i<n; i++)
	{
		cin >> temp;
		arr.emplace_back(temp);
	}

	vector<int> sec_MaxiMini = getSecondOrderElements(n, arr);
	for(const auto& ele : sec_MaxiMini)
		cout << ele << " ";
	cout << endl;

	return 0;
}
