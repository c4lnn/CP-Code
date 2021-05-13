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
const int N=4e4+5;
int mu[N],mn[N],sum[N];
VI p;
void get_mu(int n) {
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
int solve(int n) {
    int ret=0;
    for(int l=1,r;l<=n;l=r+1) {
        r=n/(n/l);
        ret+=(n/l)*(n/l)*(sum[r]-sum[l-1]);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    get_mu(40000);
    int n;cin>>n;
    cout<<solve(n-1)+2<<'\n';
    return 0;
}