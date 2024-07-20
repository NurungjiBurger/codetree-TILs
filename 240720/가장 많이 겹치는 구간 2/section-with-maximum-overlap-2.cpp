#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> vec;

int ans = 0;

int main() {
    
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int l, r;
        cin >> l >> r;

        vec.push_back({l, 1});
        vec.push_back({r, -1});
    }

    sort(vec.begin(), vec.end());

    int last = 0;

    for(int i=0;i<2*n;i++)
    {
        last += vec[i].second;

        ans = max(ans, last);
    }

    cout << ans;



    return 0;
}