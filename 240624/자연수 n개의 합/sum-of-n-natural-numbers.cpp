#include <iostream>

using namespace std;

long long s;

long long binarysearch(long long left, long long right)
{
    long long mid;

    while(left<=right)
    {
        mid = (left + right) / 2;

        if (((mid * mid) + mid) / 2 <= s) left = mid + 1;
        else right = mid - 1;
    }

    return right;
}

int main() {
    
    cin >> s;

    cout << binarysearch(1, 21e8);//1000000000);

    return 0;
}