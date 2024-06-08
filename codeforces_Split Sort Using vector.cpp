#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t, n, temp, count;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> v1;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			v1.push_back(temp);
		}
		reverse(v1.begin(), v1.end());
		count = n;
		int ans = 0;
		while(count>0)
		{
			vector<int>:: iterator it = v1.begin();
			for(int i:v1)
			{
				if(i == count)
				{
					count--;
					v1.erase(it);
				}
				if(it==v1.end()-1)
				{
					ans+=1;
					break;
				}
				it++;
			}
			
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}
