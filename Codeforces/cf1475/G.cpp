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
//head
const int N=2e5+5;
int a[N],dp[N],tot[N],pos[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        VI a(n);
        memset(tot,0,sizeof tot);
        memset(pos,-1,sizeof pos);
        for(int i=0;i<n;i++) cin>>a[i],++tot[a[i]];
        sort(ALL(a));
        a.resize(unique(ALL(a))-a.begin());
        for(int i=0;i<SZ(a);i++) pos[a[i]]=i;
        for(int i=0;i<SZ(a);i++) dp[i]=0;
        for(int i=0;i<SZ(a);i++) {
            int t=0;
            for(int j=1;j*j<=a[i];j++)
                if(a[i]%j==0) {
                    if(pos[j]!=-1) t=max(t,dp[pos[j]]+tot[a[i]]);
                    if(pos[a[i]/j]!=-1) t=max(t,dp[pos[a[i]/j]]+tot[a[i]]);
                }
            dp[i]=t;
        }
        int mx=0;
        for(int i=0;i<SZ(a);i++) mx=max(mx,dp[i]);
        cout<<n-mx<<'\n';
    }
    return 0;
}