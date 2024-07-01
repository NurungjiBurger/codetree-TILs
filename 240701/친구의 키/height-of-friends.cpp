#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> edges[100001];
int degree[100001];

int main() {

    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;

        degree[b]++;
        edges[a].push_back(b);
    }


    queue<int> que;

    for(int i=1;i<=n;i++) if(degree[i] == 0) que.push(i);

    while(!que.empty())
    {
        int now = que.front();
        que.pop();

        cout << now << " ";

        for(int i=0;i<edges[now].size();i++)
        {
            int next = edges[now][i];

            degree[next]--;
            if (degree[next] == 0) que.push(next);
        }
    }

    return 0;
}