#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;
unordered_set<int> usA;
unordered_set<int> usB;
unordered_set<int> ans;

int main() {
    
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;

        usA.insert(num);
    }

    for(int i=0;i<m;i++)
    {
        int num;
        cin >> num;

        usB.insert(num);
    }

    for(auto item : usA)
    {
        if (usB.count(item) == 0) ans.insert(item);
    }

    for(auto item : usB)
    {
        if (usA.count(item) == 0) ans.insert(item);
    }

    cout << ans.size();


    return 0;
}