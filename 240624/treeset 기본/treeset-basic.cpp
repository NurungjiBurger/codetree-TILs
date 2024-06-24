#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n;
set<int> s;

int main() {
    
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int x;
        string cmd;
        cin >> cmd;

        if (cmd == "add")
        {
            cin >> x;

            s.insert(x);
        }
        else if (cmd == "remove")
        {
            cin >> x;

            s.erase(x);
        }
        else if (cmd == "find")
        {
            cin >> x;

            if (s.count(x) == 0) cout << "false\n";
            else cout << "true\n";
        }
        else if (cmd == "lower_bound")
        {
            cin >> x;

            auto it = s.lower_bound(x);

            if (it != s.end()) cout << *it << "\n";
            else cout << "None\n";
        }
        else if (cmd == "upper_bound")
        {
            cin >> x;

            auto it = s.upper_bound(x);

            if (it != s.end()) cout << *it << "\n";
            else cout << "None\n";
        }
        else if (cmd == "largest")
        {
            if ((int)s.size() == 0) cout << "None\n";
            else 
            {
                auto it = s.end();
                it--;
                cout << *it << "\n";
            }
        }
        else if (cmd == "smallest")
        {
            if ((int)s.size() == 0) cout << "None\n";
            else
            {
                auto it = s.begin();
                cout << *it << "\n";
            }
        }
    }

    return 0;
}