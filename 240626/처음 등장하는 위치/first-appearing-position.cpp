#include <iostream>
#include <map>

using namespace std;

int n;
map<int, int> m;

int main() {
    
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        int num;
        cin >> num;

        if (m.count(num) == 0) m[num] = i;
    }

    for(auto it = m.begin();it != m.end();it++)
    {
        cout << it->first << " " << it->second << endl;
    }


    return 0;
}