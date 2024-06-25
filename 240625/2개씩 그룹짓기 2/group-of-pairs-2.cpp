#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans = -21e8;
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
    for(int i=1;i<2*n;i++)
    {
        diff = arr[i] - arr[i - 1];

        ans = max(ans, diff);
    }

    cout << ans;

    return 0;
}