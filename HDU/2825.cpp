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
const LL MOD=20090717;
const int N=105;
int n,m,t,tr[N][26],fail[N],bit[N],popcount[1<<10],cnt;
LL dp[26][N][1<<10];
void init() {
    for(int i=0;i<=cnt;i++) for(int j=0;j<26;j++) tr[i][j]=0;
    for(int i=0;i<=cnt;i++) fail[i]=bit[i]=0;
    cnt=0;
}
void insert(const string &s,int i) {
    int u=0;
    for(auto c:s) {
        int v=c-'a';
        if(!tr[u][v]) tr[u][v]=++cnt;
        u=tr[u][v];
    }
    bit[u]=1<<i;
}
void build() {
    queue<int> q;
    for(int i=0;i<26;i++) if(tr[0][i]) q.push(tr[0][i]);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int v=0;v<26;v++) {
            if(tr[u][v]) fail[tr[u][v]]=tr[fail[u]][v],q.push(tr[u][v]);
            else tr[u][v]=tr[fail[u]][v];
        }
        bit[u]+=bit[fail[u]];
    }
}
LL solve() {
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=cnt;j++) {
            for(int k=0;k<1<<m;k++) if(dp[i][j][k]) {
                dp[i][j][k]=0;
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<=cnt;j++) {
            for(int k=0;k<1<<m;k++) if(dp[i][j][k]) {
                for(int l=0;l<26;l++) {
                    dp[i+1][tr[j][l]][k|bit[tr[j][l]]]=(dp[i+1][tr[j][l]][k|bit[tr[j][l]]]+dp[i][j][k])%MOD;
                }
            }
        }
    }
    LL res=0;
    for(int i=0;i<1<<m;i++) if(popcount[i]>=t) {
        for(int j=0;j<=cnt;j++) if(dp[n][j][i]) {
            res=(res+dp[n][j][i])%MOD;
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<1<<10;i++) popcount[i]=__builtin_popcount(i);
    while(cin>>n>>m>>t) {
        if(!n&&!m&&!t) break;
        init();
        for(int i=0;i<m;i++) {
            string s;
            cin>>s;
            insert(s,i);
        }
        build();
        cout<<solve()<<'\n';
    }
    return 0;
}