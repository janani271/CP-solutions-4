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

ll n,m;
string s;

struct trie
{
	trie* next[3];
	bool is_end;
};

trie* new_node()
{
	trie* node = new trie;
	for(ll i=0;i<3;i++) node->next[i]=NULL;
	node->is_end = false;
	return node;
}

void insert(trie* root, string s)
{
	if(root==NULL) root = new_node();
	trie* head = root;
	ll len = s.length();
	for(ll i=0;i<len;i++)
	{
		if(head->next[s[i]-'a']==NULL)
			head->next[s[i]-'a'] =  new_node();
		head = head->next[s[i]-'a'];
	}
	head->is_end = true;
}

ll dfs(trie* root,ll cur, ll len, ll flag)
{
	if(cur==len)
	{
		if(root!=NULL && root->is_end && flag==1) return 1;
		return 0;
	}
	
	ll f = 0;
	char c = s[cur]-'a'; 
	for(ll i=0;i<3;i++)
	{
		if(c==i && root->next[i]!=NULL)
		{
			f = max(f,dfs(root->next[i],cur+1,len,flag));
		}
		else if(c!=i && !flag && root->next[i]!=NULL)
		{
			f = max(f,dfs(root->next[i],cur+1,len,flag+1));
		}
	}
	return f;
}


int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m;
	trie* root = new_node();
	for(ll i=0;i<n;i++)
	{
		cin>>s;
		insert(root,s);
	}
	for(ll i=0;i<m;i++)
	{
		cin>>s;
		if(dfs(root,0,s.length(),0))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}