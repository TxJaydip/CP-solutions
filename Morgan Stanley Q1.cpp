/*
days
based on days - >> pass grneration
1 day pass : 1 Rs/day
Weekly pass : 5 Rs/week
Monthly Pass : 20 Rs/Month

input - > Number of days/Week
output - > The pass type


*/

#include <iostream>
using namespace std;

int main()
{
    int days;
    cout << "Input Number of days: ";
    cin >> days;

    if (days >= 3)
    {
        cout << "Monthly pass needed" << endl;
    }

    else if (days <= 2)
    {
        cout << "Daily pass needed" << endl;
    }

    return 0;
}