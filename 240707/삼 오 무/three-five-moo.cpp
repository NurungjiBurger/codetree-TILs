#include <iostream>
#include <climits>

using namespace std;

long long n, ans = INT_MAX;

bool check(long long mid)
{
    long long cnt = mid / 3 + mid / 5 - mid / 15;

    if (mid - cnt >= n) return true;
    return false;
}

void ps(long long start, long long end)
{
    long long mid;

    while(start <= end)
    {
        mid = (start + end) / 2;

        if(check(mid))
        {
            end = mid - 1;
            ans = min(ans, mid);
        }
        else start = mid + 1;
    }
}

int main() {
    
    cin >> n;

    ps(1, INT_MAX);

    cout << ans;

    return 0;
}