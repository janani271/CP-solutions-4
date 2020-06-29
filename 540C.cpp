#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 501
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

ll n,m,r1,c1,r2,c2;
ll visited[MAX][MAX];
char a[MAX][MAX];

bool valid(ll x, ll y)
{
	if(1<=x && x<=n && 1<=y && y<=m) return true;
	return false;
}

bool check(ll x, ll y)
{
	if(x==r2 && y==c2 && visited[x][y]<=1) return true;
	if((x!=r2 || y!=c2) && !visited[x][y]) return true;
	return false;
}
	
void dfs(ll x,ll y)
{
	// cout<<"x : "<<x<<"\ty : "<<y<<"\n";
	visited[x][y] += 1;
	
	if(a[x][y]=='X' && (x!=r1 || y!=c1)) return;

	if(valid(x+1,y) && check(x+1,y)) dfs(x+1,y);
	if(valid(x-1,y) && check(x-1,y)) dfs(x-1,y);
	if(valid(x,y-1) && check(x,y-1)) dfs(x,y-1);
	if(valid(x,y+1) && check(x,y+1)) dfs(x,y+1);

	if(x==r2 && y==c2) return;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	cin>>r1>>c1;
	cin>>r2>>c2;

	dfs(r1,c1);
	if((r1==r2 && c1==c2 && visited[r2][c2]>=2) || ((r2!=r1 || c2!=c1) && visited[r2][c2]>=1))
	{
		ll c=0;
		if(valid(r2,c2-1) && a[r2][c2-1]=='.') c++;
		if(valid(r2,c2+1) && a[r2][c2+1]=='.') c++;
		if(valid(r2-1,c2) && a[r2-1][c2]=='.') c++;
		if(valid(r2+1,c2) && a[r2+1][c2]=='.') c++;
		// cout<<"c : "<<c<<"\n";
		if(a[r2][c2]=='.' && ((abs(r1-r2)+abs(c1-c2)<=1 && c<1)||(abs(r1-r2)+abs(c1-c2)>1 && c<2)))
		{
			cout<<"NO";
			return 0;
		}
		cout<<"YES";
	} 
	else cout<<"NO";

	return 0;
}