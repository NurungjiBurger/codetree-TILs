#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Student{
    int num;
    int height;
    int weight;
    bool operator<(Student right) const{
        if (height == right.height) return weight > right.weight;
        return height < right.height;
    }
};

int n;
vector<Student> vec;

int main() {
    
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        int h, w;
        cin >> h >> w;

        vec.push_back({i, h, w});
    }

    sort(vec.begin(), vec.end());

    for(int i=0;i<n;i++)
    {
        cout << vec[i].height << " " << vec[i].weight << " " << vec[i].num << endl;
    }

    return 0;
}