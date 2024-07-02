#include <iostream>

using namespace std;

int unf[100001];
int n, m;

void init()
{
    for(int i=0;i<=n;i++) unf[i] = i;
}

int find(int tar)
{
    if (unf[tar] == tar) return tar;
    return find(unf[tar]);
}

void Union(int a, int b)
{
    int ua = find(a);
    int ub = find(b);

    if (ua == ub) return;

    unf[ua] = ub;
}

int main() {

    cin >> n >> m;

    init();

    for(int i=0;i<m;i++)
    {
        int cmd, a, b;

        cin >> cmd >> a >> b;

        if (cmd == 0) Union(a, b);
        else if (cmd == 1) 
        {
            int fa, fb;
            fa = find(a);
            fb = find(b);

            if (fa == fb) cout << 1;
            else cout << 0;
            cout << endl;
        }
    }

    return 0;
}