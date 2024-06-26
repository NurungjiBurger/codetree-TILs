#include <iostream>
#include <set>

using namespace std;

int n, ans = 21e8;
set<int> s;

int main() {
    
    s.insert(0);

    cin >> n;

    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;

        s.insert(num);

        auto iter = s.find(num);

        int a, b;

        if (++iter != s.end()) 
        {
            b = *iter;
            ans = min(ans, b - num);
        }

        --iter;
        --iter;
        a = *iter;

        ans = min(ans, num - a);

        cout << ans << endl;
    }

    return 0;
}