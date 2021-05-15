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
const int N=2e5+5;
VI b;
int n,c[N];
LL dp[N][2],x[N],mx[N],mn[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>x[i]>>c[i];
        b.PB(c[i]);
    }
    sort(ALL(b));
    b.resize(unique(ALL(b))-b.begin());
    memset(mn,0x3f,sizeof mn);
    memset(mx,0xc0,sizeof mx);
    for(int i=1;i<=n;i++) {
        int pos=lower_bound(ALL(b),c[i])-b.begin();
        mx[pos]=max(mx[pos],x[i]);
        mn[pos]=min(mn[pos],x[i]);
    }
    dp[SZ(b)-1][0]=abs(mx[SZ(b)-1])+abs(mx[SZ(b)-1]-mn[SZ(b)-1]);
    dp[SZ(b)-1][1]=abs(mn[SZ(b)-1])+abs(mx[SZ(b)-1]-mn[SZ(b)-1]);
    for(int i=SZ(b)-2;~i;i--) {
        dp[i][0]=min(dp[i+1][0]+abs(mn[i+1]-mx[i]),dp[i+1][1]+abs(mx[i+1]-mx[i]))+abs(mx[i]-mn[i]);
        dp[i][1]=min(dp[i+1][0]+abs(mn[i+1]-mn[i]),dp[i+1][1]+abs(mx[i+1]-mn[i]))+abs(mx[i]-mn[i]);
    }
    cout<<min(dp[0][0]+abs(mn[0]),dp[0][1]+abs(mx[0]))<<'\n';
    return 0;
}
