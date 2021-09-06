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
int n,a[30005],b[30005],pre[1000005],res[200005];
VPII q[200005];
void update(int x,int v) {
    for(int i=x;i<=n;i+=i&-i) b[i]+=v;
}
int query(int l,int r) {
    int ret=0;;
    for(int i=r;i;i-=i&-i) ret+=b[i];
    for(int i=l-1;i;i-=i&-i) ret-=b[i];
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int m;cin>>m;
    for(int i=1;i<=m;i++) {
        int l,r;cin>>l>>r;
        q[r].EB(l,i);
    }
    for(int i=1;i<=n;i++) {
        if(pre[a[i]]) update(pre[a[i]],-1);
        update(i,1);
        pre[a[i]]=i;
        for(auto x:q[i]) res[x.SE]=query(x.FI,i);
    }
    for(int i=1;i<=m;i++) cout<<res[i]<<'\n';
    return 0;
}