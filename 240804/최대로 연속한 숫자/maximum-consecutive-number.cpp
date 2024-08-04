#include <iostream>
#include <set>

using namespace std;

long long n, m, ans = -21e8;
set<long long> removed;

int main() {

    cin >> n >> m;

    // arr 라는 곳에 0 ~ n 까지 있다고 가정

    for(int i=0;i<m;i++)
    {
        long long num;
        cin >> num;

        removed.insert(num);

        auto iter = removed.lower_bound(num);
        long long tmp = num;
        ans = -21e8;

        // logN * 10만

        // left 확인
        while(true)
        {
            ans = max(ans, (tmp - *iter) - 1);
            tmp = *iter;

            if (iter == removed.begin())
            {
                ans = max(ans, (tmp - 0));
                break;
            }

            iter--;
        }
        // right 확인
        iter = removed.lower_bound(num);
        tmp = num;
        while(true)
        {
            if (iter == removed.end()) 
            {
                ans = max(ans, n - tmp);
                break;
            }
            ans = max(ans, (*iter - tmp) - 1);
            tmp = *iter;

            iter++;
        }

        cout << ans << endl;
    }


    return 0;
}