#include <iostream>
#include <queue>

using namespace std;

int n, k;
priority_queue<int> pq;

int main() {
    
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;

        pq.push(num);
    }

    int sum = 0, cnt = 0;
    double ans = -1.0;

    while((int)pq.size() != 1)
    {
        sum += pq.top();
        cnt++;
        pq.pop();

        if (cnt > 1)
        {
            ans = max(ans, (double)sum / cnt);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << ans;

    return 0;
}