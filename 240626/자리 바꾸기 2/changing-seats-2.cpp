#include <iostream>
#include <unordered_set>

using namespace std;

int n, k;
int arr[100001];
pair<int, int> arr2[100001];
unordered_set<int> cnt[100001];

int main() {

    cin >> n >> k;

    for(int i=0;i<k;i++)
    {
        cin >> arr2[i].first >> arr2[i].second;
    }

    for(int i=1;i<=n;i++)
    {
        arr[i] = i;
        cnt[i].insert(i);
    }

    for(int idx = 0;idx<3;idx++)
    {
        for(int i=0;i<k;i++)
        {
            int a, b, tmp;
            a = arr2[i].first;
            b = arr2[i].second;

            cnt[arr[a]].insert(b);
            cnt[arr[b]].insert(a);

            tmp = arr[a];
            arr[a] = arr[b];
            arr[b] = tmp;
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout << cnt[i].size() << endl;
    }


    return 0;
}