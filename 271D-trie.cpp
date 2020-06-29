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

int n,i,g[30],k,cnt,j,res;
string s,str;

struct trie
{
	trie* ptr[28];
	//char c; //cur char value
	//bool is_end; //is the last char in a string?
};

trie* new_node()
{
	trie* node = new trie;
	for(int i=0;i<28;i++) node->ptr[i]=NULL;
	return node;
}

void insert(trie* root, string x)
{
	// if(root==NULL) root=new_node();
	trie* temp = root;
	int len = x.length(),cur,i;
	for(i=0;i<len;i++)
	{
		cur = x[i]-'a';
		if(temp->ptr[cur]==NULL)
		{
			temp->ptr[cur] = new_node();
			res++;
		}
		temp = temp->ptr[cur];
	}
}

//query()

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	char x;
	cin>>s;
	n = s.length();
	for(i=0;i<26;i++)
	{
		cin>>x;
		g[i] = x-'0';
	}
	cin>>k;
	trie* root = new_node();
	res=0;
	for(i=0;i<n;i++)
	{
		cnt=0;str="";
		for(j=i;j<n;j++)
		{
			if(!g[s[j]-'a']) cnt++;
			if(cnt>k) break;
			str += s[j];
		}
		insert(root,str);
	}
	cout<<res;
	return 0;
}