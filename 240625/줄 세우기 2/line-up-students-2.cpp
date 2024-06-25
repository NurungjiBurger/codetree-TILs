#include <iostream>
#include <queue>

using namespace std;

struct Student{
    int num;
    int height;
    int weight;
    bool operator<(Student right) const{
        if (height == right.height) return weight < right.weight;
        return height > right.height;
    }
};

int n;
priority_queue<Student> pq;

int main() {
    
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        int h, w;
        cin >> h >> w;

        pq.push({i, h, w});
    }

    while(!pq.empty())
    {
        Student now = pq.top();
        pq.pop();

        cout << now.height << " " << now.weight << " " << now.num << endl;
    }

    return 0;
}