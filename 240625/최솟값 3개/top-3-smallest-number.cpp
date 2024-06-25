#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;

        pq.push(num);

        if (pq.size() >= 3)
        {
            int a, b, c;
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            c = pq.top();
            pq.pop();

            cout << (long long)a * b * c << endl;

            pq.push(a);
            pq.push(b);
            pq.push(c);
        }
        else cout << -1 << endl;
    }

    return 0;
}