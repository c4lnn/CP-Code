#include<iostream>
#include<vector>
#include<cstring>
#include <algorithm>
using namespace std;
int maxn;
int m[45][2000];
bool v[2000];
vector<int>ans;
void dfs(int n)
{
	for(int i=1;i<=maxn;i++)
		if(m[n][i]&&!v[i])
		{
			v[i]=true;
			dfs(m[n][i]);
			ans.push_back(i);
		}
}
int main()
{
	int x,y,z;
	int start;
	while(cin>>x>>y&&x&&y)
	{
		start=min(x,y);
		ans.clear();
		memset(m,0,sizeof(m));
		memset(v,false,sizeof(v));
		bool ind[45]={0};
		maxn=0;
		while(x&&y)
		{
			cin>>z;
			m[x][z]=y;
			m[y][z]=x;
			ind[x]=!ind[x];
			ind[y]=!ind[y];
			maxn=max(maxn,z);		
			cin>>x>>y;
		}
		int f=1;
		for(;f<45;f++)
			if(ind[f])
				break;
		if(f<45)
			cout<<"Round trip does not exist."<<endl;
		else
		{
			dfs(start);
			for(int i=ans.size()-1;i>=0;i--)
				cout<<ans[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}