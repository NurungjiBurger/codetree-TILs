#include <iostream>
using namespace std;

int n, m;
long long arr[100001], ans = 21e13;

void ps(long long start, long long end)
{
    long long mid;

    while(start <= end)
    {
        // 예상되는 시간
        mid = (start + end) / 2;

        int cnt = 0;
        for(int i=0;i<m;i++) cnt += (int)(mid / arr[i]);

        if (cnt >= n)
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else start = mid + 1;
    }
}


int main() {

    cin >> n >> m;

    long long mini = 21e13, maxi = -21e13;

    for(int i=0;i<m;i++)
    {
        cin >> arr[i];

        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    ps(mini, maxi * n);

    cout << ans;


    return 0;
}