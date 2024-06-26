#include <iostream>
#include <unordered_map>

using namespace std;

int n;
unordered_map<string, int> um;

int main() {
    
    cin >> n;

    for(int i=0;i<n;i++)
    {
        string str;
        cin >> str;

        int alpha[60] = {0,};

        for(int j=0;j<str.length();j++) alpha[str[j] - 'A']++;

        string tmp = "";
        for(int i=0;i<60;i++)
        {
            if (alpha[i] == 0) continue;
            tmp += (char)(i + 'A');
            tmp += to_string(alpha[i]);
        }

        um[tmp]++;
    }

    int ans = -21e8;

    for(auto item : um)
    {
        ans = max(ans, item.second);
    }

    cout << ans;

    return 0;
}