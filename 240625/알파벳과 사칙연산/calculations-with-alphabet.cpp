#include <iostream>

using namespace std;

// a ~ f
// 1 ~ 4를 넣자
int alpha[7] = {0,};
string str;
int ans = -21e8;

void calculate()
{
    int res = 0;
    for(int i=0;i<str.length();i+=2)
    {
        if (i == 0) res = alpha[str[i] - 'a'];
        else
        {
            if (str[i - 1] == '+') res += alpha[str[i] - 'a'];
            else if (str[i - 1] == '-') res -= alpha[str[i] - 'a'];
            else if (str[i - 1] == '*') res *= alpha[str[i] - 'a']; 
        }
    }

    ans = max(ans, res);
}

void dfs(int depth)
{
    if (depth == 6)
    {
        calculate();
        return;
    }

    for(int i=1;i<=4;i++)
    {
        alpha[depth] = i;
        dfs(depth + 1);
    }
}

int main() {

    cin >> str;

    dfs(0);

    cout << ans;

    return 0;
}