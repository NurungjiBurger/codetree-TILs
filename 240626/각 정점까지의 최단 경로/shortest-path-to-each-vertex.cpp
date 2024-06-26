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

int n, m, k;
int dist[20001];
vector<Edge> edges[20001];

void dijkstra(int start)
{
    dist[start] = 0;
    priority_queue<Edge> pq;
    pq.push({start, 0});

    while(!pq.empty())
    {
        Edge now = pq.top();
        pq.pop();

        for(int i=0;i<edges[now.to].size();i++)
        {
            int next = edges[now.to][i].to;
            int cost = now.cost + edges[now.to][i].cost;

            if (dist[next] < cost) continue;

            dist[next] = cost;
            pq.push({next, cost});
        }
    }
}

int main() {
    
    cin >> n >> m;
    cin >> k;

    for(int i=0;i<n;i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;

        dist[i] = 21e8;

        from--;
        to--;

        edges[from].push_back({to, cost});
        edges[to].push_back({from, cost});
    }

    dijkstra(--k);

    for(int i=0;i<n;i++)
    {
        cout << dist[i] << endl;
    }


    return 0;
}