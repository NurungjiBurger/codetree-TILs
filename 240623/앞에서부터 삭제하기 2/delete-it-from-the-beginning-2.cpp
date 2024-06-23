#include <iostream>
#include <queue>

using namespace std;

int n, k;
double ans = -1.0;
int arr[100001];

int main() {
    
    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    for(int i=1;i<n-2;i++)
    {
        int sum = 0, cnt = 0, mini = 21e8;
        for(int j=i;j<n;j++)
        {
            sum += arr[j];
            cnt++;

            mini = min(mini, arr[j]);
        }

        ans = max(ans, (double)(sum - mini) / (cnt - 1));
    }

    cout << fixed;
    cout.precision(2);
    cout << ans;

    return 0;
}