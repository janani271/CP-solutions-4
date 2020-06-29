#include<bits/stdc++.h>
using namespace std;

int a[150] , i , n , o , e , dp[102][102][102][3];
int calc(int pos, int even, int odd, int pre)
{
	if(pos==n)
		return 0;
	int ca = 100000;
	int cb = 100000;
	if(a[pos]==-1)
	{
		if(dp[pos][even][odd][pre]!=-1)
			return dp[pos][even][odd][pre];
		if(even!=0)
		{
			ca = min(ca,calc(pos+1,even-1,odd,0)) + abs(0-pre); 
		}
		if(odd!=0)
		{
			cb = min(cb,calc(pos+1,even,odd-1,1)) + abs(1-pre);
		}
	}
	else
	{
		ca = min(ca,calc(pos+1,even,odd,a[pos])) + abs(pre-a[pos]);
	}
	dp[pos][even][odd][pre] = min(ca,cb);
	return min(ca,cb);
}

int main()
{
	cin>>n;
	e = (n/2);
	o = (n/2) + (n%2);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			a[i]=-1;
		}
		else
		{
			if(a[i]%2==1)
				o--; //odd count
			else e--;//even count
			a[i] = a[i]%2;
		}
	}
	memset(dp,-1,sizeof(dp));
	cout<<min(calc(0,e,o,0),calc(0,e,o,1));
	return 0;
}