#include<bits/stdc++.h>
using namespace std;
long long q , x , cnt[400009], mex, i , y;
int main()
{
	cin>>q>>x;
	mex=0;
	for(i=0;i<q;i++)
	{
		cin>>y;
		cnt[y%x]++;
		while(cnt[mex%x]!=0)
		{
			cnt[mex%x]--;
			mex++;
		}
		cout<<mex<<"\n";
	}
	return 0;
}