#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		ll b[n][2];
		ll max = -21;
		ll min = 21;
		ll maxIndex = 0;
		ll minIndex = 0;
		ll flag = 0;
		ll flag2 = 0;
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
			if( i > 0 && a[i]!=a[i-1] )
			{
				flag=1;
			}
			if(a[i] > max)
			{
				max = a[i];
				maxIndex = i;
			}
			if(a[i] < min)
			{
				min = a[i];
				minIndex = i;
			}
			
			if(a[i]>0)
			{
				flag2 = 1;
			}
		}
		
		ll count = 0;
		ll bi=0;
		if(flag2 == 1)
		{
			a[n-1] += a[maxIndex];
			
			b[bi][0] = n;
			b[bi++][1] = maxIndex+1;
			count++;
		}
		
		while(a[n-1]<=max && flag==1)
		{
			a[n-1] += a[maxIndex];
			b[bi][0] = n;
			b[bi++][1] = maxIndex+1;
			count++;
		}
//		cout<<"End of array: "<<a[n-1]<<endl;
		ll flag3=0;
		for( ll i = 0 ; i < n - 1 && flag2 == 1 ; i++ )
		{
			cout<<"\n in first for";
			long long int j=0;
			if(a[i]>a[i+1])
			{
				for(;j<n;)
				{
					if( a[i+1] + a[j] >=a[i] )
					{
						a[i+1] += a[j];
						b[bi][0] = i+2;
						b[bi++][1] = j+1;
						count++;
						break;
					}
					else if(j==n-1)
					{
						a[i+1] += a[j];
						b[bi][0] = i+2;
						b[bi++][1] = j+1;
						count++;
						j=0;
						continue;
					}
					j++;
				}
			}
		}
		
		if(flag2==0)
		{
			a[n-1] += a[minIndex];
				
			b[bi][0] = n;
			b[bi++][1] = minIndex+1;
			count++;
			
			while(a[n-1]<=min)
			{
				a[n-1] += a[minIndex];
				b[bi][0] = n;
				b[bi++][1] = minIndex+1;
				count++;
			}
			for( ll i = 0 ; i < n - 1 ; i++ )
			{
				ll j=0;
				if(a[i]>a[i+1])
				{
					for(;j<n;)
					{
						if( a[i] + a[j] <=a[i+1] )
						{
							a[i] += a[j];
							b[bi][0] = i+1;
							b[bi++][1] = j+1;
							count++;
							break;
						}
						else if(j==n-1)
						{
							a[i+1] += a[j];
							b[bi][0] = i+2;
							b[bi++][1] = j+1;
							count++;
							j=0;
							continue;
						}
						j++;
					}
				}
			}
		}
		
		cout<<count<<endl;
		for(ll i=0;i<count;i++)
		{
			cout<<b[i][0]<<" "<<b[i][1]<<endl;
		}
		
	}
	
	return 0;
}
