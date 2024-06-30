#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, q;
vector<int> points;

int main() {
    
    cin >> n >> q;

    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;

        points.push_back(num);
    }

    for(int i=0;i<q;i++)
    {
        int s, e;
        cin >> s >> e;

        int sidx, eidx;

        sidx = lower_bound(points.begin(), points.end(), s) - points.begin();
        eidx = lower_bound(points.begin(), points.end(), e) - points.begin();

        cout << eidx - sidx + 1 << endl;
    }

    return 0;
}