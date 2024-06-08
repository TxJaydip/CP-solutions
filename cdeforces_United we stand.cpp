#include "bits/stdc++.h"
using namespace std;

#define ll long long int
//#define cout cout<<"\t"
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		ll count=1;
		ll flag = 0;
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		sort(a, a+n);
		if(a[0]==a[n-1])
		{
			cout<<"-1"<<endl;
		}
		else
		{
			for(ll i=n-1;i>1;i--)
			{
				if(a[i] == a[i-1])
				{
					count++;
				}
				else
					break;
			}
			cout<<(n-count)<<" "<<count<<endl;
			for(ll i=0;i<(n-count);i++)
				cout<<a[i]<<" ";
			cout<<endl;
			for(ll i=(n-count);i<n;i++)
				cout<<a[i]<<" ";
			cout<<endl;
		}	
		
	}
	
	return 0;
}
