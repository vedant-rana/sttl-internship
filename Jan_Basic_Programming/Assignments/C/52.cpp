#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
int main() {
    int year = 2024;
    int month = 0;  // January
    tm calendar = {};
    calendar.tm_year = year - 1900;
    calendar.tm_mon = month;
    calendar.tm_mday = 1;
    mktime(&calendar);

    cout << put_time(&calendar, "%B %Y") << endl;
    cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;

    int startDay = calendar.tm_wday;

    for (int i = 0; i < startDay; i++) {
       cout << "    ";
    }

    int maxDay = 31;  // January always has 31 days
    for (int day = 1; day <= maxDay; day++) {
        cout << setw(3) << day << " ";

        calendar.tm_mday++;
       mktime(&calendar);
        if (calendar.tm_wday == 0) {
            cout << endl;
        }
    }

    return 0;
}
