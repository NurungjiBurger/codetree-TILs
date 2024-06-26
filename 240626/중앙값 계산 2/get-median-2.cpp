#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> vec;

int main() {
    
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;

        vec.push_back(num);

        if (i % 2 == 0)
        {
            sort(vec.begin(), vec.end());

            cout << vec[i / 2] << " ";
        }
    }


    return 0;
}