#include <iostream>
#include <set>

using namespace std;

struct Prob{
    int num;
    int hard;
    bool operator<(Prob right) const{
        if (hard == right.hard) return num < right.num;
        return hard < right.hard;
    }
};

int n, m;
set<Prob> s;

int main() {

    cin >> n;

    for(int i=0;i<n;i++)
    {
        int p, l;
        cin >> p >> l;

        s.insert({p, l});
    }

    cin >> m;

    for(int i=0;i<m;i++)
    {
        string cmd;
        int x, p, l;

        cin >> cmd;

        if (cmd == "rc")
        {
            cin >> x;

            if (x == 1)
            {
                auto iter = s.end();
                iter--;
                cout << iter->num;
            }
            else
            {
                auto iter = s.begin();
                cout << iter->num;
            }
            cout << endl;
        }
        else if (cmd == "ad")
        {
            cin >> p >> l;

            s.insert({p, l});
        }
        else if (cmd == "sv")
        {
            cin >> p >> l;

            s.erase({p, l});
        }
    }

    return 0;
}