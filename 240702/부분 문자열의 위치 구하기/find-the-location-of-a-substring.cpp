#include <iostream>
#include <unordered_map>

using namespace std;

string input, goal;
unordered_map<string, int> um;

int main() {

    cin >> input;
    cin >> goal;

    for(int i=0;i<input.length();i++)
    {
        string str = "";
        for(int j=i;j<input.length();j++)
        {
            str += input[j];
            if ((int)str.length() > (int)goal.length()) break;
            if (str.length() == goal.length() && um.count(str) == 0) um[str] = i;
        }
    }

    if (um.count(goal) == 0) cout << -1;
    else cout << um[goal];

    return 0;
}