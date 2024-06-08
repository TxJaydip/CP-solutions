#include "bits/stdc++.h"
using namespace std;

#define ll long long int


int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n, k;
		cin>>n>>k;
		string s;
		cin>>s;
		char a;
		if(k%2 == 1)
		{
			ll i=0;
			for( ;; )
			{
				if(i == n-2)
					break;
				if( s[i] > s[i+2] )
				{
					a = s[i];
					s[i] = s[i+2];
					s[i+2] = a;
					i = i-2;
					if(i<0)
						i = 0;
				}
				else
					i++;
			}
			cout<<s<<endl;
		}
		else
		{
			sort(s.begin(), s.end());
			cout<<s<<endl;
		}
		
		
	}
//	cout<<"Enter a: ";
//	cout<<( 'a'< 'b' )<<" "<<( 'b' < 'a' ) <<" "<<( 'a' == 'b' );
	
	return 0;
}
