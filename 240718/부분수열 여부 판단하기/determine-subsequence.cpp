#include <iostream>

using namespace std;

int n, m;
int A[100001];
int B[100001];

int main() {

    cin >> n >> m;

    for(int i=0;i<n;i++) cin >> A[i];
    for(int i=0;i<m;i++) cin >> B[i];

    int left = 0, right = 0;

    while(right < n)
    {
        if (B[left] == A[right]) left++;
        else right++;
    }

    if (left == m) cout << "Yes";
    else cout << "No";


    return 0;
}