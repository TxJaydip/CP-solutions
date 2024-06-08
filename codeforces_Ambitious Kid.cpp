#include "bits/stdc++.h"
using namespace std;

#define ll long long int

int main()
{
	ll n;
	cin>>n;
	ll temp, min = INT_MAX, max = INT_MIN;
	for(ll i=0;i<n;i++)
	{
		cin>>temp;
		if(temp<min && temp>=0)
			min = temp;
		if(temp>max && temp<=0)
			max = temp;
	}
	if(min == 0 || max == 0)
		cout<<0<<endl;
	else
	{
		if(abs(min) <= abs(max))
		{
			cout<<abs(min)<<endl;
		}
		else
		{
			cout<<abs(max)<<endl;
		}
	}
	
	
	return 0;
}
