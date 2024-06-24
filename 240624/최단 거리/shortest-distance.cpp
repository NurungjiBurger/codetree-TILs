#include <iostream>

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
            cin >> dist[i][j];
        }
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;

        cout << dist[a - 1][b - 1] << endl;
    }

    return 0;
}