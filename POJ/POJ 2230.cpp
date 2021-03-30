#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<functional>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
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
const int N=1e4+5;
const int M=5e4+5;
int n,m,cnt,nxt[M<<1],to[M<<1],head[N],top,stack[M<<1],ans[M<<1],t;
bool st[M<<1];
void addedge(int u,int v) {
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
}
void euler(int s) {
	stack[++top]=s;
	while(top) {
		int u=stack[top],i=head[u];
		while(i&&st[i]) i=nxt[i];
		if(i) {
			stack[++top]=to[i];
			st[i]=true;
			head[u]=nxt[i];
		}
		else top--,ans[++t]=u;
	}
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
    	int u,v;
    	scanf("%d%d",&u,&v);
    	addedge(u,v);
    	addedge(v,u);
    }
    euler(1);
    for(int i=t;i;i--) printf("%d\n",ans[i]);
    return 0;
}