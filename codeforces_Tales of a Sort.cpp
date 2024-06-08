#include "bits/stdc++.h"
using namespace std;

#define ll long long int
//#define f2(i,n) for(ll i=n;i>=0;i--)
//#define f(i,n) for(ll i=0;i<n;i++)

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
		}
		ll count = 1;
//		f2(i,n-1,1)
		for(ll i=n-1;i>0;i--)
		{
			if(a[i]>=a[i-1])
			{
				count++;
			}
			else
				break;
		}
		ll max = 0;
		if(count == n)
		{
			cout<<0<<endl;
			continue;
		}
//		f(i,n-count)
		for(ll i=0;i<n-count;i++)
		{
			if(a[i]>max)
			{
				max = a[i];
			}
		}
		cout<<max<<endl;
	}
	
	return 0;
}
