#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 100005

ll tree[25][4*SIZE] , lazy[25][4*SIZE] , a[SIZE];

void build(ll node , ll s , ll e , ll bit)
{
	if(s==e)
	{
		tree[bit][node] = 0;
		if(a[s] & (1<<bit))
		{
			tree[bit][node] = 1;
		}
		return ;
	}
	ll mid = (s+e)/2;
	build(2*node,s,mid,bit);
	build(2*node+1,mid+1,e,bit);
	tree[bit][node] = tree[bit][2*node] + tree[bit][2*node+1];
}


void update(ll node, ll s, ll e , ll bit , ll lf , ll rf)
{
	if(lazy[bit][node])
	{
		// cout<<"hello";
		tree[bit][node] = (e-s+1) - tree[bit][node];
		if(s!=e)
		{
			lazy[bit][2*node] ^=1;
			lazy[bit][2*node+1] ^=1;
		}
		lazy[bit][node] = 0;
	}

	if(s>e || s>rf || e<lf) return;

	if(s>=lf && e<=rf)
	{
		tree[bit][node] = (e-s+1) - tree[bit][node];
		if(s!=e)
		{
			lazy[bit][2*node] ^=1;
			lazy[bit][2*node+1] ^=1;
		}
		return;
	}

	ll mid = (s+e)/2;
	update(2*node,s,mid,bit,lf,rf);
	update(2*node+1,mid+1,e,bit,lf,rf);
	tree[bit][node] = tree[bit][2*node] + tree[bit][2*node+1];
}

ll query(ll node, ll s, ll e , ll bit , ll lf , ll rf)
{
	if(lazy[bit][node])
	{
		tree[bit][node] = (e-s+1) - tree[bit][node];
		if(s!=e)
		{
			lazy[bit][2*node]^=1;
			lazy[bit][2*node+1]^=1;
		}
		lazy[bit][node] = 0;
	}

	if(s>e || s>rf || e<lf) return 0;

	if(s>=lf && e<=rf)
		return tree[bit][node];

	ll mid = (s+e)/2;
	return query(2*node,s,mid,bit,lf,rf) + query(2*node+1,mid+1,e,bit,lf,rf);
}

int main()
{
	ll n , i , j , m , t , l , r , x , sum ;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}

	for(i=0;i<20;i++)
	{
		build(1,0,n-1,i);
	}

	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>t;
		if(t==1)
		{
			cin>>l>>r;
			sum = 0;
			for(j=0;j<20;j++)
			{
				// cout<<query(1,0,n-1,j,l-1,r-1)<<"\n";
				sum += (query(1,0,n-1,j,l-1,r-1) * (1<<j));
			}
			cout<<sum<<"\n";
		}
		else
		{
			cin>>l>>r>>x;
			for(j=0;j<20;j++)
			{
				if(x & 1<<j)
					update(1,0,n-1,j,l-1,r-1);
			}
		}
	}
	return 0;
}