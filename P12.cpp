
// 121124
// P12 : Maximum consequtive 1s.

#include <iostream>
using namespace std;

int main(void)
{


    int n;
    cout << "Enter \'n\' : ";
    cin >> n;

    
    cout << "Enter the " << n << " elements : ";
    int * arr = new int[n];
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }

    int count = 0;
    int temp = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==1)
        {
            ++temp;
            if(count < temp){
                count = temp;
            }
        }
        else{
            temp = 0;
        }
    }

    cout << "Max 1s count : " << count << endl;
    cout << "EOP!\n";
    return 0;
}