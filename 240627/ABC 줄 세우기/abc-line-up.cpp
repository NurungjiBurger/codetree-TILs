#include <iostream>

using namespace std;

int n;
string str = "";

int main() {

    cin >> n;

    for(int i=0;i<n;i++)
    {
        char ch;
        cin >> ch;

        str += ch;
    }

    int cnt = 0;
    int i, j;

    for(i=1;i<n;i++)
    {
        char key = str[i];

        for(j=i-1;j>=0 && str[j] > key;j--)
        {
            str[j + 1] = str[j];
            cnt++;
        }

        str[j + 1] = key;
    }

    cout << cnt;


    return 0;
}