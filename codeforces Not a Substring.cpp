#include "bits/stdc++.h"
using namespace std;

#define ll long long int

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		ll n, flag = 0;
		cin>>s;
		n = s.length();
		if(s=="()")
			cout<<"NO"<<endl;
		else if(s=="((" || s=="))")
			cout<<"YES\n()()"<<endl;
		else if(s==")(")
			cout<<"YES\n(())"<<endl;
		else
		{
			flag = 0;
			cout<<"YES"<<endl;
			for(ll i=0;i<n-1;i++)
			{
				if( ( s[i]=='(' && s[i+1]=='(' ) || ( s[i]==')' && s[i+1]==')' ) )
				{
					flag = 1;
					break;
				}
			}
			if(flag == 1)
			{
				for(ll i=0;i<(2*n);i++)
				{
					if(i%2==0)
					{
						cout<<"(";
					}
					else
					{
						cout<<")";
					}
				}
				cout<<endl;
			}
			else
			{
				for(ll i=0;i<n;i++)
				{
					cout<<"(";
				}
				for(ll i=n;i<(2*n);i++)
				{
					cout<<")";
				}
				cout<<endl;
			}
		}
		
		
		
	}
	
	return 0;
}
