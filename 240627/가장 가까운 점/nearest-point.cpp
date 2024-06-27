#include <iostream>
#include <queue>

using namespace std;

struct Point{
    int x;
    int y;
    bool operator<(Point right) const{
        if (abs(x) + abs(y) == abs(right.x) + abs(right.y) && x == right.x) return y > right.y;
        if (abs(x) + abs(y) == abs(right.x) + abs(right.y)) return x > right.x;
        return abs(x) + abs(y) > abs(right.x) + abs(right.y);
    }
};

int n, m;
priority_queue<Point> pq;

int main() {
    
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        int x, y;
        cin >> x >> y;

        pq.push({x, y});
    }

    for(int i=0;i<m;i++)
    {
        Point now = pq.top();
        pq.pop();

        pq.push({now.x + 2, now.y + 2});
    }

    Point now = pq.top();
    pq.pop();

    cout << now.x << " " << now.y << endl;

    return 0;
}