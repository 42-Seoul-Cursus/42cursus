#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main(void)
{
    // string a;
    // getline(cin, a);
    // for (size_t i = 0; i < a.length(); i++)
    // {
    //     cout << a[i] << ' ' << int(a[i]) << '\n';
    // }

    // string b;
    // cin >> b;
    // for (size_t i = 0; i < b.length(); i++)
    // {
    //     cout << b[i] << ' ' << int(b[i]) << '\n';
    // }

    string c;
    ifstream d("data.csv");
    getline(d, c);
    if (c == "date,exchange_rate")
    {
        cout << "true" << '\n';
    }
    else
    {
        cout << "false" << '\n';
    }

    time_t now = time(0);  // get current date and time

    cout << "Number of seconds since January 1,2021 is:: " << now << endl;

    tm* ltm = localtime(&now);

    // print various components of tm structure.
    cout << "Year:" << 1900 + ltm->tm_year << endl;  // print the year
    cout << "Month: " << 1 + ltm->tm_mon << endl;    // print month number
    cout << "Day: " << ltm->tm_mday << endl;         // print the day
    // Print time in hour:minute:second
    cout << "Time: " << 5 + ltm->tm_hour << ":";
    cout << 30 + ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;
    return 0;
}
