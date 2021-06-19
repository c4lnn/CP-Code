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
const LL MOD=1e9+7;
const int N=1505;
int tr[N][10],fail[N],sz;
bool f[N];
LL dp[N][N];
VI lim;
void insert(const string &s) {
    int u=0;
    for(auto c:s) {
        int v=c-'0';
        if(!tr[u][v]) tr[u][v]=++sz;
        u=tr[u][v];
    }
    f[u]=true;
}
void build() {
    queue<int> q;
    for(int v=0;v<10;v++) if(tr[0][v]) q.push(tr[0][v]);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int v=0;v<10;v++) {
            if(tr[u][v]) {
                fail[tr[u][v]]=tr[fail[u]][v];
                f[tr[u][v]]|=f[fail[tr[u][v]]];
                q.push(tr[u][v]);
            }
            else tr[u][v]=tr[fail[u]][v];
        }
    }
}
LL dfs(int x,int t,int a,int b) {
    if(!x) return !a;
    if(!a&&!b&&dp[x][t]!=-1) return dp[x][t];
    int mx=b?min(9,lim[x]):9;
    LL ret=0;
    for(int i=0;i<=mx;i++) if(!f[tr[t][i]]) {
        ret=(ret+dfs(x-1,a?(!i?0:tr[0][i]):tr[t][i],a&&!i,b&&i==mx))%MOD;
    }
    if(!a&&!b) dp[x][t]=ret;
    return ret;
}
LL solve(const string &s) {
    lim.PB(-1);
    for(int i=SZ(s)-1;~i;i--) {
        lim.PB(s[i]-'0');
    }
    memset(dp,-1,sizeof dp);
    return dfs(SZ(lim)-1,0,1,1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string n;int m;cin>>n>>m;
    for(int i=1;i<=m;i++) {
        string s;cin>>s;
        insert(s);
    }
    build();
    cout<<solve(n)<<'\n';
    return 0;
}