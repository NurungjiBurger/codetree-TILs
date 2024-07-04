#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {

    cin >> n;

    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            if (pq.empty()) cout << 0;
            else
            {
                cout << pq.top();
                pq.pop();
            }
            cout << endl;
        }
        else pq.push(x);
    }


    return 0;
}