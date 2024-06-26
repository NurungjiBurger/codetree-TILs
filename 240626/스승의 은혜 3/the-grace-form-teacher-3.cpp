#include <iostream>
#include <queue>

using namespace std;

struct Data{
    int num;
    int cnt;
    int cost;
    bool coupon;
};

int n, b, ans = -21e8;
int p[1001], s[1001];


int main() {

    cin >> n >> b;

    for(int i=0;i<n;i++)
    {
        cin >> p[i] >> s[i];
    }

    queue<Data> que;
    que.push({-1, 0, 0, true});

    while(!que.empty())
    {
        Data now = que.front();
        que.pop();

        for(int i=0;i<3;i++)
        {
            int next = now.num + 1;
            int cost = now.cost;
            int cnt = now.cnt;
            bool coupon = now.coupon;

            switch(i)
            {
                case 0:
                    if (coupon)
                    {
                        // 쿠폰 있고 쿠폰 사용
                        coupon = false;
                        cost += ((p[next]/2) + s[next]);
                        cnt = now.cnt + 1;
                    }
                    break;
                case 1:
                    // 쿠폰 유무 상관없이 정가 구매
                    cost += (p[next] + s[next]);
                    cnt = now.cnt + 1;
                    break;
                case 2:
                    cost = now.cost;
                    cnt = now.cnt;
                    break;
                default:
                    break;
            }

            if (cost > b) continue;
            if (next >= n) continue;

            ans = max(ans, cnt);
            que.push({next, cnt, cost, coupon});

        }
    }

    cout << ans;


    return 0;
}