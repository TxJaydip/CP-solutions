#include "bits/stdc++.h"
using namespace std;

#define ll long long int


int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n, m, k, h;
		cin>>n>>m>>k>>h;
		ll steps[m];
		for(ll i=0;i<m;i++)
		{
			steps[i] = (i+1)*k;
		}
		
		ll a[n][2];
		for(ll i=0;i<n;i++)
		{
			cin>>a[i][0];
			a[i][1]=0;
		}
		ll count=0;
		
		ll hgt = 0;
		ll person=0;
		ll phgt=0;
		for(ll i=0;i<n;i++)
		{
			hgt = h+steps[i];
			cout<<"\nheight: "<<hgt;
			for(ll j = 0;j<n;j++)
			{
				if(a[j][1]==1)
				{
					continue;
				}
				person = a[j][0];
				cout<<", person: "<<person;
				for(ll z=0;z<n;z++)
				{
					if(i == z)
					{
						continue;
					}
					phgt = person + steps[z];
					cout<<endl<<"  -->  person's height: "<<phgt;
					if( abs( h-person ) == abs( steps[i] - steps[z] ) )
					{
						count++;
						a[j][1]=1;
					}
					
				} // for z
			} // for j
		} // for i
		cout<<"ans: "<<count<<endl;
		
		
	}
	
	return 0;
}
