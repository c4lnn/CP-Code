#include<iostream>
#include<cstring>

using namespace std;

const int N=30;

int n,m;
int d[N][N];
bool vis[N][N];
int u[1000000],v[1000000];
int deg[N];
char res[N];
bool flag,st;
int cnt;

void init() {
	memset(d,0,sizeof d);
	memset(deg,0,sizeof deg);
	memset(vis,false,sizeof vis);
	flag=false;
	st=false;
	cnt=0;
}
int floyd() {	
	for(int k=0;k<n;k++) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				d[i][j]|=d[i][k]&d[k][j];
				if(i!=j&&d[i][j]+d[j][i]==2) {
					flag=true;
					break;
				}
				else if(i!=j&&d[i][j]&&!vis[i][j]) cnt++,vis[i][j]=true;
			}
		}
	}
	if(flag) return -1;
	if(cnt==(n-1)*n/2) return 1;
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>m&&n&&m) {
		init();
		for(int i=1;i<=m;i++) {
			string s;
			cin>>s;
			if(!st) {
				d[s[0]-'A'][s[2]-'A']=1;
				int t=floyd();
				if(t==-1) {
					cout<<"Inconsistency found after "<<i<<" relations.\n";
					st=true;
				}		
				else if(t==1){
					cout<<"Sorted sequence determined after "<<i<<" relations: ";
					for(int i=0;i<n;i++) {
						for(int j=0;j<n;j++) {
							if(i!=j) {
								if(d[i][j]) deg[j]++;
							}
						}
					}
					for(int i=0;i<n;i++) res[deg[i]]=i+'A';
					for(int i=0;i<n;i++) cout<<res[i];
					cout<<".\n";
					st=true;
				}
			}	
		}
		if(st==false) cout<<"Sorted sequence cannot be determined.\n";
	}
	return 0;
}