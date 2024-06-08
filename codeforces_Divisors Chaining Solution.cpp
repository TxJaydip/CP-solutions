#include "bits/stdc++.h"
using namespace std;

#define ll long long int

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<int> a;
		a.push_back(n);
		cout<<"n: "<<n<<endl;
		while( n & (n-1) )
		{
			cout<<"n & (n-1): "<< (n & (n-1) )<<endl;
			cout<<"n&-n: "<< (n&-n)<<endl;
			cout<<"n: "<<n<<endl;
			n -= n&-n;
			a.push_back(n);
		}
		cout<<"n & (n-1): "<< (n & (n-1) )<<endl;
		cout<<"n&-n: "<< (n&-n)<<endl;
		cout<<"n: "<<n<<endl;
		while(n>1)
		{
			cout<<"n: "<<n<<endl;
			n/=2;
			a.push_back(n);
		}
		for( vector<int> :: iterator it = a.begin(); it!=a.end();it++ )
		{
			cout<<*it<<" ";
		}
		cout<<endl;
		
	}
	
	return 0;
}
