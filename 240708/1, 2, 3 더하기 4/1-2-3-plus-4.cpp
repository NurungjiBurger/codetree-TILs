#include <iostream>

using namespace std;

int n;
int dp[100001];

int main() {

    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i=4;i<=n;i++) 
    {
        dp[i] = dp[i - 1] + dp[i - 2] - dp[i - 3];
        if (i % 3 == 0) dp[i]++;
    }

    cout << dp[n];


    return 0;
}