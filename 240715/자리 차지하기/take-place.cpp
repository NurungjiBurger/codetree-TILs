#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n, m, ans = 0;
int arr[100001];
set<int> s;

int main() {

    cin >> n >> m;

    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=1;i<=m;i++) s.insert(i);

    for(int i=0;i<n;i++)
    {
        auto iter = s.upper_bound(arr[i]);

        if (iter == s.begin()) break;

        iter--;
        
        ans++;
        s.erase(iter);
    }

    cout << ans;

    return 0;
}