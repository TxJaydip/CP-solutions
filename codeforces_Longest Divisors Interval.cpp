#include "bits/stdc++.h"
using namespace std;

#define ll long long int

int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll count = 1;
		while (true)
		{
			if ((n % (count + 1)) == 0)
				count++;
			else
				break;
		}
		cout << count << endl;
	}

	return 0;
}
