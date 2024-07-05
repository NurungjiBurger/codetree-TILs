#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dist[101][101];

int main() {

    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dist[i][j] = 21e8;
        }
    }

    for(int i=0;i<m;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = c;
    }

    for(int i=0;i<n;i++) dist[i][i] = 0;

    for(int k=0;k<=n;k++)
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if (dist[i][k] != 21e8 && dist[k][j] != 21e8) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 21e8;

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            //if (i == j) continue;
            if (dist[i][j] != 0 && dist[j][i] != 0) ans = min(ans, dist[i][j] + dist[j][i]);
            //cout << dist[i][j] << " ";
        }
        //cout << endl;
    }

    cout << ans;

    return 0;
}