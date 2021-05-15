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
const int N=1005;
int id[20],tr[N][4],st[N],fail[N],sz,dp[N][N];
void init() {
    for(int i=0;i<=sz;i++) for(int j=0;j<4;j++) tr[i][j]=0;
    for(int i=0;i<=sz;i++) fail[i]=st[i]=0;
    sz=0;
}
void insert(const string &s) {
    int u=0;
    for(auto c:s) {
        int v=id[c-'A'];
        if(!tr[u][v]) tr[u][v]=++sz;
        u=tr[u][v];
    }
    st[u]=1;
}
void build() {
    queue<int> q;
    for(int i=0;i<4;i++) if(tr[0][i]) q.push(tr[0][i]);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            if(tr[u][i]) fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
            else tr[u][i]=tr[fail[u]][i];
        }
        st[u]|=st[fail[u]];
    }
}
void solve(const string &s) {
    for(int i=0;i<=SZ(s);i++) for(int j=0;j<=sz;j++) dp[i][j]=0x3f3f3f3f;
    dp[0][0]=0;
    for(int i=0;i<SZ(s);i++) {
        for(int j=0;j<=sz;j++) if(!st[j]) {
            for(int k=0;k<4;k++) if(!st[tr[j][k]]) {
                dp[i+1][tr[j][k]]=min(dp[i+1][tr[j][k]],dp[i][j]+(id[s[i]-'A']!=k));
            }
        }
    }
    int mn=0x3f3f3f3f;
    for(int i=0;i<=sz;i++) mn=min(mn,dp[SZ(s)][i]);
    cout<<(mn==0x3f3f3f3f?-1:mn)<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    id[0]=0,id[2]=1,id[6]=2,id[19]=3;
    int n,cs=0;
    while(cin>>n) {
        if(!n) break;
        init();
        string s;
        for(int i=1;i<=n;i++) {
            cin>>s;
            insert(s);
        }
        build();
        cin>>s;
        cout<<"Case "<<++cs<<": ";
        solve(s);
    }
    return 0;
}