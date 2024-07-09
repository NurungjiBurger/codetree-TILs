#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n, m, ans = 21e8;
int arr[100001];
set<int> s;

int main() {

    cin >> n >> m;

    for(int i=0;i<n;i++) 
    {
        int num;
        cin >> num;

        s.insert(num);
    }

    for(auto item : s)
    {
        // 차이가 m 이상
        // lowerbound(arr[i] + m)
        auto iter = s.lower_bound(item - m);
        
        if (iter != s.end() && item - *iter >= m) ans = min(ans, abs(*iter - item));

        iter = s.lower_bound(item + m);

        if (iter != s.end() && *iter - item >= m) ans = min(ans, abs(*iter - item));
    }

    if (ans == 21e8) ans = -1;
    cout << ans;

    return 0;
}