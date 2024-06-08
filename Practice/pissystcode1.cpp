#include "bits/stdc++.h"
using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>

int main()
{
    int curr = 21;
    int flag = 0;
    int input;
    while (true)
    {
        if (curr == 0)
        {
            break;
        }
        if (flag == 0)
        {
            int flag1 = 0;
            while (flag1 != 1)
            {
                if (flag1 == 2)
                {
                    cout << "Wrong choice, select 1 to 4 sticks" << endl;
                }
                if (flag1 == 3)
                {
                    cout << "Input should be less or equal to remaim=ning sticks" << endl;
                }
                cout << "Enter sticks: ";
                string inputS;
                cin >> inputS;
                {
                    if (inputS.length() > 1)
                    {
                        cout << "Wrong input(Too Large)" << endl;
                        flag1 = 0;
                        continue;
                    }
                    else
                    {
                        try
                        {
                            input = stoi(inputS);
                        }
                        catch (exception e)
                        {
                            cout << "Wrong input charcters" << endl;
                            continue;
                        }
                    }
                }

                if (input > curr)
                {
                    flag1 = 3;
                }
                else if (input <= 4 && input >= 1)
                {
                    flag1 = 1;
                }
                else
                {
                    cout << "Wrong input" << endl;
                    flag = 2;
                }
            }

            curr -= max(input, 1);
            cout << "Remaining sticks: " << curr << endl;
            flag = 1;
        }
        else
        {
            int st = 0;
            if (curr >= 10)
            {
                st = 1;
            }
            else if (curr == 5)
            {
                st = 4;
            }
            else if (curr > 5)
            {
                st = curr % 5 - 1;
            }
            else if (curr < 5)
            {
                st = curr - 1;
            }
            cout << "Computer selected : " << st << " sticks, remaining: ";
            curr -= st;
            cout << curr << endl;
            flag = 0;
        }
    }
    if (flag)
    {
        cout << "Computer Won" << endl;
    }
    else
    {
        cout << "You won" << endl;
    }

    return 0;
}