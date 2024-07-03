#include <iostream>

using namespace std;

struct Node {
    int num;
    Node *prev, *next;

    Node(int num) : num(num), prev(nullptr), next(nullptr) {}
};

int n, q;
Node *nodes[100001] = {};

void makeNode(int idx)
{
    if (nodes[idx] == nullptr) nodes[idx] = new Node(idx);
    else
    {
        Node *left;
        if (nodes[idx]->prev != nullptr) left = nodes[idx]->prev;
        else left = nullptr;
        Node *right;
        if (nodes[idx]->next != nullptr) right = nodes[idx]->next;
        else right = nullptr;

        if (right != nullptr) right->prev = left;
        if (left != nullptr) left->next = right;

        nodes[idx]->next = nullptr;
        nodes[idx]->prev = nullptr;
    }
}

void insertPrevNode(int i, int j)
{
    if (nodes[i] == nullptr) makeNode(i);
    if (nodes[j] == nullptr) makeNode(j);
    //Node *from = nodes[i];
    //Node *to = nodes[j];

    //from->prev = to;
    //to->next = from;

    if (nodes[i]->prev != nullptr)
    {
        Node *ptr = nodes[i]->prev;

        ptr->next = nodes[j];
        nodes[j]->prev = ptr;
    }
    nodes[i]->prev = nodes[j];
    nodes[j]->next = nodes[i];
}

void insertNextNode(int i, int j)
{
    if (nodes[i] == nullptr) makeNode(i);
    if (nodes[j] == nullptr) makeNode(j);
    // Node *from = nodes[i];
    // Node *to = nodes[j];

    // from->next = to;
    // to->prev = from;

    if (nodes[i]->next != nullptr)
    {
        Node *ptr = nodes[i]->next;

        ptr->prev = nodes[j];
        nodes[j]->next = ptr;
    }
    nodes[i]->next = nodes[j];
    nodes[j]->prev = nodes[i];
}

void print(int i)
{
    if (nodes[i] == nullptr) makeNode(i);

    if (nodes[i]->prev == nullptr) cout << 0 << " ";
    else cout << nodes[i]->prev->num << " ";
    if (nodes[i]->next == nullptr) cout << 0 << " ";
    else cout << nodes[i]->next->num;

    cout << endl;
}

int main() {

    cin >> n;
    cin >> q;

    for(int idx=0;idx<q;idx++)
    {
        int cmd, i, j;
        cin >> cmd;

        if (cmd == 1)
        {
            cin >> i;

            makeNode(i);
        }
        else if (cmd == 2)
        {
            cin >> i >> j;

            insertPrevNode(i, j);
        }
        else if (cmd == 3)
        {
            cin >> i >> j;

            insertNextNode(i, j);
        }
        else if (cmd == 4)
        {
            cin >> i;

            print(i);
        }
    }

    for(int i=1;i<=n;i++) 
    {
        if (nodes[i] == nullptr) cout << 0 << " ";
        else
        {
            if (nodes[i]->next == nullptr) cout << 0 << " ";
            else cout << nodes[i]->next->num << " ";
        }
    }

    return 0;
}