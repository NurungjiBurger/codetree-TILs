#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
unordered_map<string, int> um;

int main() {
    
    cin >> n;

    for(int i=0;i<n;i++)
    {
        string str;
        cin >> str;

        sort(str.begin(), str.end());

        um[str]++;
    }

    int ans = -21e8;

    for(auto item : um)
    {
        ans = max(ans, item.second);
    }

    cout << ans;

    return 0;
}