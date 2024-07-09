#include <iostream>
#include <set>

using namespace std;

int n, m, ans = 21e8;
set<int> s;

int main() {

    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;

        s.insert(num);

        if (s.size() > 1)
        {
            auto iter = s.find(num);

            if (iter != s.begin())
            {
                iter--;
                //cout << "left : " << *iter << " " << num << endl;
                if (abs(num - *iter) >= m) ans = min(ans, abs(num - *iter));
            }

            iter = s.find(num);

            iter++;

            if (iter != s.end())
            {
                //cout << "right : " << *iter << " " << num << endl;
                if (abs(num - *iter) >= m) ans = min(ans, abs(num - *iter));
            }
        }
    }

    if (ans == 21e8) ans = -1;
    cout << ans;

    return 0;
}