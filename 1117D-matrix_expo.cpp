#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 102

using namespace std;

ll MOD=1e9+7;

ll ans[MAX][MAX], mat[MAX][MAX];
ll temp[MAX], n , m , i, j, k;
ll res[MAX][MAX];

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
 
 //matrix exp
 void matmul(ll a[][MAX],ll b[][MAX])
 {  //multiplies two matrices A and B and stores result in A
 	for(int i=1;i<=m;i++)
 	{
 		for(int j=1;j<=m;j++)
 		{
 			for(int k=1;k<=m;k++)
 			{
                 res[i][j]=(res[i][j]%MOD + (a[i][k]%MOD*b[k][j]%MOD)%MOD)%MOD;
            }
         }
 	}
 	for(i=1;i<=m;i++)
 	{
 		for(j=1;j<=m;j++)
 		{
 			a[i][j] = res[i][j];
 			res[i][j] = 0;
 		}
 	}
 }

 void matexp(ll ex)
 {
     while(ex>0)
     {
     	//ans->result matrix, mat->transition matrix
        if(ex%2==1) matmul(ans,mat);
        matmul(mat,mat);
        ex = ex/2;
     }
 }
 
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;
	cin>>n>>m;
	if(n<m)
	{
		cout<<"1"; return 0;
	}
	if(n==m)
	{
		cout<<"2"; return 0;
	}
	for(i=0;i<=m;i++)
	{
		ans[i][i] = 1;
		mat[i+1][i] = 1;
		temp[i] = 1;
	}
	temp[m] = 2;
	mat[m][m]=1; mat[1][m]=1;

	matexp(n-m);
	// matmul(temp,ans);
	// matexp(n-1);
	ll val=0;
	for(i=1;i<=m;i++)
	{
		val = (val%MOD + (temp[i]%MOD*ans[i][m]%MOD)%MOD)%MOD;
	}
	cout<<val;

	// cout<<temp[1][m];
	return 0;
}