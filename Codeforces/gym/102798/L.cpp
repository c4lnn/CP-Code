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
const int N=3e4+5;
int mn[N];
VI p;
DB lg[N],dp[N];
void prime_seive(int n) {
    for(int i=2;i<=n;i++) {
        if(!mn[i]) mn[i]=i,p.PB(i);
        for(auto x:p) {
            if(x>mn[i]||x*i>n) break;
            mn[i*x]=x;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    prime_seive(30000);
    for(int i=1;i<=30000;i++) lg[i]=log(i);
    for(auto x:p) {
        for(int i=30000;i>=2;i--) {
            for(int j=x;i-j>=0;j*=x) {
                dp[i]=max(dp[i],dp[i-j]+lg[j]);
            }
        }
    }
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        cout<<fixed<<setprecision(9)<<dp[n]<<'\n';
    }
    return 0;
}