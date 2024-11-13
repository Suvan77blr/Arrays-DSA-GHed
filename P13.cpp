
// 131124.
// P13 : Finding the no appearing once, while others appear twice.

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

    int xor1 = 0;
    for(const int& ele : arr)
    {
        xor1 ^= ele;
    }
    cout << xor1 << endl;
}
