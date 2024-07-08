#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, x;
vector<int> arr;

int main() {
    
    cin >> n >> m;

    for(int i=0;i<n;i++) 
    {
        cin >> x;

        arr.push_back(x);
    }

    for(int i=0;i<m;i++)
    {
        cin >> x;

        auto iter = lower_bound(arr.begin(), arr.end(), x);

        if (iter == arr.end() || *iter != x) cout << -1;
        else cout << (int)(iter - arr.begin()) + 1;

        cout << endl;
    }

    return 0;
}