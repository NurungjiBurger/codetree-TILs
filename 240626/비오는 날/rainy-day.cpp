#include <iostream>
#include <algorithm>

using namespace std;

struct Data{
    int soda;
    string date;
    string day;
    string weather;
    bool operator<(Data right) const{
        return soda < right.soda;
    }
};

int n;
Data arr[101];

int main() {
    
    cin >> n;

    for(int i=0;i<n;i++)
    {
        string date, day, weather;

        cin >> date >> day >> weather;

        int data = 0;

        for(int j=0;j<date.length();j++)
        {
            if (date[j] >= '0' && date[j] <= '9')
            {
                data *= 10;
                data += ( date[j] - '0' );
            }
        }

        arr[i].soda = data;
        arr[i].date = date;
        arr[i].day = day;
        arr[i].weather = weather;
    }

    sort(arr, arr + n);

    for(int i=0;i<n;i++)
    {
        if (arr[i].weather == "Rain")
        {
            cout << arr[i].date << " " << arr[i].day << " " << arr[i].weather;
            break;
        }
    }


    return 0;
}