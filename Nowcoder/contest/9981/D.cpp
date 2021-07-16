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
//head
const LL MOD=1e9+7;
const int N=505;
int a[N][N],fa[N*N],sz[N*N],tot;
LL inv[N*N],res=1;
LL qpow(LL a,LL b) {
    LL ret=1;
    while(b) {
        if(b&1) ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y) {
    int tx=find(x),ty=find(y);
    if(tx==ty) return;
    fa[tx]=ty;
    res=res*inv[sz[tx]]%MOD;
    res=res*inv[sz[ty]]%MOD;
    res=res*inv[tot--]%MOD;
    sz[ty]+=sz[tx];
    res=res*sz[ty]%MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        for(int j=0;j<n;j++) if(s[j]=='1') a[i][j]=1,++tot;
    }
    for(int i=0;i<n*n;i++) fa[i]=i,sz[i]=1;
    for(int i=1;i<=n*n;i++) inv[i]=qpow(i,MOD-2);
    for(int i=1;i<=tot;i++) res=res*i%MOD;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(!a[i][j]) continue;
            if(i-1>=0&&a[i-1][j]) merge(i*n+j,(i-1)*n+j);
            if(j-1>=0&&a[i][j-1]) merge(i*n+j,i*n+j-1);
        }
    }
    cin>>k;
    for(int i=1;i<=k;i++) {
        int x,y;
        cin>>x>>y;
        if(!a[x][y]) {
            res=res*(++tot)%MOD;
            if(x-1>=0&&a[x-1][y]) merge(x*n+y,(x-1)*n+y);
            if(y-1>=0&&a[x][y-1]) merge(x*n+y,x*n+y-1);
            if(x+1<n&&a[x+1][y]) merge(x*n+y,(x+1)*n+y);
            if(y+1<n&&a[x][y+1]) merge(x*n+y,x*n+y+1);
            a[x][y]=1;
        }
        cout<<res<<'\n';
    }
    return 0;
}