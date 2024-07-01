#include <iostream>
#include <vector>

using namespace std;

int n;
int parent[100001];

int main() {

    cin >> n;

    for(int i=0;i<n;i++)
    {
        int p, c;
        cin >> p >> c;

        parent[c] = p;                    
    }

    for(int i=2;i<=n;i++) cout << parent[i] << endl;


    return 0;
}