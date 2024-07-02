#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<long long, int> um;

int main() {
    
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;

        um[num]++;
    }

    for(int i=0;i<m;i++)
    {
        int num;
        cin >> num;

        if (um.count(num) == 0) cout << 0;
        else cout << um[num];
        cout << endl;
    }

    return 0;
}