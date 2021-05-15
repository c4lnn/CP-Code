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
const int N=55;
const int dir[4][2]={0,-1,0,1,-1,0,1,0};
int n,m,fa[N*N],dist[N][N],cnt;
char a[N][N];
map<PII,int> mp;
struct E {
	int u,v,w;
	E() {}
	E(int u,int v,int w):u(u),v(v),w(w) {}
	bool operator < (const E &a) const {
		return w<a.w;
	}
};
vector<E> e;
int find(int x) {
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool valid(int x,int y) {
	if(x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!='#') return true;
	return false;
}
void bfs(PII s) {
	queue<PII> q;
	q.push(s);
	memset(dist,-1,sizeof dist);
	dist[s.FI][s.SE]=0;
	while(!q.empty()) {
		PII u=q.front();
		q.pop();
		for(int i=0;i<4;i++) {
			int dx=u.FI+dir[i][0],dy=u.SE+dir[i][1];
			if(valid(dx,dy)&&dist[dx][dy]==-1) {
				dist[dx][dy]=dist[u.FI][u.SE]+1;
				if(a[dx][dy]=='A') e.PB(E(mp[s],mp[MP(dx,dy)],dist[dx][dy]));
				q.push(MP(dx,dy));
			}
		}
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&m,&n);
		int s;
		cnt=0;
		mp.clear();
		gets(a[0]);
		for(int i=1;i<=n;i++) {
			gets(a[i]);
			for(int j=1;j<=m;j++) {
				if(a[i][j]=='A'||a[i][j]=='S') mp[MP(i,j)]=++cnt;
				if(a[i][j]=='S') s=mp[MP(i,j)];
			}
		}
		for(int i=1;i<=cnt;i++) fa[i]=i;
		e.clear();
		for(map<PII,int>::iterator it=mp.begin();it!=mp.end();it++) bfs(it->FI);
		sort(ALL(e));
		int res=0;
		for(int i=0;i<SZ(e);i++) {
			int tx=find(e[i].u),ty=find(e[i].v);
			if(tx==ty) continue;
			fa[tx]=ty;
			res+=e[i].w;
		}
		printf("%d\n",res);
	}
    return 0;
}