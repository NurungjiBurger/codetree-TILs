#include <iostream>

using namespace std;

int n, m;
int arr[10001];

bool check(long long num)
{
    int cnt = 0;

    for(int i=0;i<n;i++)
    {
        cnt += (arr[i] / num);
    }

    if (cnt >= m) return true;

    return false;
}

long long bs(long long left, long long right)
{
    long long mid;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if (check(mid)) left = mid + 1;
        else right = mid - 1;
    }

    return right;
}

int main() {

    cin >> n >> m;

    for(int i=0;i<n;i++) cin >> arr[i];

    cout << bs(1, 10000);

    return 0;
}