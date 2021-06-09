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
int n,m,a[N],b[N],c[N],res[N];
VI pos[2][N];
struct O {
    int l,r,id;
    bool operator < (const O &T) const {
        return l<T.l||l==T.l&&r<T.r;
    }
}o[N];
int lowbit(int x) {
    return x&-x;
}
void update(int x,int v) {
    for(int i=x;i<=n;i+=lowbit(i)) c[i]+=v;
}
int query(int x) {
    int ret=0;
    for(int i=x;i>=1;i-=lowbit(i)) ret+=c[i];
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        b[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
        for(int j=a[i]*2;j<=n;j+=a[i])
            if(b[j]>i) pos[0][i].PB(b[j]);
            else pos[1][b[j]].PB(i);
    for(int i=1;i<=n;i++)
        for(int j=a[i]*2;j<=n;j+=a[i])
            if(b[j]>i) update(b[j],1);
            else update(i,1);
    for(int i=1;i<=m;i++) {
        cin>>o[i].l>>o[i].r;
        o[i].id=i;
    }
    sort(o+1,o+1+m);
    int l=1;
    for(int i=1;i<=m;i++) {
        while(l<o[i].l) {
            for(auto x:pos[0][l]) update(x,-1);
            for(auto x:pos[1][l]) update(x,-1);
            ++l;
        }
        res[o[i].id]=query(o[i].r);
    }
    for(int i=1;i<=m;i++) cout<<res[i]<<'\n';
    return 0;
}