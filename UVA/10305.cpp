#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=105;
int edge[maxn][maxn];
int v[maxn];
int n,m;
vector<int>ans;
bool dfs(int x){
	v[x]=-1;
	for(int i=1;i<=n;i++)
		if(edge[x][i])
			if(v[i]==-1) return false;
			else if(!v[i]&&!dfs(i)) return false;
	v[x]=1;
	ans.push_back(x);		
	return true;
}
int main(){
 	int a,b;
 	while(cin>>n>>m&&n){	
	 	memset(edge,0,sizeof(edge));
	 	memset(v,0,sizeof(v));
	 	ans.clear();
		int flag=0;	
	 	for(int i=0;i<m;i++){
	 		cin>>a>>b;
	 		if(!edge[a][b])	edge[a][b]=1;
		}
		for(int i=1;i<=n;i++)
			if(!v[i])
				if(!dfs(i)){
					flag=1;
					break;
				}
		for(int i=ans.size()-1;i>=0;i--)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}