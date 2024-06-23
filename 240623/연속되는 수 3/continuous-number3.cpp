#include <iostream>

using namespace std;

int n, last = 0, ans = -21e8, cnt = 0;

int main() {
    
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;

        if (last == 0) cnt = 1;
        else
        {
            if (num > 0 && last < 0) cnt = 1;
            else if (num < 0 && last > 0) cnt = 1;
            else cnt++;
        }

        last = num;
        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}