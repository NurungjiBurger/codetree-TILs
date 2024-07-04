#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
    int to;
    int cost;
    vector<int> path;
    bool operator<(Edge right) const{
        return cost > right.cost;
    }
};

int n, m;
int from, to;
vector<int> anspath;
vector<Edge> edges[1001];
int dist[1001];

void dijkstra()
{
    priority_queue<Edge> pq;
    vector<int> vec;
    vec.push_back(from);
    pq.push({from, 0, vec});
    dist[from] = 0;

    while(!pq.empty())
    {
        Edge now = pq.top();
        pq.pop();

        for(int i=0;i<edges[now.to].size();i++)
        {
            int next = edges[now.to][i].to;
            int ncost = now.cost + edges[now.to][i].cost;
            vector<int> npath = now.path;

            npath.push_back(next);

            if (dist[next] < ncost) continue;
            
            dist[next] = ncost;
            pq.push({next, ncost, npath});

            if (next == to) anspath = npath;
        }
    }
}

int main() {
    
    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    cin >> from >> to;

    for(int i=0;i<1001;i++) dist[i] = 21e8;

    dijkstra();

    cout << dist[to] << endl;

    for(int i=0;i<anspath.size();i++) cout << anspath[i] << " ";

    return 0;
}