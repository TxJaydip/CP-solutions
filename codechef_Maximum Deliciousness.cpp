#include "bits/stdc++.h"
using namespace std;

#define ll long long int

int count(string s, char a)
{
    int count = 0;
    for(int i=0;i<8;i++)
    {
        if(s[i] == a)
            count++;
    }
    return count;
}

int main ()
{
	ll t, k;
	string s;
	string c = "codechef";
	string o = "";
	cin>>t;
	while(t--)
	{
	    o = "11111111";
	    k = 0;
	    cin>>s;
	    if( count(s, 'e') >= 7 || count(s, 'c') >= 7 || count(s, 'o') == 8 || count(s, 'd') == 8 || count(s, 'h') == 8 || count(s, 'f') == 8 )
	    {
	        cout<<"-1"<<endl;
	    }
	    else
	    {
	    	for(int i = 0;i<8;i++)
	    	{
	    		for(int j = 0;j<8;j++)
	    		{
	    			if(c[i] == s[j])
	    			{
	    				for(int l = 0;l<8;l++)
	    				{
	    					if(c[i]!=s[l] && s[l]!='0')
	    					{
	    						o[i] = s[l];
	    						s[l] = '0';
	    						break;
							}
						}
						break;
					}
				}
			}
	        for(int i=0;i<8;i++)
	        {
	        	if(o[i]!='1')
	        		continue;
	            for(int j = 0;j<8;j++)
	            {
	                cout<<"for i : "<<i<<", for j: "<<j<<", c[i]: "<<c[i]<<", s[j]: "<<s[j]<<", o: "<<o<<", s: "<<s<<endl;
	                if(c[i] != s[j] && s[j]!='0')
	                {
	                    o[i]=s[j];
	                    s[j] = '0';
	                    break;
	                }
	            }
	        }
	        cout<<o<<endl;
	    }
	}
	
	return 0;
}
