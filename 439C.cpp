#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n , k , p , a , o , e , op , j , i , pos1 , pos2 , ans , ep;
vector<ll>even,odd;

int main()
{
	cin>>n>>k>>p;
	for(i=0;i<n;i++)
	{
		cin>>a;
		if(a&1)
		{
			o++;
			odd.push_back(a);
		}
		else
		{
			e++;
			even.push_back(a);
		}
	}

	op = k-p;
	if(o<op || (o-op)%2!=0 || (e<p && (o-op)<(p-e)*2))
	{
		cout<<"NO";
		return 0;
	}

	cout<<"YES\n";

	i = 0; ep=0;
	for(i=0;i<op-1;i++)
	{
		cout<<"1 "<<odd[i]<<"\n";
	}

	for(j=0;j<p-1;j++)
	{
		if(j<e)
			cout<<"1 "<<even[ep++]<<"\n";
		else
			cout<<"2 "<<odd[i++]<<" "<<odd[i++]<<"\n";
	}

	if(p!=0 && op!=0)
		cout<<"1 "<<odd[i++]<<"\n";

	cout<<o-i+e-ep<<" ";
	while(j<e)
		cout<<even[j++]<<" ";
	while(i<o)
		cout<<odd[i++]<<" ";






	// i = 0; j = 0;
	// while(i<p && j<e-1)
	// {
	// 	cout<<"1 "<<even[j]<<"\n";
	// 	i++; j++;
	// }

	// pos1 = i; //pos1==p ah nu check
	// pos2 = j; //pos2==e ah nu check

	// j = 0;
	// if(pos1<p) //even segments left but even numbers over
	// {
	// 	while(pos1<p)
	// 	{
	// 		cout<<"2 "<<odd[j]<<" "<<odd[j+1]<<"\n";
	// 		j+=2;
	// 		pos1++;
	// 	}
	// } 
	// i = 0;
	// while(i<op-1 && j<o)
	// {
	// 	cout<<"1 "<<odd[j]<<"\n";
	// 	i++; j++;
	// }

	// ans = e-pos2+o-j;
	// if(ans>0)
	// {
	// 	cout<<ans<<" ";
	// 	while(pos2<e)
	// 	{
	// 		cout<<even[pos2]<<" ";
	// 		pos2++;
	// 	}
	// 	while(j<o)
	// 	{
	// 		cout<<odd[j]<<" ";
	// 		j++;
	// 	}
	// }
	return 0;
}