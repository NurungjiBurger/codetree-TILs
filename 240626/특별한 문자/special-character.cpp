#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, pair<int, int>> um;

int main() {
    
    string str;
    cin >> str;

    for(int i=0;i<str.length();i++)
    {
        if (um.count(str[i]) == 0) um[str[i]] = {1, i};
        else um[str[i]].first++;
    }

    string ans = "None";
    int far = 21e8;

    for(auto it = um.begin();it != um.end();it++)
    {
        if (it->second.first == 1) 
        {
            if (far > it->second.second)
            {
                far = it->second.second;
                ans = it->first;
            }
        }
    }

    cout << ans;


    return 0;
}