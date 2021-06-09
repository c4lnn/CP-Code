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
const int N=5e5+5;
int n,m,a[N],ls[N<<2],rs[N<<2],w[N<<2];
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {w[p]=a[l]-m;return;}
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    w[p]=max(w[p<<1],w[p<<1|1]);
}
int query(int p,int l,int r,int k) {
    if(l==r) return l;
    int mid=l+r>>1;
    if(w[p<<1|1]>=k) return query(p<<1|1,mid+1,r,k);
    if(w[p<<1]>=k) return query(p<<1,l,mid,k);
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for(int i=1;i<n;i++) {
        int ret=query(1,1,n,a[i]);
        if(ret==-1||ret<=i) cout<<-1<<' ';
        else cout<<ret-i-1<<' ';
    }
    cout<<-1<<'\n';
    return 0;
}