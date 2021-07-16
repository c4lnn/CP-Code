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
const int N=2e5+5;
int n,L,R,a[N],fa[N],tot[N];
bool st[N];
ULL seed;
struct E {
    int u,v,w;
    E() {}
    E(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator < (const E &T) const {
        return w<T.w;
    }
};
vector<E> e;
ULL xorshift64() {
    ULL x=seed;
    x^=x<<13;
    x^=x>>7;
    x^=x<<17;
    return seed=x;
}
int gen() {
    return xorshift64()%(R-L+1)+L;
}
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>L>>R>>seed;
    for(int i=1;i<=n;i++) a[i]=gen();
    if(L==R) cout<<1ll*(n-1)*L<<'\n';
    else if(n<=1000) {
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                e.EB(i,j,__gcd(a[i],a[j]));
            }
        }
        sort(ALL(e));
        LL res=0;
        for(int i=1;i<=n;i++) fa[i]=i;
        for(auto x:e) {
            int fx=find(x.u),fy=find(x.v);
            if(fx==fy) continue;
            fa[fx]=fy;
            res+=x.w;
        }
        cout<<res<<'\n';
    }
    else if(R-L+1<=1000) {
        for(int i=1;i<=n;i++) ++tot[a[i]];
        for(int i=L;i<=R;i++) if(tot[i]) {
            for(int j=i;j<=R;j++) if(tot[j]) {
                e.EB(i,j,__gcd(i,j));
            }
        }
        sort(ALL(e));
        LL res=0;
        for(int i=L;i<=R;i++) fa[i]=i;
        for(auto x:e) {
            int fu=find(x.u),fv=find(x.v);
            if(!st[fu]) res+=1ll*(tot[x.u]-1)*x.w,st[fu]=true;
            if(!st[fv]) res+=1ll*(tot[x.v]-1)*x.w,st[fv]=true;
            if(fu==fv) continue;
            fa[fu]=fv;
            res+=x.w;
        }
        cout<<res<<'\n';
    }
    else cout<<n-1<<'\n';
    return 0;
}