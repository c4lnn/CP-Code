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
int mn[N],phi[N];
LL sum[N];
VI p;
void get_phi(int n) {
    phi[1]=1;
    for(int i=2;i<=n;i++) {
        if(!mn[i]) mn[i]=i,p.PB(i),phi[i]=i-1;
        for(auto x:p) {
            if(x>mn[i]||x*i>n) break;
            mn[i*x]=x;
            phi[i*x]=i%x?phi[i]*(x-1):phi[i]*x;
        }
    }
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+phi[i];
}
LL solve(int n,int m) {
    LL ret=0;
    int lim=min(n,m);
    for(int l=1,r;l<=lim;l=r+1) {
        r=min(n/(n/l),m/(m/l));
        ret+=(sum[r]-sum[l-1])*(n/l)*(m/l);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    get_phi(100000);
    cout<<solve(n,m)*2-1ll*n*m<<'\n';
    return 0;
}