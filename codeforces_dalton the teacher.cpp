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
		ll p[n];
		ll count = 0;
		for(ll i=0;i<n;i++)
		{
			cin>>p[i];
			if(p[i] == i+1)
			{
				count+=1;
			}
		}
		if(count%2==0)
		{
			cout<<count/2<<endl;
		}
		else
		{
			cout<<(count/2)+1<<endl;
		}
		
	}
	
	return 0;
}
