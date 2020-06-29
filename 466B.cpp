#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003
#define INF 1000000000000000005

using namespace std;

ll MOD=1e9+7;

ll add(ll a,ll b)
{
	return ((a%MOD) + (b%MOD))%MOD;
}
ll mul(ll a,ll b)
{
	return ((a%MOD) * (b%MOD))%MOD;
}
ll sub(ll a,ll b)
{
	return ((a%MOD) - (b%MOD) + MOD)%MOD;
}
ll n,a,b,i,c,d,x,y,f,s,ans,aa,bb;
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>c>>d;
	n *= 6;
	if(c*d > n)
	{
		cout<<c*d<<"\n";
		cout<<c<<" "<<d;
		return 0;
	}
	ans = n*100;
	aa = n*100;
	bb = n*100;
	for(i=1;i*i<=n;i++)
	{
		x = i;
		y = (n/i);
		a=0; b=0;
		if(n%x!=0) a=1;
		if(n%y!=0) b=1;
		f = (x+a)*y;
		s = x*(y+b);
		if(f>=n && f<=ans && ((x+a>=c && y>=d)||(x+a>=d && y>=c)))
		{
			// cout<<"x : "<<x<<"\ty : "<<y<<"\n";
			// cout<<"f : "<<f<<"\ts : "<<s<<"\n";
			ans = f;
			if(c>d) 
			{
				aa=max(x+a,y);
				bb=min(x+a,y);
			}
			else
			{
				bb=max(x+a,y);
				aa=min(x+a,y);
			}
		}
		if(s>=n && s<=ans && ((x>=c && y+b>=d)||(x>=d && y+b>=c)))
		{
			ans = s;
			if(c>d) 
			{
				aa=max(x,y+b);
				bb=min(x,y+b);
			}
			else
			{
				bb=max(x,y+b);
				aa=min(x,y+b);
			}
		}
	}
	cout<<ans<<"\n"<<aa<<" "<<bb;
	return 0;
}