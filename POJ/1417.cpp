#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=605;
int n,p,q,fa[N],w[N],dp[N][N],pre[N][N];
bool st[N];
VI v[N][2];
int find(int x) {
	if(x==fa[x]) return x;
	int root=find(fa[x]);
	w[x]^=w[fa[x]];
	return fa[x]=root;
}
int main() {
    while(~scanf("%d%d%d",&n,&p,&q)) {
    	if(n==0&&p==0&&q==0) break;
    	for(int i=1;i<=p+q;i++) {
    		fa[i]=i;
    		w[i]=0;
	    }
	    for(int i=1;i<=n;i++) {
	    	int x,y;
	    	char s[5];
	    	scanf("%d%d%s",&x,&y,s);
	    	int tx=find(x),ty=find(y);
	    	int temp=s[0]=='y'?0:1;
	    	if(tx!=ty) {
	    		fa[tx]=ty;
	    		w[tx]=(w[y]+w[x]+temp)&1;
	    	}
	    }
	    int cnt=0;
	    memset(st,false,sizeof st);
	    for(int i=1;i<=p+q;i++) {
	    	if(st[i]) continue;
	    	int root=find(i);
	    	++cnt;
	    	for(int j=i;j<=p+q;j++) {
	    		if(!st[j]&&find(j)==root) {
	    			v[cnt][w[j]].PB(j);
	    			st[j]=true;
	    		}
	    	}
	    }
		memset(dp,0,sizeof dp);
		dp[0][0]=1;
		for(int i=1;i<=cnt;i++) {
			for(int j=p;j>=0;j--) {
				if(j-SZ(v[i][0])>=0&&dp[i-1][j-SZ(v[i][0])]) {
					dp[i][j]+=dp[i-1][j-SZ(v[i][0])];
					pre[i][j]=j-SZ(v[i][0]);
				}
				if(j-SZ(v[i][1])>=0&&dp[i-1][j-SZ(v[i][1])]) {
					dp[i][j]+=dp[i-1][j-SZ(v[i][1])];
					pre[i][j]=j-SZ(v[i][1]);
				}
			}
		}
		if(dp[cnt][p]!=1) {
			puts("no");
		} else {
			VI res;
			for(int i=cnt,j=p;i>=1;j=pre[i][j],i--) {
				if(j-pre[i][j]==SZ(v[i][0])) {
					for(int k=0;k<SZ(v[i][0]);k++) {
						res.PB(v[i][0][k]);
					}
				} else {
					for(int k=0;k<SZ(v[i][1]);k++) {
						res.PB(v[i][1][k]);
					}
				}
			}
			sort(ALL(res));
			for(int i=0;i<SZ(res);i++) {
				printf("%d\n",res[i]);
			}
			puts("end");
		}
		for(int i=1;i<=cnt;i++) {
			v[i][0].clear();
			v[i][1].clear();
		}
	}
    return 0;
    
}
/*
2 1 1
1 2 no
2 1 no
3 2 1
1 1 yes
2 2 yes
3 3 yes
2 2 1
1 2 yes
2 3 no
5 4 3
1 2 yes
1 3 no
4 5 yes
5 6 yes
6 7 no
0 0 0
*/