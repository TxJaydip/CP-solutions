#include "bits/stdc++.h"
using namespace std;

#define ll long long int

ll formula(ll n, ll count)
{
	return ( (count * n) - ( count * ( count + 1 ) / 2 ) );
}

ll minu(ll a, ll b)
{
	if(a<b)
		return a;
	return b;
}

ll roots(ll b, ll c)
{
	if(b == -1 && c == 2)
		return 1;
	ll r1 = ( (-b) + (sqrt( (b*b)-(4*c) )) )/(2);
	ll r2 = ( (-b) - (sqrt( (b*b)-(4*c) )) )/(2);
	return minu(r1, r2);
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		
		ll b1 = n*(n-1)/2;
		ll n2 = n;
		ll b[b1];
		for(ll i=0;i<b1;i++)
		{
			cin>>b[i];
		}
//	";
		sort(b, b+b1);
		if(n==2 || n==3)
		{
			if(n==2)
			{
				cout<<b[0]<<" "<<b[0]<<endl;
			}
			if(n==3)
			{
				if(b[0] == b[1] && b[1]!=b[2])
					cout<<b[0]<<" "<<b[2]<<" "<<b[2]<<endl;
				else
					cout<<b[0]<<" "<<b[0]<<" "<<b[0]<<endl;
			}
		}
		else
		{
			
			ll temp = b[0];
			ll ans = 0;
			ll count = 0;
			ll x,y,z;
			ll count2 = 0;
			for( ll i = 0 ; i < b1 ; i++ )
			{
				if(i>0)
//				cout<<"\nin for \t"<<"b[i]: "<<b[i]<<", b[i-1]: "<<b[i-1];
				if( i>0 && b[i] != b[i-1])
				{
//					cout<<"\nin if\tn2: "<<n2<<",\t|| b[i]: "<<b[i]<<endl;
					x = 1;
					y = 1-(2*n2);
					z = 2*ans;
					count = roots(y, z);
//					cout<<"\n\ty: "<<y<<", z: "<<z<<",ROOT: "<<count<<endl;
					count2 += count;
					for(ll j=0;j<count;j++)
						cout<<temp<<" ";
					n2 = n2 - count;
					ans = 0;
				}
				temp = b[i];
				ans++;
			}
			if(count2<n)
			{
				for(ll i=0;i<(n-count2);i++)
					cout<<b[b1-1]<<" ";
			}
			cout<<endl;
		}
		
		
		
	}
	
	return 0;
}
