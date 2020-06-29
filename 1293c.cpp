#include<bits/stdc++.h>
using namespace std;
long long n , q , cnt , visited[3][100009] , i , row, r, c;
int main()
{
	cin>>n>>q;
	cnt=0;
	memset(visited,0,sizeof visited);
	for(i=0;i<q;i++)
	{
		cin>>r>>c;
		row = (r%2)+1;
		if(!visited[r][c])
		{     
			//cout<<"row: "<<row<<" c: "<<c-1<<"\n"<<" visited : "<<visited[row][c-1]<<"\n";
			if(c>1 && visited[row][c-1])
			{
				cnt++;
				//cout<<"jj";
			}
			if(visited[row][c])
				cnt++;
			if(c<n && visited[row][c+1])
				cnt++;
			visited[r][c] = 1;
		}
		//cout<<"visited : "<<visited[r][c];
		else if(visited[r][c])
		{
			if(c>1 && visited[row][c-1])
				cnt--;
			if(visited[row][c])
				cnt--;
			if(c<n && visited[row][c+1])
				cnt--;
			visited[r][c] = 0;
		}
		if(cnt==0)
			cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}