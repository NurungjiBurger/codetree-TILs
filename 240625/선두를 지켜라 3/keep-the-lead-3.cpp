#include <iostream>
#include <vector>

using namespace std;

vector<int> da, db;
int n, m;
int cnt = 0;
string top = "";

int main() {

    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        int v, t;
        cin >> v >> t;

        int dist = 0;
        if ((int)da.size() == 0) dist = v;
        else dist = da[(int)da.size() - 1] + v;

        for(int j=0;j<t;j++)
        {
            da.push_back(dist);
            dist += v;
        }
    }

    for(int j=0;j<m;j++)
    {
        int v, t;
        cin >> v >> t;

        int dist = 0;
        if ((int)db.size() == 0) dist = v;
        else dist = db[(int)db.size() - 1] + v;

        for(int j=0;j<t;j++)
        {
            db.push_back(dist);
            dist += v;
        }
    }


    for(int i=0;i<da.size();i++)
    {
        string tmp = "";

        if (da[i] > db[i]) tmp = "A";
        else if (da[i] < db[i]) tmp = "B";
        else tmp = "AB";

        if (top == tmp) continue;
        else
        {
            if ((int)top.length() == 2 && (int)tmp.length() == 2) continue;
            
            top = tmp;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}