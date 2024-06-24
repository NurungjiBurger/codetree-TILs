#include <iostream>

using namespace std;

long long s;

bool check(int num)
{
    long long tmp = (long long)num;

    if (((tmp * tmp) + tmp) / 2 <= s) return true;
    else return false;
}

int binarysearch(int left, int right)
{
    int ans = -21e8;
    int mid;

    while(left<=right)
    {
        mid = (left + right) / 2;

        if (check(mid))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return right;
}

int main() {
    
    cin >> s;

    cout << binarysearch(1, 21e8);//1000000000);

    return 0;
}