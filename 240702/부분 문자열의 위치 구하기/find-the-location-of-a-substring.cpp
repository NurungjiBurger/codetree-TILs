#include <iostream>
#include <unordered_map>

using namespace std;

string input, goal;
unordered_map<string, int> um;

int main() {

    cin >> input;
    cin >> goal;

    for(int i=0;i<=input.length() - goal.length();i++)
    {
        string str = input.substr(i, goal.length());
        if (um.count(str) == 0) um[str] = i;
    }

    if (um.count(goal) == 0) cout << -1;
    else cout << um[goal];

    return 0;
}