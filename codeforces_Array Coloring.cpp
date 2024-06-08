#include "bits/stdc++.h"
using namespace std;

#define ll long long int

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		ll temp;
		ll count = 0;
		for(ll i=0;i<n;i++)
		{
			cin>>temp;
			if(temp%2 == 1)
				count++;
		}
		if(count%2 == 0)
		{
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;
		
		
	}
	
	return 0;
}
