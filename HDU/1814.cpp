#include <bits/stdc++.h>
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
const int N=16005;
int n,m,top,stk[N];
bool st[N];
VI G[N];
bool dfs(int u) {
    st[u]=true;
    stk[++top]=u;
    for(auto v:G[u]) {
        if(st[v^1]) return false;
        if(st[v]) continue;
        if(!dfs(v)) return false;
    }
    return true;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        for(int i=0;i<n*2;i++) G[i].clear(),st[i]=false;
        for(int i=1;i<=m;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            u--,v--;
            G[u].PB(v^1);
            G[v].PB(u^1);
        }
        bool f=false;
        for(int i=0;i<n*2;i+=2) {
            if(st[i]||st[i^1]) continue;
            top=0;
            if(!dfs(i)) {
                while(top) st[stk[top--]]=false;
                if(!dfs(i^1)) {f=true;break;}
            }
        }
        if(f) puts("NIE");
        else for(int i=0;i<n*2;i++) if(st[i]) printf("%d\n",i+1);
    }
    return 0;
}