#include <iostream>

using namespace std;

struct Node{
    int num;
    Node *prev, *next;

    Node(int val) : num(val), prev(nullptr), next(nullptr) {}
};

int n, q;
Node *head, *tail;

void InsertNode(Node *from, int num)
{
    Node *node = new Node(num);

    node->next = from->next;

    from->next = node;
    node->prev = from;
}

void ChangeNode(Node *ls, Node *le, Node *rs, Node *re)
{
    if (le->next == rs)
    {
        rs->prev = ls->prev;
        ls->prev->next = rs;

        ls->prev = re;

        le->next = re->next;
        re->next->prev = le;

        re->next = ls;
    }
    else
    {

        Node *leftone = ls->prev;
        Node *lefttwo = le->next;
        Node *rightone = rs->prev;
        Node *righttwo = re->next;

        leftone->next = rs;
        rs->prev = leftone;

        lefttwo->prev = re;
        re->next = lefttwo;

        rightone->next = ls;
        ls->prev = rightone;

        righttwo->prev = le;
        le->next = righttwo;

    }
}

Node* RetrunNodeptr(Node *from, int val)
{
    Node *ptr = from;

    while(true)
    {
        if (ptr->num == val) return ptr;
        if (ptr->next == nullptr) break;
        ptr = ptr->next;
    }

    return nullptr;
}

void print()
{
    Node *ptr = head;
    ptr = ptr->next;

    while(ptr != nullptr)
    {
        if (ptr->num != 0) cout << ptr->num << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {

    head = new Node(0);
    tail = new Node(0);

    head->next = tail;
    tail->prev = head;

    cin >> n;
    cin >> q;

    Node *ptr = head;

    for(int i=1;i<=n;i++)
    {
        InsertNode(ptr, i);
        ptr = ptr->next;
    }

    for(int i=0;i<q;i++)
    {
        int a, b, c, d;

        cin >> a >> b >> c >> d;

        Node *aptr, *bptr, *cptr, *dptr;

        aptr = RetrunNodeptr(head, a);
        bptr = RetrunNodeptr(aptr, b);
        cptr = RetrunNodeptr(head, c);
        dptr = RetrunNodeptr(cptr, d);

        ChangeNode(aptr, bptr, cptr, dptr);
    }

    print();


    return 0;
}