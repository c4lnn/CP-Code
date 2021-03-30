#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

const int N=105;

int n,m;
int a[N][N];
int d[N][N];
int pos[N][N];
vector<int>path;
long long res;

void get_path(int i,int j) {
	if(!pos[i][j]) return;
	get_path(i,pos[i][j]);
	path.push_back(pos[i][j]);
	get_path(pos[i][j],j);
}
void floyd() {
	res=0x3f3f3f3f;
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				if(res>(long long)d[i][j]+a[i][k]+a[k][j]) {
					res=d[i][j]+a[i][k]+a[k][j];
					path.clear();
					path.push_back(i);
					get_path(i,j);
					path.push_back(j);
					path.push_back(k);
				}
			}
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(d[i][j]>d[i][k]+d[k][j]) {
					d[i][j]=d[i][k]+d[k][j];
					pos[i][j]=k;
				}
			}
		}
	}
}
int main() {
	memset(a,0x3f,sizeof a);
	memset(d,0x3f,sizeof d);
	cin>>n>>m;
	for(int i=1;i<=m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=min(a[u][v],w);
	}
	memcpy(d,a,sizeof a);
	floyd();
	if(res==0x3f3f3f3f) cout<<"No solution.";
	else for(int i=0;i<path.size();i++) cout<<path[i]<<" ";
	cout<<endl;
 	return 0;
}