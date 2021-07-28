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
    int m,n;cin>>m>>n;
    for(int i=0;i<m;i++) {
        string s;cin>>s;
        int x=0;
        for(int j=SZ(s)-1,t=0;~j;j--,t++) if(s[j]=='1') x+=1<<t;
        ++tot[x];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<1<<n;j++) if(j&(1<<i)) {
            tot[j]+=tot[j^(1<<i)];
        }
    }
    for(int i=0;i<1<<n;i++) tot[i]=(qpow(2,tot[i])-1+MOD)%MOD;
    for(int i=n-1;~i;i--) {
        for(int j=0;j<1<<n;j++) if(j&(1<<i)) {
            tot[j]=(tot[j]+MOD-tot[j^(1<<i)])%MOD;
        }
    }
    string s;cin>>s;
    int x=0;
    for(int j=SZ(s)-1,t=0;~j;j--,t++) if(s[j]=='1') x+=1<<t;
    cout<<tot[x]<<'\n';
    return 0;
}