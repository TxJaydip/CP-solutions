#include "bits/stdc++.h"
using namespace std;

#define ll long long int


int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll b, c, h;
		cin>>b>>c>>h;
		ll betn = c + h;
		if(b<=betn)
		{
			cout<< ( b + (b-1) ) <<endl;
		}
		else
		{
			cout<< (  betn + (betn + 1) )<<endl;
		}
			
	}
	
	return 0;
}
