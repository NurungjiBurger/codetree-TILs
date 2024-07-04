#include <iostream>
#include <queue>

using namespace std;

struct Num{
    int num;
    bool operator<(Num right) const{
        if (abs(num) == abs(right.num)) return num > right.num;
        return abs(num) > abs(right.num);
    }
};

int n;
priority_queue<Num> pq;

int main() {

    cin >> n;

    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            if (pq.empty()) cout << 0;
            else
            {
                cout << pq.top().num;
                pq.pop();
            }
            cout << endl;
        }
        else pq.push({x});
    }


    return 0;
}