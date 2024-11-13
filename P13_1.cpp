
// 131124
// P13_1 : Finding the no that appears only once, while all others appear twice. (BETTER)

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(void)
{
    unordered_set<int> ust;
    int n;
    cout << "Enter n : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the " << n << " elements : ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    for(const int& ele : arr)
    {
        if(ust.find(ele) == ust.end()){
            ust.insert(ele);
        }
        else{
            ust.erase(ele);
        }
    }

    cout << *(ust.begin()) << endl;
    return 0;
}
