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
const int N=5005;
int n,q,fa[N],sz[N];
LL tot[N];
map<string,int> mp;
struct E {
    int u,v,w;
    E() {}
    E(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator < (const E &T) const {
        return w<T.w;
    }
};
vector<E> e;
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int merge(int x,int y,int w) {
    int tx=find(x),ty=find(y);
    if(tx==ty) return false;
    fa[tx]=ty;
    tot[ty]+=tot[tx]+w;
    sz[ty]+=sz[tx];
    if(sz[ty]==n) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n>>q) {
        mp.clear();
        e.clear();
        for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1,tot[i]=0;
        int cnt=0;
        string s;
        cin>>s;
        mp[s]=++cnt;
        for(int i=1;i<=q;i++) {
            string a,b;
            int w;
            cin>>a>>b>>w;
            if(!mp.count(a)) mp[a]=++cnt;
            if(!mp.count(b)) mp[b]=++cnt;
            int u=mp[a],v=mp[b];
            if(u==v) continue;
            e.EB(u,v,w);
        }
        sort(ALL(e));
        bool f=false;
        for(int i=0;i<SZ(e);i++) {
            if(merge(e[i].u,e[i].v,e[i].w)) {
                f=true;
                break;
            }
        }
        if(f) cout<<tot[find(1)]<<'\n';
        else cout<<"No!"<<'\n';
    }
    return 0;
}