#include <iostream>

using namespace std;

int n, k, ans = -21e8;
int arr[100001];

int main() {

    cin >> n >> k;

    for(int i=0;i<n;i++) cin >> arr[i];

    int left = 0;
    int sum = 0;
    for(int i=0;i<k;i++) sum += arr[i];

    ans = sum;

    for(int i=k;i<n;i++)
    {
        sum -= arr[left++];
        sum += arr[i];

        ans = max(ans, sum);
    }

    cout << ans;


    return 0;
}