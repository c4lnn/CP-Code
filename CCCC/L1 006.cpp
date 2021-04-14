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
LL fac[20];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL x;cin>>x;
    fac[0]=1;
    for(int i=1;i<=13;i++) fac[i]=fac[i-1]*i;
    int mx=0,ll;
    for(int l=2;l*(l+1);l++) {
        for(int r=l;r<=13;r++) if(x%(fac[r]/fac[l-1])==0) {
            int t=x/fac[r]/fac[l-1];
            if(t>l&&t<r) continue;
            if(r-l+1>mx) mx=r-l+1,ll=l;
        }
    }
    cout<<mx<<'\n';
    for(int i=ll;i<ll+mx;i++) cout<<i<<"*\n"[i==ll+mx-1];
    return 0;
}