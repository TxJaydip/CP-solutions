#include "bits/stdc++.h"
using namespace std;

#define ll long long int

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll m, k, a1, ak, flag, f1;
		cin>> m>> k>> a1>> ak;
		ll sum = (k*ak) + a1;
		sum = m - sum;
		if(sum<=0)
		{
			cout<<0<<endl;
		}
		else if(sum%k == 0)
		{
			cout<<(sum/k)<<endl;
		}
		else
		{
			sum = (ak*k) + a1;
			ll sum2 = floor( () )
			
			
		}
	}
	
	return 0;
}
