#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 100003

ll MOD=1e9+7;

int main()
{
	ll t , a , b , x , y , a1 , a2 , a3 , a4;
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>t;
	while(t--)
	{
		cin>>a>>b>>x>>y;

		a1 = (a*y);
		a2 = (a*(b-y-1));
		a3 = (b*(a-x-1));
		a4 = (b*x);

		cout<<max(a1,max(a2,max(a3,a4)))<<"\n";
	}
	return 0;
}