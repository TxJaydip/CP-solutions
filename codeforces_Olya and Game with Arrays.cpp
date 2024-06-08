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
		ll m[n];
		ll min[n][2];
		ll m1, m2;
//		int vector<vector<int>> a;
		for(ll i=0;i<n;i++)
		{
			m1 = 50001;
			m2 = 50001;
			cin>>m[i];
			ll a[m[i]];
			for(ll j=0;j<m[i];j++)
			{
				cin>>a[j];
				if( m1 == 50001 )
				{
					m1 = a[j];
					
				}
				else if( a[j]<=m1 )
				{
					m2 = m1;
					m1 = a[j];
				}
				else if(a[j]<m2)
				{
					m2 = a[j];
				}
			}
			min[i][0] = m1;
			min[i][1] = m2;
		}
		m1 = 50001;
		m2 = 50001; // min(second min)
		ll index = 0;
		for(ll i=0;i<n;i++)
		{
			if(min[i][1]<m2)
			{
				
				m2 = min[i][1];
				index = i;
			}
			if(min[i][0]<m1)
			{
				m1 = min[i][0];
			}
		}
		ll sum =0;
		for(ll i=0;i<n;i++)
		{
			if(i == index)
				sum+=m1;
			else
				sum+=min[i][1];
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
