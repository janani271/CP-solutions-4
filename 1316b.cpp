#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 100003

ll MOD=1e9+7;
ll t , n ,i , cost;
string s , smin , fh , sh , r; 
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>s;
		smin=s;
		cost=1;
		for(i=1;i<n-1;i++)
		{
			fh = s.substr(i,n-i);
			sh = s.substr(0,i);
			if((i%2==0 && n%2!=0) || (i%2==1 && n%2!=1))
				reverse(sh.begin(),sh.end());
			// cout<<"fh : "<<fh<<"\tsh : "<<sh<<"\n";
			r = fh.append(sh);
			if(r<smin)
			{
				smin = r;
				cost = i+1;
			}
			// cout<<"r : "<<r<<"\nsmin : "<<smin<<"\ncost : "<<cost<<"\n";
		}
		reverse(s.begin(),s.end());
		if(s<smin)
		{
			smin = s;
			cost = n;
		}
		cout<<smin<<"\n"<<cost<<"\n";
	}
	return 0;
}