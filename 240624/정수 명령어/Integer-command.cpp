#include <iostream>
#include <set>

using namespace std;

int t, k;

int main() {
    
    cin >> t;

    for(int tc=1;tc<=t;tc++)
    {
        cin >> k;

        set<int> s;

        for(int i=0;i<k;i++)
        {
            int n;
            char cmd;
            cin >> cmd;
            cin >> n;

            if (cmd == 'I')
            {       
                s.insert(n);
            }
            else if (cmd == 'D')
            {
                if (n == 1)
                {
                    if ((int)s.size() == 0) continue;

                    auto it = s.end();
                    it--;

                    s.erase(it);
                }
                else if (n == -1)
                {
                    if ((int)s.size() == 0) continue;

                    auto it = s.begin();

                    s.erase(it);
                }
            }
        }

        if ((int)s.size() == 0) cout << "EMPTY\n";
        else 
        {
            auto st = s.begin();
            auto en = s.end();
            en--;

            cout << *en << " " << *st << "\n";
        }
    }

    return 0;
}