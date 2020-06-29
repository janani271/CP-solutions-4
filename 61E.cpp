#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 1000003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll n,a[MAX];
vll tree[4*MAX];

vll merge_nodes(vll p, vll q)
{
    ll len1 = p.size();
    ll len2 = q.size();
    ll i=0,j=0,k=0;
    vll v;
    while(i<len1 && j<len2)
    {
        if(p[i]<=q[j]) v.pb(p[i++]);
        else v.pb(q[j++]);
    }
    while(i<len1) v.pb(p[i++]);
    while(j<len2) v.pb(q[j++]);
    return v; 
}

void build(ll node, ll start, ll end)
{
    if(start==end)
    {
        tree[node].pb(a[start]);
        return;
    }
    if(start>end) return;
    ll mid = (start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node] = merge_nodes(tree[2*node],tree[2*node+1]);
}

ll query(ll node, ll start, ll end, ll l, ll r, ll x)
{
    if(r<start || l>end || start>end) return 0;
    if(l<=start && end<=r)
    {
        auto pos = lower_bound(tree[node].begin(),tree[node].end(),x);
        return pos-(tree[node].begin());
    }
    ll mid = (start+end)/2;
    return query(2*node,start,mid,l,r,x) + query(2*node+1,mid+1,end,l,r,x);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastread;

    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    build(1,0,n-1);

    ll ans=0;
    for(ll j=1;j<n-1;j++)
    {
        ll left = query(1,0,n-1,0,j-1,a[j]);
        left = j - left;
        ll right = query(1,0,n-1,j+1,n,a[j]);
        ans += (left*right); 
    }
    cout<<ans;
    return 0;
}