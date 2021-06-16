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
const LL MOD=998244353;
const int N=1e6+5;
LL sum[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    sum[1]=1;
    for(int i=2;i<=n;i++) {
        int t=i,cnt=1;
        for(int j=2;j*j<=t;j++) if(t%j==0) {
            int tt=0;
            while(t%j==0) t/=j,++tt;
            cnt*=tt+1;
        }
        if(t>1) cnt*=2;
        sum[i]=(sum[i-1]+sum[i-1]+cnt)%MOD;
    }
    cout<<((sum[n]-sum[n-1])%MOD+MOD)%MOD<<'\n';
    return 0;
}