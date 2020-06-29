#include<bits/stdc++.h>
using namespace std;
long long t , s,a;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>s;
		if(s>=10)
		{
			a = s + (s/9);
			if(s%9==0)
			{
				a--;
			}
		}
		else a = s;
		cout<<a<<"\n";
	}
	return 0;
}