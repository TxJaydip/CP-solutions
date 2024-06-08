#include "bits/stdc++.h"
using namespace std;

#define ll long long int

bool isprime(ll n)
{
	for(ll i=2;i<=(sqrt(n)); i++ )
	{
		if(n%i == 0)
		{
			return false;
		}
	}
	return true;
}

ll nxtdiv(ll n1, ll n2)
{
	for(ll i=n2;i<=(n1/2); i++)
	{
		if(n1%i == 0)
		{
			return i;
		}
	}
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll x;
		cin >> x;
		ll n = x;
		vector<int> v1;
		vector<int> v2;
		ll pflag = 0;
		while(true)
		{
			if(n == 2)
			{
				v1.push_back(2);
				v1.push_back(1);
				break;
			}
			if(n == 4)
			{
				v1.push_back(2);
				v1.push_back(1);
				break;
			}
			if(n == 3)
			{
				v1.push_back(2);
				v1.push_back(1);
				break;
			}
			if(n == 5)
			{
				v1.push_back(4);
				v1.push_back(2);
				v1.push_back(1);
				break;
			}
			if(isprime(n))
			{
				n -= 1;
				v2.push_back(1);
				pflag = 1;
			}
			else
			{
				
			}
		}
		
	}
	return 0;
}
