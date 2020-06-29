#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll t , x , y , a , b , c , d;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>x>>y>>a>>b;
		c = (y-x);
		d = (a+b);
		if(c%d==0)
			cout<<c/d<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}