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
const LL MOD=10007;
const int N=6005;
LL dp[105][N];
LL qpow(LL a,LL b) {
    LL ret=1;
    while(b) {
        if(b&1) ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}
struct AC {
    int tr[N][26],fail[N],sz;
    bool f[N];
    void insert(const string &s) {
        int u=0;
        for(auto c:s) {
            int v=c-'A';
            if(!tr[u][v]) tr[u][v]=++sz;
            u=tr[u][v];
        }
        f[u]=true;
    }
    void build() {
        queue<int> q;
        for(int v=0;v<26;v++) if(tr[0][v]) q.push(tr[0][v]);
        while(SZ(q)) {
            int u=q.front();
            q.pop();
            for(int v=0;v<26;v++) {
                if(tr[u][v]) {
                    fail[tr[u][v]]=tr[fail[u]][v];
                    f[tr[u][v]]|=f[fail[tr[u][v]]];
                    q.push(tr[u][v]);
                }
                else tr[u][v]=tr[fail[u]][v];
            }
        }
    }
} ac;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) {
        string s;cin>>s;
        ac.insert(s);
    }
    ac.build();
    dp[0][0]=1;
    for(int i=1;i<=m;i++) {
        for(int j=0;j<=ac.sz;j++) if(!ac.f[j]) {
           for(int k=0;k<26;k++) if(!ac.f[ac.tr[j][k]]) {
                dp[i][ac.tr[j][k]]=(dp[i][ac.tr[j][k]]+dp[i-1][j])%MOD;
            }
        }
    }
    LL res=0;
    for(int i=0;i<=ac.sz;i++) res=(res+dp[m][i])%MOD;
    cout<<((qpow(26,m)-res)%MOD+MOD)%MOD<<'\n';
    return 0;
}