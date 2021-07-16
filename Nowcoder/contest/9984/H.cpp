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
const int N=1e5+5;
int n;
LL w[N],a[N],b[N],c[N];
char o[N];
bool f[N];
VI g[N];
LL qpow(LL a,LL b) {
    LL ret=1;
    while(b) {
        if(b&1) ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}
LL get_inv(LL x) {
    return qpow(x,MOD-2);
}
void dfs(int u) {
    for(auto v:g[u]) {
        if(o[v]=='+') {
            a[v]=(a[u]+w[v])%MOD;
            b[v]=w[v];
            c[v]=a[u]%MOD;
            f[v]=false;
        }
        else if(o[v]=='-') {
            a[v]=(a[u]-w[v]+MOD)%MOD;
            b[v]=w[v];
            c[v]=a[u]%MOD;
            f[v]=true;
        }
        else if(o[v]=='*') {
            if(!f[u]) a[v]=(c[u]+b[u]*w[v]%MOD)%MOD;
            else a[v]=(c[u]-b[u]*w[v]%MOD+MOD)%MOD;
            c[v]=c[u];
            b[v]=b[u]*w[v]%MOD;
            f[v]=f[u];
        }
        else if(o[v]=='/') {
            if(!f[u]) a[v]=(c[u]+b[u]*get_inv(w[v])%MOD)%MOD;
            else a[v]=(c[u]-b[u]*get_inv(w[v])%MOD+MOD)%MOD;
            c[v]=c[u];
            b[v]=b[u]*get_inv(w[v])%MOD;
            f[v]=f[u];
        }
        dfs(v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=2;i<=n;i++) {
        int fa;
        cin>>fa;
        g[fa].PB(i);
    }
    for(int i=2;i<=n;i++) cin>>o[i];
    a[1]=b[1]=w[1];
    dfs(1);
    for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
    return 0;
}