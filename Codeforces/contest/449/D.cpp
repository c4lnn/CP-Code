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
const LL MOD=1e9+7;
const int N=2e6+5;
LL tot[N];
LL qpow(LL a,LL b) {
    LL ret=1;
    while(b) {
        if(b&1) ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        ++tot[x];
    }
    for(int i=0;i<20;i++) {
        for(int j=(1<<20)-1;~j;j--) if(j&(1<<i)) {
            tot[j^(1<<i)]+=tot[j];
        }
    }
    for(int i=0;i<1<<20;i++) tot[i]=(qpow(2,tot[i])-1+MOD)%MOD;
    for(int i=19;~i;i--) {
        for(int j=(1<<20)-1;~j;j--) if(j&(1<<i)) {
            tot[j^(1<<i)]=(tot[j^(1<<i)]+MOD-tot[j])%MOD;
        }
    }
    cout<<tot[0]<<'\n';
    return 0;
}