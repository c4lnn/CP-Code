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
const int N=1e5+5;
int f[N],in[N];
bool st[N];
VI a,b;
void topo(int n) {
    queue<int> q;
    a.clear();
    for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
    while(SZ(q)) {
        int u=q.front();
        a.PB(u);
        q.pop();
        if(--in[f[u]]==0) q.push(f[u]);
    }
}
LL sum=0;
void dfs(int u) {
    st[u]=true;
    sum+=f[u];
    b.PB(u);
    if(!st[f[u]]) dfs(f[u]);
}
void solve(int n) {
    topo(n);
    vector<pair<LL,int>> w(n+1);
    for(int i=1;i<=n;i++) st[i]=false;
    for(int i=1;i<=n;i++) if(in[i]&&!st[i]) {
        sum=0;
        b.clear();
        dfs(i);
        for(auto x:b) w[x]=MP(sum,SZ(b));
    }
    for(int i=SZ(a)-1;~i;i--) w[a[i]]=w[f[a[i]]];
    for(int i=2;i<=n;i++) if(w[1].FI*w[i].SE!=w[i].FI*w[1].SE) {
        cout<<"NO"<<'\n';
        return;
    }
    cout<<"YES"<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        for(int i=1;i<=n;i++) in[i]=0;
        for(int i=1;i<=n;i++) cin>>f[i],++in[f[i]];
        solve(n);
    }
    return 0;
}