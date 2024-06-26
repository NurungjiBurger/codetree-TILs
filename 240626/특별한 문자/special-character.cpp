#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, int> um;

int main() {
    
    string str;
    cin >> str;

    for(int i=0;i<str.length();i++)
    {
        um[str[i]]++;
    }

    bool print = false;

    for(auto it = um.begin();it != um.end();it++)
    {
        if (it->second == 1) 
        {
            cout << it->first;
            print = true;
            break;
        }
    }

    if (!print) cout << "None";


    return 0;
}