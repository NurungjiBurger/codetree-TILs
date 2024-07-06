#include <iostream>

using namespace std;

int n, m;
int dist[101][101];

int main() {
    
    cin >> n >> m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 21e8;
        }
    }

    for(int i=0;i<m;i++)
    {
        int f, t, c;
        cin >> f >> t >> c;

        dist[f][t] = min(dist[f][t], c);
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if (dist[i][k] != 21e8 || dist[k][j] != 21e8) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if (dist[i][j] == 21e8) cout << -1 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}