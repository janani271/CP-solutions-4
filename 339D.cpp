#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 132000

ll MOD=1e9+7;
ll tree[4*MAX] , n , num , m , i , a[MAX];

ll power(ll x, ll y)
{
	if(y==0)
		return 1;
	ll c = power(2,y/2);
	x = c*c;
	if(y&1) x*=2;
	return x;
}

void build(ll node, ll l , ll r , ll level)
{
	if(l==r)
	{
		tree[node] = a[l];
		// cout<<"LEAF "<<l<<" : "<<tree[node]<<"\n";
		return;
	}
	if(l>r) return;

	ll mid =(l+r)/2;
	build(2*node,l,mid,level+1);
	build(2*node+1,mid+1,r,level+1);
	if((n%2==0 && level%2==0)||(n%2==1 && level%2==1))
		tree[node] = tree[2*node] | tree[2*node+1];
	else 
		tree[node] = tree[2*node] ^ tree[2*node+1];
	// cout<<"l : "<<l<<"\tr : "<<r<<"\tlevel : "<<level<<"\tval : "<<tree[node]<<"\n";
}

void update(ll node, ll l , ll r , ll level , ll p , ll b)
{
	if(l==r)
	{
		// cout<<"LEAF "<<l<<" : "<<tree[node]<<"\n";
		if(l==p)
		{
			tree[node] = b;
			// cout<<l<<" node updated to "<<tree[node]<<"\n";
		}
		return;
	}
	if(l>r || (l>p) || (r<p)) return;

	ll mid = (l+r)/2;
	update(2*node,l,mid,level+1,p,b);
	update(2*node+1,mid+1,r,level+1,p,b);
	if((n%2==0 && level%2==0)||(n%2==1 && level%2==1))
		tree[node] = tree[2*node] | tree[2*node+1];
	else 
		tree[node] = tree[2*node] ^ tree[2*node+1];	
	// cout<<"l : "<<l<<"\tr : "<<r<<"\tlevel : "<<level<<"\tval : "<<tree[node]<<"\n";
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	ll p , b;
	cin>>n>>m;
	num = power(2,n);
	// cout<<n<<"\n";
	for(i=0;i<num;i++)
	{
		cin>>a[i];
	}
	
	build(1,0,num-1,1);
	
	for(i=0;i<m;i++)
	{
		cin>>p>>b;
		update(1,0,num-1,1,p-1,b);
		cout<<tree[1]<<"\n";
	}
	return 0;
}