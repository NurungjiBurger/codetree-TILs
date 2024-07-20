#include <iostream>
using namespace std;

long long n, m, ans = 0;
long long arr[100001];

int main() {

    cin >> n >> m;

    for(int i=0;i<n;i++) cin >> arr[i];

    int left = 0, right = -1;
    int sum = 0;

    while(right < n)
    {
        if (sum >= m)
        {
            if (sum == m) ans++;
            sum -= arr[left++];
        }
        else sum += arr[++right];
    }

    cout << ans;

    return 0;
}