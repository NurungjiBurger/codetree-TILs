#include <iostream>

using namespace std;

int n, t, ans = 0;
int arr[1001];

int main() {
    
    cin >> n >> t;

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if (arr[i] > t) cnt++;
        else cnt = 0;

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}