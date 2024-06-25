#include <iostream>

using namespace std;

int x, y;
int ans = 0;

int main() {
    
    cin >> x >> y;

    for(int i=x;i<=y;i++)
    {
        string str = to_string(i);

        int l, r;
        l = 0;
        r = (int)str.length() - 1;

        bool ispel = true;
        while(l<r)
        {
            if (str[l] != str[r])
            {
                ispel = false;
                break;
            }
            l++;
            r--;
        }

        if (ispel) ans++;
    }

    cout << ans;

    return 0;
}