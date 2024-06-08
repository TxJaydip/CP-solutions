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
		ll count = 0;
		ll o_sum = 0;
		
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i] == 1)
				count++;
			o_sum += a[i];	
		}
		if( ( ( 2 * count ) + ( n - count ) ) <= o_sum && n!=1 )
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}
