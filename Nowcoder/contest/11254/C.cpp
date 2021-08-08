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
const int N=1e6+5;
VI mx1[N],mx2[N],a,b;
int match[505];
bool w[2005][2005],st[505];
bool dfs(int u) {
    for(int v=0;v<SZ(b);v++) if(w[a[u]][b[v]]&&!st[v]) {
        st[v]=true;
        if(match[v]==-1||dfs(match[v])) {
            match[v]=u;
            return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        mx1[x].PB(i);
    }
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        mx2[x].PB(i);
    }
    for(int i=1;i<=m;i++) {
        int x,y;cin>>x>>y;
        w[x][y]=true;
    }
    int res=0;
    for(int i=k;i;i--) {
        a.clear();
        b.clear();
        for(auto x:mx1[i]) a.PB(x);
        for(auto x:mx2[i]) b.PB(x);
        for(int i=0;i<SZ(b);i++) match[i]=-1;
        int cnt=SZ(a)+SZ(b);
        for(int i=0;i<SZ(a);i++) {
            for(int j=0;j<SZ(b);j++) st[j]=false;
            if(dfs(i)) --cnt;
        }
        res+=cnt*i;
    }
    cout<<res<<'\n';
    return 0;
}