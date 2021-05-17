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
const int N=5e5+5;
int mn[N],mu[N],cnt[N],sum[N][20];
VI p;
void get_mu(int n) {
    mu[1]=1;
    for(int i=2;i<=n;i++) {
        if(!mn[i]) mn[i]=i,mu[i]=-1,p.PB(i),cnt[i]=1;
        for(auto x:p) {
            if(x*i>n) break;
            cnt[i*x]=cnt[i]+1;
            mn[x*i]=x;
            if(i%x==0) {mu[x*i]=0;break;}
            mu[x*i]=-mu[i];
        }
    }
}
void init(int n) {
    get_mu(n);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            sum[j][cnt[i]]+=mu[j/i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<=18;j++) {
            if(i-1>=0) sum[i][j]+=sum[i-1][j];
            if(j-1>=0) sum[i][j]+=sum[i][j-1];
            if(i-1>=0&&j-1>=0) sum[i][j]-=sum[i-1][j-1];
        }
}
LL solve(int t,int n,int m) {
    LL res=0;
    int lim=min(n,m);
    for(int l=1,r;l<=lim;l=r+1) {
        r=min(n/(n/l),m/(m/l));
        res+=1ll*(sum[r][t]-sum[l-1][t])*(n/l)*(m/l);
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init(5e5);
    int q;cin>>q;
    while(q--) {
        int n,m,t;cin>>n>>m>>t;
        if(t>=19) cout<<1ll*n*m<<'\n';
        else cout<<solve(t,n,m)<<'\n';
    }
    return 0;
}