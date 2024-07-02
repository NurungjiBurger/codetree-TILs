#include <iostream>

using namespace std;

struct Node{
    char me;
    int left;
    int right;
};

int n;
// A ~ Z
Node arr[27];

void preorder(int idx)
{
    if (idx > n && arr[idx].me == '.') return;

    cout << arr[idx].me;
    if (arr[idx].left > 0) preorder(arr[idx].left);
    if (arr[idx].right > 0) preorder(arr[idx].right);
}

void inorder(int idx)
{
    if (idx > n && arr[idx].me == '.') return;

    if (arr[idx].left > 0) inorder(arr[idx].left);
    cout << arr[idx].me;
    if (arr[idx].right > 0) inorder(arr[idx].right);
}

void postorder(int idx)
{
    if (idx > n && arr[idx].me == '.') return;

    if (arr[idx].left > 0) postorder(arr[idx].left);
    if (arr[idx].right > 0) postorder(arr[idx].right);
    cout << arr[idx].me;
}

int main() {
    
    cin >> n;

    //   1
    // 2   3
    //4 5 6 7

    for(int i=1;i<=n;i++)
    {
        char a, b, c;
        cin >> a >> b >> c;

        arr[a - 'A'].me = a;
        arr[a - 'A'].left = b - 'A';
        arr[a - 'A'].right = c - 'A';
    }

    preorder(0);
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);

    return 0;
}