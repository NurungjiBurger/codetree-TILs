#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int degree[100001];
vector<int> align[100001];
queue<int> que;

int main() {
    
    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;

        degree[a]++;
        align[b].push_back(a);
    }

    int cnt = 0;

    for(int i=1;i<=n;i++) 
    {
        if (degree[i] == 0) 
        {
            que.push(i);
            cnt++;
        }
    }

    while(!que.empty())
    {
        int now = que.front();
        que.pop();

        for(int i=0;i<align[now].size();i++)
        {
            int next = align[now][i];

            degree[next]--;

            if (degree[next] == 0) 
            {
                que.push(next);
                cnt++;
            }
        }
    }

    if (cnt == n) cout << "Consistent\n";
    else cout << "Inconsistent\n";

    return 0;
}