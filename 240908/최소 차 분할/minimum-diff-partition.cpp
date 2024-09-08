#include <iostream>
using namespace std;

int n;
int arr[1001];
int dp[4][1001];

int main() {
    
    cin >> n;

    for(int i=0;i<n;i++) cin >> arr[i];

    // 정확히 두 그룹으로 나뉜다
    // A or B

    // A에 속하는 경우 B에 속하는 경우
    // A B A B
    // 0 X X 0

    dp[0][0] = arr[0];
    dp[3][0] = arr[0];

    for(int i=i;i<n;i++)
    {

        int diff = 21e8;

        // A에 속하는 경우
        if (abs(dp[2][i - 1] + arr[i] - dp[3][i - 1]) < abs(dp[0][i - 1] + arr[i] - dp[1][i - 1]))
        {
            // 이전에는 B가 가져감
            dp[0][i] = dp[2][i - 1] + arr[i];
            dp[1][i] = dp[3][i - 1];

            diff = abs(dp[2][i - 1] + arr[i] - dp[3][i - 1]);
        }
        else
        {
            // 이전에도 A가 가져감
            dp[0][i] = dp[0][i - 1] + arr[i];
            dp[1][i] = dp[1][i - 1];

            diff = abs(dp[0][i - 1] + arr[i] - dp[1][i - 1]);
        }

        // 이전 기록을 다 합치고 새로 만들어주는게 차이가 적은 경우
        if (abs(dp[0][i - 1] + dp[1][i - 1] - arr[i]) < diff)
        {
            dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
            dp[1][i] = arr[i];
        }


        // B에 속하는 경우
        if (abs(dp[1][i - 1] + arr[i] - dp[0][i - 1]) < abs(dp[3][i - 1] + arr[i] - dp[2][i - 1]))
        {
            // 이전에는 A가 가져감
            dp[3][i] = dp[1][i - 1] + arr[i];
            dp[2][i] = dp[0][i - 1];

            diff = abs(dp[1][i - 1] + arr[i] - dp[0][i - 1]);
        }
        else
        {
            // 이전에도 B가 가져감
            dp[3][i] = dp[3][i - 1] + arr[i];
            dp[2][i] = dp[2][i - 1];

            diff = abs(dp[3][i - 1] + arr[i] - dp[2][i - 1]);
        }

        // 이전 기록을 다 합치고 새로 만들어주는게 차이가 적은 경우
        if (abs(dp[2][i - 1] + dp[3][i - 1] - arr[i]) < diff)
        {
            dp[3][i] = dp[3][i - 1] + dp[2][i - 1];
            dp[2][i] = arr[i];
        }


               // cout << dp[0][i] << " " << dp[1][i] << " " << dp[2][i] << " " << dp[3][i] << endl;
    }

   // cout << dp[0][n - 1] << " " << dp[1][n - 1] << " " << dp[2][n - 1] << " " << dp[3][n - 1] << endl;

    cout << min(abs(dp[0][n - 1] - dp[1][n - 1]), abs(dp[2][n - 1] - dp[3][n - 1]));


    return 0;
}