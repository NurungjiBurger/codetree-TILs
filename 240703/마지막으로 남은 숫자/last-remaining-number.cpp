#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> pq;

int main() {

    cin >> n;

    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;

        pq.push(num);
    }

    while((int)pq.size() >= 2)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int diff = abs(a - b);

        if (diff != 0) pq.push(diff);
    }

    if (pq.empty()) cout << -1;
    else cout << pq.top();

    return 0;
}