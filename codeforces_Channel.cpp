#include "bits/stdc++.h"
using namespace std;

#define ll long long int


int main()
{
	ll t, a, n, q, count1, count2, flag2;
	string s;
	cin>>t;
	while(t--)
	{
		flag2 = 0;
		cin>>n>>a>>q;
		cin>>s;
		if(a == n)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			count1 = a;
			count2 = a;
			for(ll i=0;i<q;i++)
			{
				if(s[i] == '+')
				{
					count1++;
					count2++;					
				}
				else
				{
					count2--;
				}
				if(count2 == n)
				{
					flag2 = 1;
					break;
				}
				
			}
			if(flag2 == 1)
			{
				cout<<"YES"<<endl;
			}
			else if(count1 >= n)
			{
				cout<<"MAYBE"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
		
	}
	
	return 0;
}
