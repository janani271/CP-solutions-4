#include<bits/stdc++.h>
using namespace std;

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

ll MAX = 10000003;

ll prime[10000005] , a , n , i , fp[10000007] , q , l , r , temp;

void sieve()
{	
	for(i=2;i<MAX;i++)
	{
		if(i%2!=0)
			prime[i] = i;
		else 
		prime[i] = 2;
	}

	// for(i=2;i<MAX;i+=2)
	// 	prime[i] = 2;

	for(i=3;i*i<MAX;i++)
	{
		if(prime[i]==i)
		{
			// ll x = 2*i ,start = i*i;
			for(ll j=i*i;j<MAX;j+=i)
				// if(prime[j]==j)
				prime[j] = i;
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	fastread;

	sieve();

	cin>>n;
	
	for(i=0;i<n;i++)
	{
		cin>>a;
		temp = a;
		while(temp>1)
		{
			ll de = prime[temp];
			fp[de]++;
			while(temp%de==0)
				temp = temp/de;
		}
	}

	for(i=1;i<=MAX-3;i++)
	{
		fp[i] = fp[i-1] + fp[i];
	}

	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>l>>r;
		l = min(l,MAX-3);
		r = min(r,MAX-3);
		cout<<fp[r]-fp[l-1]<<"\n";
	}


	return 0;
}