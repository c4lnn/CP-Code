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
const int N=4e5+5;
unordered_map<LL,LL> mp;
LL calc(LL a,LL n, LL d) {
    return n*a+n*(n-1)/2*d;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        mp.clear();
        int n,m;cin>>n>>m;
        for(int i=1;i<=m;i++) {
            int o;cin>>o;
            if(o==1) {
                LL x,y,z;cin>>x>>y>>z;
                LL res=calc(x,y-x+1,1),t=z;
                vector<LL> a;
                for(int j=2;j*j<=t;j++) if(t%j==0) {
                    while(t%j==0) t/=j;
                    a.PB(j);
                }
                if(t!=1) a.PB(t);
                for(int j=1;j<1<<SZ(a);j++) {
                    LL lcm=1;
                    int cnt=0;
                    for(int k=0;k<SZ(a);k++) if(j&(1<<k)) {
                        lcm=lcm*a[k]/__gcd(lcm,a[k]);
                        ++cnt;
                    }
                    res+=(cnt&1?-1:1)*calc(x%lcm?x-x%lcm+lcm:x,y/lcm-(x-1)/lcm,lcm);
                }
                for(auto xx:mp) if(xx.FI>=x&&xx.FI<=y) {
                    if(__gcd(xx.FI,z)==1&&__gcd(xx.SE,z)!=1) res-=xx.FI;
                    else if(__gcd(xx.FI,z)!=1&&__gcd(xx.SE,z)==1) res+=xx.SE;
                    else if(__gcd(xx.FI,z)==1&&__gcd(xx.SE,z)==1) res+=xx.SE-xx.FI;
                }
                cout<<res<<'\n';
            }
            else {
                int x,c;cin>>x>>c;
                mp[x]=c;
            }
        }
    }
    return 0;
}