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
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
const int N=3e5+5;
const int LIM=20;
const LL HASH_BASE=13331;
const LL HASH_MOD[2]={1000000007,998244353};
int cnt,f[N],id[N],ed[N],fa[N][25];
LL ha[N][2],power[N][2],w[N];
VI g[N];
string t;
pair<LL,LL> tt;
int res=0;
pair<LL,LL> find(int u,int len) {
    int uu=u,l=len;
    for(int i=LIM;~i;i--) if(l>=1<<i) {
        l-=1<<i;
        uu=fa[uu][i];
    }
    if(!uu) return MP(-1,-1);
    return MP(
        ((ha[u][0]-ha[uu][0]*power[len][0]%HASH_MOD[0])%HASH_MOD[0]+HASH_MOD[0])%HASH_MOD[0],
        ((ha[u][1]-ha[uu][1]*power[len][1]%HASH_MOD[1])%HASH_MOD[1]+HASH_MOD[1])%HASH_MOD[1]
    );
}
void dfs(int u) {
    ha[u][0]=(ha[fa[u][0]][0]*HASH_BASE%HASH_MOD[0]+w[u])%HASH_MOD[0];
    ha[u][1]=(ha[fa[u][0]][1]*HASH_BASE%HASH_MOD[1]+w[u])%HASH_MOD[1];
    if(find(u,SZ(t))==tt) ++res;
    for(auto v:g[u]) if(v!=fa[u][0]) {
        fa[v][0]=u;
        for(int i=1;i<=LIM;i++) fa[v][i]=fa[fa[v][i-1]][i-1];
        dfs(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    ed[1]=++cnt;
    w[cnt]=30;
    for(int i=2;i<=n;i++) {
        string s;cin>>f[i]>>s;
        for(int j=0;j<SZ(s);j++) {
            w[++cnt]=s[j]-'a';
            if(!j) id[i]=cnt;
            else g[cnt-1].PB(cnt);
        }
        ed[i]=cnt;
    }
    for(int i=2;i<=n;i++) g[ed[f[i]]].PB(id[i]);
    power[0][0]=power[0][1]=1;
    for(int i=1;i<=cnt;i++) {
        power[i][0]=power[i-1][0]*HASH_BASE%HASH_MOD[0];
        power[i][1]=power[i-1][1]*HASH_BASE%HASH_MOD[1];
    }
    cin>>t;
    for(int i=0;i<SZ(t);i++) {
        tt.FI=(tt.FI*HASH_BASE%HASH_MOD[0]+t[i]-'a')%HASH_MOD[0];
        tt.SE=(tt.SE*HASH_BASE%HASH_MOD[1]+t[i]-'a')%HASH_MOD[1];
    }
    dfs(1);
    cout<<res<<'\n';
    return 0;
}