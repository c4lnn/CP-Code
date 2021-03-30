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
const int N=1105;
string s[101],path[55][N];
int n,m,tr[N][26],fail[N],val[N],cnt,dp[55][N];
void init()  {
    for(int i=0;i<=cnt;i++) {
        for(int j=0;j<26;j++) tr[i][j]=0;
        fail[i]=val[i]=0;
    }
    cnt=0;
}
void insert(const string &s,int x) {
    int u=0;
    for(auto c:s) {
        int v=c-'a';
        if(!tr[u][v]) tr[u][v]=++cnt;
        u=tr[u][v];
    }
    val[u]=x;
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
        val[u]+=val[fail[u]];
    }
}
void solve() {
    memset(dp,0xc0,sizeof dp);
    dp[0][0]=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=cnt;j++) {
            for(int k=0;k<26;k++) {
                if(dp[i][j]+val[tr[j][k]]>dp[i+1][tr[j][k]]) {
                    dp[i+1][tr[j][k]]=dp[i][j]+val[tr[j][k]];
                    path[i+1][tr[j][k]]=path[i][j]+(char)('a'+k);
                }
                else if(dp[i][j]+val[tr[j][k]]==dp[i+1][tr[j][k]])
                    path[i+1][tr[j][k]]=min(path[i+1][tr[j][k]],path[i][j]+(char)('a'+k));
            }
        }
    }
    int x=0,y=0;
    for(int i=1;i<=n;i++) for(int j=0;j<=cnt;j++) {
        if(dp[i][j]>dp[x][y]) x=i,y=j;
        else if(dp[i][j]==dp[x][y]&&path[i][j]<path[x][y]) x=i,y=j;
    }
    cout<<path[x][y]<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        init();
        for(int i=1;i<=m;i++) cin>>s[i];
        for(int i=1;i<=m;i++) {
            int x;
            cin>>x;
            insert(s[i],x);
        }
        build();
        solve();
    }
    return 0;
}