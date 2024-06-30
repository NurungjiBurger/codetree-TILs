#include <iostream>

using namespace std;

int n, ans = -21e8;
int cnt[200001];

int main() {
    
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int l, r;
        cin >> l >> r;

        cnt[l]++;
        cnt[r]--;
    }

    int last = 0;
    for(int i=0;i<200001;i++)
    {
        cnt[i] += last;
        last = cnt[i];

        ans = max(ans, cnt[i]);
    }

    cout << ans;


    return 0;
}