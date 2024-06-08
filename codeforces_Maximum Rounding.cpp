#include "bits/stdc++.h"
using namespace std;

#define ll long long int

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string s1;
		cin>>s1;
		string s = "0"+s1;
		int a[s.length()];
		for(ll i=0;i<s.length();i++)
		{
			a[i] = (s[i] - '0');
		}
		for( ll i = 0 ; i < s.length() ; i++ )
		{
			if( a[i] >= 5 )
			{
				if(a[i-1] == 4)
				{
					ll c = i-1;
					while(a[c] == 4)
					{
						c--;
					}
					c++;
					for(ll j = c; j<s.length();j++)
					{
						a[j] = 0;
					}
					a[c-1] = a[c-1]+1;
				}
				else
				{
					a[i]  = 0;
				
					for(ll j = i+1; j<s.length();j++)
					{
						a[j] = 0;
					}
					
					a[i-1] = a[i-1]+1;
				}
				break;				
			}
		}
//		cout<<"\tANS: ";
		if(a[0]!=0)
			cout<<a[0];
		for(ll i=1;i<s.length();i++)
		{
			cout<<a[i];
		}
		cout<<endl;
		
	}
	
	return 0;
}
