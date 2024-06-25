#include <iostream>

using namespace std;

struct Point{
    int x;
    int y;
};

int minx = 21e8, maxx = -21e8, miny = 21e8, maxy = -21e8;
int n, ans = 21e8;
Point arr[101];

void size(int eli)
{
    minx = 21e8, maxx = -21e8, miny = 21e8, maxy = -21e8;
    for(int i=0;i<n;i++)
    {
        if (i == eli) continue;

        minx = min(minx, arr[i].x);
        maxx = max(maxx, arr[i].x);

        miny = min(miny, arr[i].y);
        maxy = max(maxy, arr[i].y);
    }

    ans = min(ans, abs(maxx - minx) * abs(maxy - miny));
}

int main() {
    
    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin >> arr[i].x;
        cin >> arr[i].y;
    }

    for(int i=0;i<n;i++) size(i);

    cout << ans;

    return 0;
}