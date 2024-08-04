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

        auto iter = removed.find(num);
        long long tmp = num;
        ans = -21e8;

        // logN * 10만
        for(;iter != removed.begin();iter--)
        {
            ans = max(ans, (tmp - *iter) - 1);
            tmp = *iter;
        }
        tmp = *iter;
        ans = max(ans, (tmp - 0));

        // left 확인

        // right 확인
        iter = removed.find(num);
        tmp = num;

        for(;iter != removed.end();iter++)
        {
            ans = max(ans, (*iter - tmp) - 1);
            tmp = *iter;
        }
        ans = max(ans, n - tmp);


        cout << ans << endl;
    }


    return 0;
}