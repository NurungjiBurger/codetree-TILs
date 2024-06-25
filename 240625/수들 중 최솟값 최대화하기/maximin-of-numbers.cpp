#include <iostream>
#include <vector>

using namespace std;

bool row[11] = {false,};
bool col[11] = {false,};
int arr[11][11];
int n, ans = -21e8;
vector<pair<int, int>> points;

void check()
{
    int mini = 21e8;

    for(int i=0;i<points.size();i++)
    {
        int y = points[i].first;
        int x = points[i].second;

        mini = min(mini, arr[y][x]);
    }

    ans = max(ans, mini);
}

void dfs(int depth, int si)
{
    if (depth == n)
    {
        check();
        return;
    }

    for(int i=si;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (col[j]) continue;
            col[j] = true;
            points.push_back({i, j});
            dfs(depth + 1, i + 1);
            points.pop_back();
            col[j] = false;
        }
    }    

}

int main() {

    cin >> n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> arr[i][j];
        }
    }

    dfs(0, 0);

    cout << ans;

    return 0;
}