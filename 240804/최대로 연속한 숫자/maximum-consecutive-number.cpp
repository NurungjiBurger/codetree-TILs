#include <iostream>
#include <map>

using namespace std;

int n, m;
map<int, int> arr;

int main() {

    cin >> n >> m;

    arr[-1] = n + 1;
    arr[n + 1] = n + 1;

    for(int i=0;i<m;i++)
    {
        int num;
        cin >> num;

        arr[num] = 0;

        auto leftiter = arr.find(num);
        leftiter--;
        auto rightiter = arr.find(num);
        rightiter++;

        leftiter->second = num - leftiter->first - 1;
        rightiter->second = rightiter->first - num - 1;

        arr[num] = max(leftiter->second, rightiter->second);

        int ans = -21e8;

        ans = max(ans, arr[num]);
        ans = max(ans, arr.begin()->second);
        ans = max(ans, (--arr.end())->second);

        cout << ans << endl;
    }


    return 0;
}