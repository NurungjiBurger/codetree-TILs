#include <iostream>
#include <unordered_map>

using namespace std;

long long ans = 0;
int n;
unordered_map<int, int> um;

int main() {
    
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int x, y;
        cin >> x >> y;

        if (um.count(x) == 0) um[x] = y;
        else um[x] = min(um[x], y);
    }

    for(auto item : um)
    {
        ans += item.second;
    }

    cout << ans;

    return 0;
}