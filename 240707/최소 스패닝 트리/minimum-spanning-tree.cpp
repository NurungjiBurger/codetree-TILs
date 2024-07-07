#include <iostream>
#include <queue>

using namespace std;

struct Info{
    int from;
    int to;
    int cost;
    bool operator<(Info right) const {
        return cost > right.cost;
    }
};

int unf[10001];
int n, m;
priority_queue<Info> pq;

void init()
{
    for(int i=0;i<=n;i++) unf[i] = i;
}

int find(int tar)
{
    if (tar == unf[tar]) return tar;
    return unf[tar] = find(unf[tar]);
}

bool Union(int a, int b)
{
    int ua = find(a);
    int ub = find(b);

    if (ua == ub) return false;

    unf[ua] = ub;
    return true;
}

int main() {

    cin >> n >> m;

    init();

    for(int i=0;i<m;i++)
    {
        int f, t, c;
        cin >> f >> t >> c;

        pq.push({f, t, c});
    }

    int cnt = 0;
    int ans = 0;

    while(cnt != n - 1)
    {
        Info now = pq.top();
        pq.pop();

        if (Union(now.from, now.to)) 
        {
            ans += now.cost;
            cnt++;
        }
    }

    cout << ans;


    return 0;
}