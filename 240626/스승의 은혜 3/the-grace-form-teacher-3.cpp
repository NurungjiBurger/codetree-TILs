#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct price{
    int p;
    int s;
    bool operator<(price right) const{
        return (p + s) < (right.p + right.s);
    }
};

int n, b, ans = 0;
vector<price> arr;

int main() {

    cin >> n >> b;

    for(int i=0;i<n;i++)
    {
        int p, s;
        cin >> p >> s;

        arr.push_back({p, s});
    }

    sort(arr.begin(), arr.end());

    for(int idx=0;idx<n;idx++)
    {
        // idx -> 할인 품목
        int sum = ((arr[idx].p / 2) + arr[idx].s), cnt = 1;
        for(int i=0;i<n;i++)
        {
            if (idx == i) continue;
            else sum += (arr[i].p + arr[i].s);

            if (sum > b) break;

            cnt++;
            ans = max(ans, cnt);
        }
    }

    cout << ans;

    return 0;
}