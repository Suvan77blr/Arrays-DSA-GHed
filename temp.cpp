
// 081124
// tmp (p8) : union of 2 sorted arrays.

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

int main(){
	cout << "For Vector 1 : " << endl;
	int n1 = getSize();
	vector<int> v1(n1);
	getVector(v1, n1);

	cout << "For Vector 2 : " << endl;
	int n2 = getSize();
	vector<int> v2(n2);
	getVector(v2, n2);

	vector<int> res;

	int i = 0, j = 0;

	while(i<n1 && j<n2){
		if(v1[i] < v2[j]){
			if(res.size() == 0 or res.back()!=v1[i])
			{
				res.push_back(v1[i]);
			}
			i++;
		}
		else{
			if(res.size() == 0 || res.back()!=v2[j])
			{
				res.push_back(v2[j]);
			}
			j++;
		}
	}
	while(i<n1){
		if(res.size() == 0 || res.back()!=v1[i])
		{
			res.push_back(v1[i]);
		}
		i++;
	}

	while(j<n2){
		if(res.size() == 0 || res.back()!=v2[j])
		{
			res.push_back(v2[j]);
		}
		j++;
	}

	cout << "Union of v1 and v2 : ";
	displayVector(res);

	cout << "EOP!" << endl;
	return 0;
}


	/*
	   //BRUTE - FORCE.
	set<int> st;
	for(int i=0; i<v1.size(); i++){
		st.insert(v1[i]);
	}

	for(int i=0; i<v2.size(); i++){
		st.insert(v2[i]);
	}

	cout << "Union of given vectors : { ";
	for(auto it = st.begin(); it!=st.end(); it++){
		cout << *it << " ";
	}
	cout << "}\n";
//	*/

/*
//My Two pointer approach.
	int i = 0, j=0;
	vector<int> u;
	int temp = (v1[0] < v2[0]) ? v1[0] : v2[0];
	u.push_back(temp);

	for(; i<v1.size() && j<v2.size(); )
	{
		if(v1[i] < v2[j] ){
			if(temp != v1[i])
			{	
				temp = v1[i];
				u.append(temp);
			}
			i++;		
		}
		else{
			if(temp != v2[j])
			{	
				temp = v2[j];
				u.append(temp);
			}
			j++;		
		}
	}
	while(i < v1.size() ){
		u.append(v1[i]);
		i++;
	}

	while(j < v2.size() ){
		u.append(v2[j]);
		j++;
	}
*/