#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct Point{
    int x;
    int y;
    bool operator<(Point right) const{
        if (x == right.x) return y < right.y;
        return x < right.x;
    }
};

int n, m;
set<Point> s;

int main() {
    
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        int x, y;
        cin >> x >> y;

        s.insert({x, y});
    }

    for(int i=0;i<m;i++)
    {
        int x, y;
        cin >> x >> y;

        auto iter = s.lower_bound({x, y});

        if (iter == s.end()) cout << "-1 -1" << endl;
        else cout << iter->x << " " << iter->y << endl;
    }

    return 0;
}