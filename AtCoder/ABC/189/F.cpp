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
const int N=1e5+5;
int n,m,k;
bool st[N];
pair<DB,DB> f[N],dp[N<<1];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++) {
        int x;
        cin>>x;
        st[x]=true;
    }
    for(int i=n;~i;i--) {
        f[i].FI=f[i+1].FI-dp[i+1+m].FI+dp[i+1].FI;
        f[i].SE=f[i+1].SE-dp[i+1+m].SE+dp[i+1].SE;
        if(st[i]) dp[i]=MP(1,0);
        else if(i<n) dp[i].FI=f[i].FI/m,dp[i].SE=f[i].SE/m+1;
    }
    if(fabs(1-dp[0].FI)<1e-6) cout<<-1<<'\n';
    else cout<<fixed<<setprecision(4)<<dp[0].SE/(1-dp[0].FI)<<'\n';
    return 0;
}