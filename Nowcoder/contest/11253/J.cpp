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
const int N=8e4;
int mn[10000001];
LL binom[40001][31];
int tot[N+5];
VI p;
void prime_seive(int n) {
    for(int i=2;i<=n;i++) {
        if(!mn[i]) mn[i]=i,p.PB(i);
        for(auto x:p) {
            if(x>mn[i]||x*i>n) break;
            mn[i*x]=x;
        }
    }
}
LL get_phi(LL n) {
    LL ret=n;
    for(int i=0,x=p[0];x*x<=n&&i<SZ(p);i++,x=p[i]) if(n%x==0) {
        while(n%x==0) ret=ret/x*(x-1),n/=x;
    }
    if(n>1) ret=ret/n*(n-1);
    return ret;
}
LL add(LL a,LL b,LL m) {
    return a+=b,a>=m?a-m:a;
}
LL mul(LL a,LL b,LL m) {
    return (__int128)a*b%m;
}
LL qpow(LL a,LL b,LL m) {
    LL ret=1;
    while(b) {
        if(b&1) ret=mul(ret,a,m);
        a=mul(a,a,m);
        b>>=1;
    }
    return ret;
}
void init(int n,int k,LL m) {
    binom[0][0]=1;
    for(int i=1;i<=n;i++) {
        binom[i][0]=1;
        for(int j=1;j<=min(i,k);j++) {
            binom[i][j]=add(binom[i-1][j-1],binom[i-1][j],m);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    prime_seive(1e7);
    int T;cin>>T;
    while(T--) {
        memset(tot,0,sizeof tot);
        int n,k;LL m;cin>>n>>k>>m;
        for(int i=1;i<=n;i++) {
            int x;cin>>x;
            ++tot[x];
        }
        LL phi=get_phi(m);
        init(n,k,phi);
        LL res=1;
        for(auto x:p) {
            if(x>N) break;
            LL sum=0;
            for(LL i=x;i<=N;i*=x) {
                int cnt=0;
                for(int j=i;j<=N;j+=i) cnt+=tot[j];
                if(cnt<k) continue;
                sum+=binom[cnt][k];
            }
            if(sum>=phi) sum=sum%phi+phi;
            res=mul(res,qpow(x,sum,m),m);
        }
        cout<<res<<'\n';
    }
    return 0;
}