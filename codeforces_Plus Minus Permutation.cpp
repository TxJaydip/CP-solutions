#include "bits/stdc++.h"
#include "algorithm"
using namespace std;

#define ll long double

int main()
{
	ll t;
	ll t1 = 1;
	cin >> t;
	while (t--)
	{
		ll n, x, y;

		cin >> n >> x >> y;
		long long int x1 = x, y1 = y;

		ll n1, n2, n3, sum1, sum2;
		ll lcm = (x1 * y1) / __gcd(x1, y1);
		n3 = floor((n) / (lcm));
		n1 = floor(n / x) - n3;
		n2 = floor(n / y) - n3;
		//		cout<<"n1: "<<n1<<", n2: "<<n2<<", n3: "<<n3<<endl;
		sum1 = (n * (n1)) - ((n1 * (n1 - 1)) / 2);
		sum2 = n2 * (n2 + 1) / 2;
		//		cout<<"Sum1: "<<sum1<<", sum2: "<<sum2<<endl;
		//		cout<<"\tAns: "<<sum1 - sum2<<endl;
		long long int ans = sum1 - sum2;
		cout << ans << endl;
	}

	return 0;
}