#include <iostream>
#include <queue>

using namespace std;

double ans = -21e8;
priority_queue<int, vector<int>, greater<int>> pq;
int arr[100001];
int n;

int main() {

    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    
    int sum = 0, cnt = 0;
    for(int i=n-1;i>0;i--)
    {
        sum += arr[i];
        cnt++;

        pq.push(arr[i]);

        if ((int)pq.size() >= 2) ans = max(ans, ((double)sum - pq.top()) / (cnt - 1));
    }

    cout << fixed;
    cout.precision(2);

    cout << ans;

    return 0;
}