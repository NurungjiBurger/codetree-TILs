#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> a;
unordered_set<int> b;
unordered_set<int> ans;

int main() {

    int n, m;
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;

        a.insert(num);
    }

    for(int i=0;i<m;i++)
    {
        int num;
        cin >> num;

        b.insert(num);
    }

    for(auto item : a) if (b.count(item) == 0) ans.insert(item);
    for(auto item : b) if (a.count(item) == 0) ans.insert(item);

    cout << ans.size();

    return 0;
}