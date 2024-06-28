#include <iostream>
#include <unordered_map>

using namespace std;

long long ans = 0;
int n;
unordered_map<int, int> AB;
unordered_map<int, int> CD;
int A[5001];
int B[5001];
int C[5001];
int D[5001];

int main() {

    cin >> n;

    for(int i=0;i<n;i++) cin >> A[i];
    for(int i=0;i<n;i++) cin >> B[i];
    for(int i=0;i<n;i++) cin >> C[i];
    for(int i=0;i<n;i++) cin >> D[i];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            AB[A[i] + B[j]]++;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            CD[C[i] + D[j]]++;
        }
    }

    for(auto first : AB)
    {
        for(auto second : CD)
        {
            if (first.first + second.first == 0)
            {
                ans += (first.second * second.second);
            }
        }
    }

    cout << ans;
    

    return 0;
}