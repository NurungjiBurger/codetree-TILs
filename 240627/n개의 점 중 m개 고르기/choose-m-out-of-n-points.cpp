#include <iostream>
#include <vector>

using namespace std;

struct Point{
    int x;
    int y;
};

int n, m, ans = 21e8;
Point arr[21];
int c[21];
vector<Point> vec;

void check()
{
    int tmp = -21e8;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if (i == j) continue;

            int xdif = arr[c[i]].x - arr[c[j]].x;
            int ydif = arr[c[i]].y - arr[c[j]].y;
            int dist = (xdif*xdif) + (ydif*ydif);

            tmp = max(tmp, dist);
        }
    }
    ans = min(ans, tmp);
}

void dfs(int depth, int idx)
{
    if (depth == m)
    {
        check();
        return;
    }

    for(int i=idx;i<n;i++)
    {
        c[depth] = i;
        dfs(depth + 1, i + 1);
    }
}

int main() {
    
    cin >> n >> m;

    for(int i=0;i<n;i++) cin >> arr[i].x >> arr[i].y;

    dfs(0, 0);

    cout << ans;

    return 0;
}