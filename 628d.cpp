#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[2001][2001][2][2] , d , m , MOD=1e9+7 , n;
string a , b;

ll digit(ll pos , ll rem , bool l , bool r)
{
	if(pos==n)
	{
		if(rem==0) return 1;
		else return 0;
	}
	if(dp[pos][rem][l][r]!=-1) return dp[pos][rem][l][r];
	
	ll st = 0, en=9, i, res=0;
	bool ln , rn;

	if(!l)
		st = a[pos]-'0';
	if(!r)
		en = b[pos]-'0';
	// cout<<pos<<" "<<st<<" "<<en<<"\n";
	for(ll i=st;i<=en;i++)
	{
		if(pos%2==0 && i==d) continue;
		if(pos%2==1 && i!=d) continue;
		ln=false , rn=false;
		ln = l || (i>a[pos]-'0');
		rn = r || (i<b[pos]-'0');
		// cout<<"i: "<<i<<"\tpos: "<<pos<<"\trem"<<(rem*10 + i)%m<<"\n";
		res = (res + digit(pos+1,((rem*10)+i)%m,ln,rn))%MOD;
	}
	res = res%MOD;
	return dp[pos][rem][l][r] = res;
}

int main()
{
	cin>>m>>d;
	cin>>a>>b;
	n = a.length();
	memset(dp,-1,sizeof(dp));
	cout<<digit(0,0,0,0);
	return 0;
}





