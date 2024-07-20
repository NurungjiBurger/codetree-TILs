#include <iostream>
#include <map>

using namespace std;

int n;
map<int, int> m;

int main() {
    
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int l, r;
        cin >> l >> r;

        m[l]++;
        m[r]--;
    }

    int last = 0, ans = 0;

    for(auto item : m)
    {
        item.second += last;
        last = item.second;

        ans = max(ans, last);
    }

    cout << ans;


    return 0;
}