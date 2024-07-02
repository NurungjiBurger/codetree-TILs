#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

struct Point{
    int y;
    int x;
};

int diry[4] = {0, 0, 1, -1};
int dirx[4] = {1, -1, 0, 0};

int n, m, ans = -21e8;
int Map[501][501];
//  num    cnt
int board[501][501];
bool visited[501][501] = {false,};
int cnts[2500001];

void bfs(int y, int x, int num)
{
    queue<Point> que;
    que.push({y, x});
    visited[y][x] = true;
    board[y][x] = num;
    int cnt = 1;

    while(!que.empty())
    {
        Point now = que.front();
        que.pop();

        for(int i=0;i<4;i++)
        {
            int ny = now.y + diry[i];
            int nx = now.x + dirx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (Map[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;
            
            board[ny][nx] = num;
            visited[ny][nx] = true;
            que.push({ny, nx});
            cnt++;
        }
    }

    cnts[num] = cnt;
}

int main() {

    cin >> n >> m;

    // 입력
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> Map[i][j];
        }
    }

    // 1 체크
    int num = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if (Map[i][j] == 1 && !visited[i][j]) bfs(i, j, num++);
        }
    }

    // 0인 애들 중에서 1로 바꿨을때 max 찾기
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if (Map[i][j] == 0)
            {
                int cnt = 1;
                unordered_set<int> us;

                for(int k=0;k<4;k++)
                {
                    int ny = i + diry[k];
                    int nx = j + dirx[k];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

                    if (us.count(board[ny][nx]) == 0)
                    {
                        cnt += cnts[board[ny][nx]];
                        us.insert(board[ny][nx]);
                    }
                }

                ans = max(ans, cnt);
            }
        }
    }

    if (ans == -21e8) ans = 249999;

    cout << ans;

    return 0;
}