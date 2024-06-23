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

    int sum = 0, cnt = 0, mini = 21e8;
    double ans = -1.0;

    while((int)pq.size() != 1)
    {
        int tmp = pq.top();
        sum += tmp;
        cnt++;
        pq.pop();

        mini = min(mini, tmp);

        if (cnt > 2)
        {
            ans = max(ans, (double)(sum - mini) / (cnt - 1));
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << ans;

    return 0;
}