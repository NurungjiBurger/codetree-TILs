#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Line{
    int start;
    int end;
    bool operator<(Line right) const{
        if (start == right.start) return end < right.end;
        return start < right.start;
    }
};

int n;
vector<Line> vec;

int main() {

    cin >> n;

    for(int i=0;i<n;++i)
    {
        int a, b;
        cin >> a >> b;

        vec.push_back({a, b});
    }

    sort(vec.begin(), vec.end());

    long long last, ans = 0;
    last = vec[0].end;
    ans = 1;

    for(int i=1;i<n;++i)
    {
        if (last < vec[i].start)
        {
            last = vec[i].end;
            ++ans;
        }
        last = vec[i].end;
    }

    cout << ans;

    return 0;
}