#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
set<int> s;

int main() {

    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;

        s.insert(num);
    }

    for(int i=0;i<m;i++)
    {
        int num;
        cin >> num;

        auto iter = s.lower_bound(num);

        if (iter == s.end()) cout << -1 << endl;
        else cout << *iter << endl;
    }
    
    return 0;
}