
// 181124.
/* // Problem : Given a queue of size 'n', reverse the first 'k' elements of the queue. The other elements remain as they are.
                Use only the STL Queue functions.
*/        

#include <iostream>
#include <queue>
using namespace std;

// Recursive function for reversing the order and sending back the first 'k' elements of the queue.
void reverse_order_and_send_back(queue<int> &q, int k)
{
    if(k == 0)
        return;

    int temp = q.front();
    q.pop();
    reverse_order_and_send_back(q, k-1);
    q.push(temp);
}

queue<int> reverse_first_k(queue<int> q, int k)
{
    // Reversing the order and sending back the first 'k' elements of the queue.
    reverse_order_and_send_back(q, k);

    //Right rotating the queue by 'n-k' places.
    int temp;
    for(int i = 0; i<q.size() - k; i++)
    {
        temp = q.front();
        q.pop();
        q.push(temp);
    }
    return q;
}

void displayQueue(queue<int> &q)
{
    int lim = q.size(), temp;
    cout << "[ ";
    for(int i = 0; i<lim; i++){
        temp = q.front();
        q.pop();
        cout << temp << " ";
        q.push(temp);
    }
    cout << "]\n";
}

int main(void)
{
    int n;
    cout << "Enter 'n' : ";
    cin >> n;

    queue<int> q;
    cout << "Enter the \'" << n << "\' elements of the queue : " ;
    int temp;
    for(int i = 0; i<n; i++){
        cin >> temp;
        q.push(temp);
    }

    int k;
    cout << "Enter 'k' : ";
    cin >> k;

    cout << "Original Queue : ";
    displayQueue(q);

    queue<int> result = reverse_first_k(q, k);

    cout << "First-K-Reversed Queue : ";
    displayQueue(result);

    return 0;
}