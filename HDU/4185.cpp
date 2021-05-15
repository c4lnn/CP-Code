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
const int N=605;
int n,match[N*N];
bool st[N*N];
char s[N][N];
VI g[N*N];
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
    int T;
    scanf("%d",&T);
    for(int cs=1;cs<=T;cs++) {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                g[i*n+j].clear();
        for(int i=0;i<n;i++) scanf("%s",s[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) {
                if(s[i][j]=='.') continue;
                if(j+1<n&&s[i][j+1]=='#') {
                    g[i*n+j].PB(i*n+j+1);
                    g[i*n+j+1].PB(i*n+j);
                }
                if(i+1<n&&s[i+1][j]=='#') {
                    g[i*n+j].PB((i+1)*n+j);
                    g[(i+1)*n+j].PB(i*n+j);
                }
            }
        int res=0;
        for(int i=0;i<n*n;i++) match[i]=-1;
        for(int i=0;i<n*n;i++) {
            if(match[i]!=-1) continue;
            for(int j=0;j<n*n;j++) st[j]=false;
            if(dfs(i)) res++;
        }
        printf("Case %d: %d\n",cs,res);
    }
    return 0;
}