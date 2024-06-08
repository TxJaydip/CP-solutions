#include "bits/stdc++.h"
using namespace std;

#define ll long long int


int main()
{
	ll t, n, count, temp, j, ans, k;
	string s;
	cin>>t;
	vector<ll> v1;
	while(t--)
	{
		
		cin>>n;
		ll a[n];
		for(ll i = 0;i<n;i++)
		{
			cin>>temp;
//			cin>>a[i];
			v1.push_back(temp);
		}
		count = n;
		ans = 0;
		k = n-1;
		while(count>0)
		{
			j = count-1;
			while(j>=0)
			{
				if( == count)
				{
					count --;
//					
				}
				
				if(j == 0)
				{
					ans+=1;
				}
				j--;
			}
		}
		cout<<ans-1<<endl;
//		v1.clear();
	}
	
	return 0;
}
