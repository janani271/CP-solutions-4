#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003

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
struct node
{
	ll a , b , c , d;
};

node matmul(node aa, node bb)
{
	node ans;
	ans.a = add(mul(aa.a,bb.a),mul(aa.b,bb.c));
	ans.b = add(mul(aa.a,bb.b),mul(aa.b,bb.d));
	ans.c = add(mul(aa.c,bb.a),mul(aa.d,bb.c));
	ans.d = add(mul(aa.c,bb.b),mul(aa.d,bb.d));
	return ans;
}

node exp (node x, ll y)
{
	if(y==1) return x;
	node ans = exp(x,y/2);
	ans = matmul(ans,ans);
	if(y&1) ans = matmul(ans,x);
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;
	ll n;
	cin>>n;
	node mat = {2,3,1,0}; //matrix to multiply with
	node bc = {0,1,0,0}; //base case

	mat = exp(mat,n); //after matrix expo
	node ans = matmul(bc,mat);

	cout<<ans.b;
	return 0;
}