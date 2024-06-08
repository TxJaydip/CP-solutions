#include "bits/stdc++.h"
using namespace std;

#define ll long long int

bool compareValues(const pair<ll, ll>& a, const pair<ll, ll>& b)
{
    return a.first < b.first;
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n, k, temp;
		cin>>n>>k;
		ll a[n][2];
		for(ll i=0;i<n;i++)
		{
			a[i][1]=i+1;
		}
		for(ll i=0;i<n;i++)
		{
			cin>>temp;
			temp = temp % k;
			a[i][0] = temp;			
		}
		ll flag=0, temp2;
		for(ll i=0;i<n-1;i++)
		{
			for(ll j=i+1;j<n-i;j++)
			{
				if(a[i][0] > a[j][0])
				{
					temp = a[j][0];
					temp2 = a[j][1];
					a[j][0] = a[i][0];
					a[j][1] = a[i][1];
					
					a[i][0] = temp;
					a[i][1] = temp2;
					
					flag=1;
				}
			}
			if(flag == 0)
				break;
		}
		
	}
	
	return 0;
}
