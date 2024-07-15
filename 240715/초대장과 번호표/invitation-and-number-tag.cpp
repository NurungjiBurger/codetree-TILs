#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int n, g;
vector<int> group[250001];
unordered_set<int> us; // 초대받은 인원

int main() {

    cin >> n >> g;

    for(int i=0;i<g;i++)
    {
        int s;
        cin >> s;

        for(int j=0;j<s;j++)
        {
            int num;
            cin >> num;

            group[i].push_back(num);
        }
    }

    int cnt = 0;
    us.insert(1);

    while(true)
    {
        // 돌려
        cnt = 0;
        for(int i=0;i<g;i++)
        {
            int s = (int)group[i].size();
            int tcnt = 0, tmp;
            for(int j=0;j<s;j++)
            {
                if (us.count(group[i][j]) == 0) tmp = group[i][j];
                else tcnt++;
            }

            if (s - 1 == tcnt) 
            {
                us.insert(tmp);
                cnt++;
            }
        }

        // 체크
        if (cnt == 0) break;
    }

    cout << us.size();


    return 0;
}