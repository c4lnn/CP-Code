#include<bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=6005;
int n,dp[N][N];
PII a[N];
VI b,v[N];
void pre() {
    scanf("%d",&n);
    b.clear();
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].FI,&a[i].SE),b.PB(a[i].FI),b.PB(a[i].SE);
    sort(ALL(b));
    b.resize(unique(ALL(b))-b.begin());
    for(int i=1;i<=n;i++) {
        a[i].FI=lower_bound(ALL(b),a[i].FI)-b.begin()+1;
        a[i].SE=lower_bound(ALL(b),a[i].SE)-b.begin()+1;
    }
    for(int i=1;i<=SZ(b);i++) v[i].clear();
    for(int i=1;i<=n;i++) v[a[i].FI].PB(a[i].SE);
    for(int i=1;i<=SZ(b);i++)
        for(int j=1;j<=SZ(b);j++)
            dp[i][j]=-1;
}
int dfs(int l,int r) {
    if(dp[l][r]!=-1) return dp[l][r];
    dp[l][r]=0;
    if(l>r) return 0;
    bool cnt=count(ALL(v[l]),r);
    dp[l][r]=max(dp[l][r],cnt+(l>=r?0:dfs(l+1,r)));
    for(auto x:v[l]) dp[l][r]=max(dp[l][r],cnt+(x<r?dfs(l,x)+dfs(x+1,r):0));
    return dp[l][r];
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        pre();
        printf("%d\n",dfs(1,SZ(b)));
    }
    return 0;
}