#include <iostream>
#include <unordered_set>

using namespace std;

int n, ans = -21e8;
int arr[100001];
unordered_set<int> us;

void print()
{
    for(auto item : us)
    {
        cout << item << " ";
    }
    cout << "===============\n";
}

int main() {
    
    cin >> n;

    for(int i=0;i<n;i++) cin >> arr[i];

    int left = 0, right = 0;
    while(right < n)
    {
        if (us.count(arr[right]) != 0)
        {
            us.erase(arr[left]);
            left++;
        }
        else
        {
            us.insert(arr[right]);
            right++;
            ans = max(ans, (right - left));
        }
    }

    cout << ans;


    return 0;
}