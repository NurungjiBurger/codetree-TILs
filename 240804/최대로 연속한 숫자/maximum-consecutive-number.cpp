#include <iostream>
#include <set>

using namespace std;

int n, m;
set<int> nums;
set<pair<int, pair<int, int>>> lens;

int main() {

    cin >> n >> m;

    nums.insert(-1);
    nums.insert(n + 1);

    lens.insert({-(n + 1), {-1, n + 1}});

    for(int i=0;i<m;i++)
    {
        int num;
        cin >> num;

        nums.insert(num);

        auto iter = nums.find(num);
        iter++;
        int e = *iter;

        iter = nums.find(num);
        iter--;
        int s = *iter;

        lens.erase({-(e - s - 1), {s, e}});
        lens.insert({-(num - s - 1), {s, num}});
        lens.insert({-(e - num - 1), {num, e}});

        cout << -(*lens.begin()).first << endl;
    }


    return 0;
}