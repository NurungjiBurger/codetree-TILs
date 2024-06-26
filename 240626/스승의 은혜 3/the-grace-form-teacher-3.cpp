#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct price{
    int p;
    int s;
    bool operator<(price right) const{

        if (p + s == right.p + right.s) return p < right.p;
        return p + s < right.p + right.s;
    }
};

int n, b, ans = -21e8;
price arr[1001];

int main() {

    cin >> n >> b;

    for(int i=0;i<n;i++)
    {
        cin >> arr[i].p >> arr[i].s;
    }

    sort(arr, arr + n);

    for(int idx=0;idx<n;idx++)
    {
        // idx -> 할인 품목
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            if (idx == i) sum += ((arr[i].p/2) + arr[i].s);
            else
            {
                sum += (arr[i].p + arr[i].s);
            }

            if (sum > b)
            {
                ans = max(ans, i);
                break;
            }
        }

    }

    cout << ans;

    return 0;
}