#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1505;
int n,m,match[N];
bool st[N];
VI g[N];
bool dfs(int u) {
    for(auto v:g[u]) {
        if(st[v]) continue;
        st[v]=true;
        if(match[v]==-1||dfs(match[v])) {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    while(~scanf("%d",&n)) {
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=n;i++) {
            int u,t;
            scanf("%d:(%d)",&u,&t);
            ++u;
            for(int j=1;j<=t;j++) {
                int v;
                scanf("%d",&v);
                ++v;
                g[u].PB(v);
                g[v].PB(u);
            }
        }
        int res=0;
        for(int i=1;i<=n;i++) match[i]=-1;
        for(int i=1;i<=n;i++) {
            if(match[i]!=-1) continue;
            for(int j=1;j<=n;j++) st[j]=false;
            res+=dfs(i);
        }
        printf("%d\n",res);
    }
    return 0;
}