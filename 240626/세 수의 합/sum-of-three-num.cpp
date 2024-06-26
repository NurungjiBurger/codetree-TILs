#include <iostream>
#include <unordered_map>

using namespace std;

int n, k, ans = 0;
int arr[1001];
unordered_map<long long, int> um;

int main() {

    cin >> n >> k;

    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            long long sum = (long long)arr[i] + arr[j];

            long long diff = (long long)k - sum;

            ans += um[diff];
        }
        um[arr[i]]++;
    }
    
    cout << ans;

    return 0;
}