#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
    int to;
    int cost;
    bool operator<(Edge right) const{
        return cost > right.cost;
    }
};

int n, m, ans = -21e8;
int dist[100001];
vector<Edge> edges[100001];

void dijkstra(int start)
{
    priority_queue<Edge> pq;
    dist[start] = 0;
    pq.push({start, 0});

    while(!pq.empty())
    {
        Edge now = pq.top();
        pq.pop();

        for(int i=0;i<edges[now.to].size();i++)
        {
            int next = edges[now.to][i].to;
            int ncost = now.cost + edges[now.to][i].cost;

            if (dist[next] < ncost) continue;

            dist[next] = ncost;
            pq.push({next, ncost});
        }
    }

}

int main() {

    cin >> n >> m;

    for(int i=1;i<=n;i++) dist[i] = 21e8;

    for(int i=0;i<m;i++)
    {
        int f, t, d;
        cin >> f >> t >> d;

        edges[t].push_back({f, d});
    }

    dijkstra(n);

    for(int i=1;i<=n-1;i++) 
    {
        if (dist[i] == 21e8) continue;
        ans = max(ans, dist[i]);
    }

    cout << ans;

    return 0;
}