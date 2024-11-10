
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>> res;

   int len = arr.size();
   int curr_ele, second;
   for(int i = 0; i<len-1; i++)
   {
      curr_ele = arr[i];
      for(int j = i+1; j<len; j++)
      {
         second = arr[j];
         if(curr_ele + second == s)
         {
            if(curr_ele > second){
               curr_ele = curr_ele^second;
               second = curr_ele^second;
               curr_ele = curr_ele^second;
            }
            res.push_back({curr_ele, second});
         }
      }
   }

   sort(res.begin(), res.end(), [](vector<int>& a, vector<int>& b){
      return (a[0] < b[0]);
   });

   return res;
}

int main(void)
{
	int n, s;
//	cout << "Enter the \'n\' elements : ";
	cin >> n;

//	cout << "Enter the sum value \'s\' : ";
	cin >> s;

	vector<int> arr;
//	cout << "Enter the \'" << n << "\' elements :\n";
	int temp;
	for( int i = 0; i<n; i++)
	{
		cin >> temp;
		arr.emplace_back(temp);
	}


	vector< vector<int> > result = pairSum(arr, s);

	for(const auto& i : result)
	{
		for(const auto& j : i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}
