#include <iostream>
#include <algorithm>

using namespace std;

int a, b;
int n;
long long origin = 0;
string ans = "";

int main() {
    
    cin >> a >> b;
    cin >> n;

    long long zari = 1;

    while(n)
    {
        int tmp = n % 10;

        origin += (tmp * zari);

        zari *= a;
        n /= 10;
    }

    while(origin)
    {
        int tmp = origin % b;

        ans += to_string(tmp);

        origin /= b;
    }

    reverse(ans.begin(), ans.end());

    cout << ans;

    return 0;
}