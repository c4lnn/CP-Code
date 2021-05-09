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
char s[N];
int dp1[N],dp2[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n>>s+1;
        dp1[n+1]=dp2[n+1]=0;
        bool f=false;
        for(int i=1;i<=n;i++) {
            if(s[i]=='M') {
                dp1[i]=dp1[i-1]+1;
                dp2[i]=dp2[i-1];
                if(dp1[i]>dp2[i]) f=true;
            }
            else {
                dp1[i]=dp1[i-1];
                dp2[i]=dp2[i-1]+1;
            }
        }
        int t=0;
        for(int i=n;i>=1;i--) {
            if(s[i]=='M') {
                dp1[i]=dp1[i+1]+1;
                dp2[i]=dp2[i+1];
                if(dp1[i]>dp2[i]) f=true;
                ++t;
            }
            else {
                dp1[i]=dp1[i+1];
                dp2[i]=dp2[i+1]+1;
            }
        }
        if(t*3!=n) f=true;
        cout<<(f?"NO":"YES")<<'\n';
    }
    return 0;
}