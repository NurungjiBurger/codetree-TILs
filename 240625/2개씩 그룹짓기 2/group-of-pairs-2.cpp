#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans = 21e8;
vector<int> arr;

int main() {

    cin >> n;

    for(int i=0;i<2*n;i++)
    {
        int num;
        cin >> num;

        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    int diff;
    for(int i=0;i<n;i++)
    {
        diff = abs(arr[n + i] - arr[i]);

        ans = min(ans, diff);
    }

    cout << ans;

    return 0;
}