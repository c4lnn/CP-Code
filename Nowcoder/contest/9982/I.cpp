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
const int N=4e6+5;
LL n,mn[N],res;
vector<LL> p;
LL qpow(LL a,LL b) {
    LL ret=1;
    while(b) {
        if(b&1) ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}
void get_prime(int n) {
    for(LL i=2;i<=n;i++) {
        if(!mn[i]) mn[i]=i,p.push_back(i);
        for(auto x:p) {
            if(x>mn[i]||x*i>n) break;
            mn[i*x]=x;
        }
    }
}
void dfs(LL d,LL sum,int i) {
    for(;i<SZ(p);i++) {
        if(d*p[i]>n) break;
        LL t=(sum*qpow(10,((int)log10(p[i])+1))%MOD+p[i])%MOD;
        res=(res+t)%MOD;
        dfs(d*p[i],t,i);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    get_prime(n);
    for(int i=0;i<SZ(p);i++) {
        res=(res+p[i])%MOD;
        dfs(p[i],p[i],i);
    }
    cout<<res<<'\n';
    return 0;
}