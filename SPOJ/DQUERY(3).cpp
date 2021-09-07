// 莫队
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
int n,m,unit,ans,a[30005],cnt[1000005],res[200005];
struct Q {
    int l,r,id;
    Q() {}
    Q(int l,int r,int id):l(l),r(r),id(id) {}
    bool operator < (const Q &T) const {
        if(l/unit!=T.l/unit) return l<T.l;
        if((l/unit)&1) return r>T.r;
        return r<T.r;
    }
} q[200005];
void move(int x,int v) {
    cnt[a[x]]+=v;
    if(v==-1&&cnt[a[x]]==0) --ans;
    if(v==1&&cnt[a[x]]==1) ++ans;
}
void mo() {
    unit=int(ceil(n/pow(n,0.5)));
    sort(q,q+m);
    int l=0,r=-1;
    for(int i=0;i<m;i++) {
        while(l>q[i].l) move(--l,1);
        while(r<q[i].r) move(++r,1);
        while(l<q[i].l) move(l++,-1);
        while(r>q[i].r) move(r--,-1);
        res[q[i].id]=ans;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>m;
    for(int i=0;i<m;i++) {
        cin>>q[i].l>>q[i].r;
        --q[i].l,--q[i].r;
        q[i].id=i;
    }
    mo();
    for(int i=0;i<m;i++) cout<<res[i]<<'\n';
    return 0;
}