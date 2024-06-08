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
		ll a[n][2];
//		ll odd[n];
//		ll even[n];
		ll arr[n];
		ll odd_cnt=0;
		ll even_cnt=0;
		for(ll i=0;i<n;i++)
		{
			cin>>a[i][0];
			arr[i] = a[i][0];
//			a[i][1]=i;
			if(a[i][0]%2==0)
			{
//				even[even_cnt]=a[i][0];
//				even_cnt++;
				a[i][1]=0;
			}
			else
			{
//				odd[odd_cnt]=a[i][0];
//				odd_cnt++;
				a[i][1]=1;
			}
		}
//		sort(even, even + even_cnt);
//		sort(odd, odd + odd_cnt);
		sort(arr, arr+n);
		ll a2[n][2];
		for(ll i=0;i<n;i++)
		{
			a2[i][0]=arr[i];
			if(a2[i][0]%2==0)
			{
				a2[i][1]=0;
			}
			else
			{
				a2[i][1]=1;
			}
		}
		ll flag=0;
		for(ll i=0;i<n;i++)
		{
			if(a[i][1]==a2[i][1])
			{
				continue;
			}
			else
			{
				flag=1;
				cout<<"NO"<<endl;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"YES"<<endl;
		}
		
				
	}
	
	return 0;
}
