#include <iostream>

using namespace std;

int n, ans = 21e8;
int arr[100001];
long long s, sum;

int main() {
    
    cin >> n >> s;

    for(int i=0;i<n;i++) cin >> arr[i];

    sum = 0;
    int left = 0, right = -1;

    while(right < n)
    {
        if (sum >= s) 
        {
            ans = min(ans, (right - left + 1));
            sum -= arr[left];
            left++;
        }
        else
        {
            right++;
            sum += arr[right];
        }
    }

    if (ans == 21e8) ans = -1;
    cout << ans;


    return 0;
}