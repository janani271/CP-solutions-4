#include<bits/stdc++.h>
using namespace std;
double n,ans,i;
int main()
{
	cin>>n;
	ans=0.0;
	for(i=1;i<=n;i++)
	{
		ans += (1/i);
	}
	cout<<ans;
	return 0;
}