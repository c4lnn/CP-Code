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
const int MOD=1e9+7;
const int N=105;
int m,n,tr[201][2],fail[201],st[201],sz,dp[101][101][201][4];
void init() {
    for(int i=0;i<=sz;i++) {
        tr[i][0]=tr[i][1]=fail[i]=st[i]=0;
    }
    sz=0;
}
void insert(const string &s,int i) {
    int u=0;
    for(auto c:s) {
        int v=c=='D';
        if(!tr[u][v]) tr[u][v]=++sz;
        u=tr[u][v];
    }
    st[u]|=1<<i;
}
void build() {
    queue<int> q;
    for(int i=0;i<2;i++) if(tr[0][i]) q.push(tr[0][i]);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int v=0;v<2;v++) {
            if(tr[u][v]) fail[tr[u][v]]=tr[fail[u]][v],q.push(tr[u][v]);
            else tr[u][v]=tr[fail[u]][v];
        }
        st[u]|=st[fail[u]];
    }
}
void solve() {
    build();
    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) {
            for(int k=0;k<=sz;k++) {
                for(int b=0;b<4;b++) {
                    dp[i][j][k][b]=0;
                }
            }
        }
    }
    dp[0][0][0][0]=1;
    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) {
            for(int u=0;u<=sz;u++) {
                for(int b=0;b<4;b++) {
                    for(int v=0;v<2;v++) {
                        if(v==0&&i+1<=m) dp[i+1][j][tr[u][v]][b|st[tr[u][v]]]=(dp[i+1][j][tr[u][v]][b|st[tr[u][v]]]+dp[i][j][u][b])%MOD;
                        else if(v==1&&j+1<=n) dp[i][j+1][tr[u][v]][b|st[tr[u][v]]]=(dp[i][j+1][tr[u][v]][b|st[tr[u][v]]]+dp[i][j][u][b])%MOD;
                    }
                }
            }
        }
    }
    LL res=0;
    for(int i=0;i<=sz;i++) res=(res+dp[m][n][i][3])%MOD;
    cout<<res<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        cin>>m>>n;
        init();
        string s;
        cin>>s;insert(s,0);
        cin>>s;insert(s,1);
        solve();
    }
    return 0;
}