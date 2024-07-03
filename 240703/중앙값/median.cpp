#include <iostream>
#include <queue>

using namespace std;

int t, m;

int main() {

    cin >> t;

    for(int tc=1;tc<=t;tc++)
    {
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;

        cin >> m;

        int middle;

        for(int i=0;i<m;i++)
        {
            int num;
            cin >> num;

            if (i == 0) middle = num;
            else
            {
                if (num > middle) right.push(num);
                else left.push(num);

                //cout << "before " << left.size() << " " << right.size() << endl;

                if (i >= 2)
                {
                    // left < right
                    if ((int)right.size() - (int)left.size() >= 2)
                    {
                        //cout << "left < right";
                        left.push(middle);
                        middle = right.top();
                        right.pop();
                    }
                    // left > right
                    else if ((int)left.size() - (int)right.size() >= 2)
                    {
                        //cout << "left >= right";
                        right.push(middle);
                        middle = left.top();
                        left.pop();
                    }
                }
            }

            //cout << "after " << left.size() << " " << right.size() << endl;

            if (i % 2 == 0) cout << middle << " ";//cout << left.size() << " : " << middle << " : " << right.size() << endl;;
        }
        cout << endl;
    }

    return 0;
}