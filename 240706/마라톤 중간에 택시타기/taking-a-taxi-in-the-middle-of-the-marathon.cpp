#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point{
    int y;
    int x;
    bool operator<(Point right) const{
        if (x == right.x) return y < right.y;
        return x < right.x;
    }
};

int n;
vector<Point> vec;
int L[100001];
int R[100001];

int main() {

    cin >> n;

    for(int i=0;i<n;i++)
    {
        int x, y;
        cin >> x >> y;

        vec.push_back({y, x});
    }

    L[0] = 0;
    for(int i=1;i<n;++i) L[i] = L[i - 1] + abs(vec[i].y - vec[i - 1].y) + abs(vec[i].x - vec[i - 1].x);
    R[n - 1] = 0;
    for(int i=n-2;i>=0;--i) R[i] = R[i + 1] + abs(vec[i].y - vec[i + 1].y) + abs(vec[i].x - vec[i + 1].x);

    int ans = 21e8;

    for(int i=1;i<n-1;i++)
    {
        int tmp = L[i - 1] + R[i + 1] + abs(vec[i - 1].y - vec[i + 1].y) + abs(vec[i - 1].x - vec[i + 1].x);
        ans = min(ans, tmp);
    }

    cout << ans;

    return 0;
}