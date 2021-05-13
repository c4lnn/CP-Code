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
int mn[N],mu[N],sum[N];
VI p;
void get_mu(LL n) {
    mu[1]=1;
    for(int i=2;i<=n;i++) {
        if(!mn[i]) mn[i]=i,mu[i]=-1,p.PB(i);
        for(auto x:p) {
            if(x*i>n) break;
            mn[x*i]=x;
            if(i%x==0) {mu[x*i]=0;break;}
            mu[x*i]=-mu[i];
        }
    }
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+mu[i];
}
LL solve(int n,int m) {
    LL res=0;
    int lim=min(n,m);
    for(int l=1,r;l<=lim;l=r+1) {
        r=min(n/(n/l),m/(m/l));
        res+=1ll*(n/l)*(m/l)*(sum[r]-sum[l-1]);
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    get_mu(100000);
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        int a,b,c,d,k;cin>>a>>b>>c>>d>>k;
        if(b>d) swap(b,d);
        cout<<"Case "<<cs<<": "<<(k?solve(b/k,d/k)-solve(b/k,b/k)/2:0)<<'\n';
    }
    return 0;
}