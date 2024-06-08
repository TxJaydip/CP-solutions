#include "bits/stdc++.h"
using namespace std;

#define ll long long int


int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n, k;
		cin>>n>>k;
		ll a[n];
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
		}
		ll clr = a[n-1];
		sort(a, a+n);
		ll cnt=1;
		ll max=0;
		ll flag=0;
		for(ll i=0;i<n;i++)
		{
			if(a[i]==clr)
			{
				max++;
			}
		}
		if(max>=k)
		{
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;		
	}
	
	return 0;
}
