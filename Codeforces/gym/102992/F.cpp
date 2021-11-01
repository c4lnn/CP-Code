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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
const DB EPS=1e-6;
int sgn(DB x) {return fabs(x)<EPS?0:(x>0?1:-1);}
DB n,m,p;
DB qpow(DB a,int b) {
    DB ret=1;
    while(b) {
        if(b&1) ret=ret*a;
        a=a*a;
        b>>=1;
    }
    return ret;
}
DB calc(int x) {
    return 1.0*(x*n+m)/(1-qpow(1-p,x));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        cin>>n>>m>>p;
        p*=0.0001;
        int l=1,r=1e9;
        while(l<r) {
            int lmid=l+(r-l)/3,rmid=r-(r-l)/3;
            if(sgn(calc(lmid)-calc(rmid))<0) r=rmid-1;
            else l=lmid+1;
        }
        cout<<fixed<<setprecision(10)<<calc(l)<<'\n';
    }
    return 0;
}