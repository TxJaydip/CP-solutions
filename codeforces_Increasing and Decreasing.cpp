#include "bits/stdc++.h"
using namespace std;

#define ll long long int

ll sum(ll n)
{
	return ( (n*(n+1))/2 );
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll x, y, n;
		cin>>x>>y>>n;
		
		if( (y-x) >= sum(n-1) )
		{
			ll a[n];
			ll j = y;
			ll cnt = 1;
			
			for( ll i = n-1 ; i >= 0 ; i-- )
			{
				if(i == 0)
				{
					a[i] = x;
				}
				else
				{
					a[i] = j;
					j -= cnt;
					cnt++;
				}
				
			}
			
			for(ll i=0; i<n;i++)
			{
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
		
	}
	
	return 0;
}
