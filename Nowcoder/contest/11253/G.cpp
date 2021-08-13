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
const int N=5005;
int dp[N][N],sum[N];
PII a[N];
VPII b;
VI c;
bool cmp(PII a,PII b) {
    return a.FI<b.FI||a.FI==b.FI&&a.SE>b.SE;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i].FI>>a[i].SE;
    sort(a,a+n);
    for(int i=0;i<n;i++) {
        while(SZ(b)&&a[i].SE<=b.back().SE) {
            c.PB(b.back().SE-b.back().FI);
            b.pop_back();
        }
        b.PB(a[i]);
    }
    sort(ALL(c),greater<int>());
    for(int i=0;i<SZ(c);i++) sum[i+1]=sum[i]+c[i];
    memset(dp,0xc0,sizeof dp);
    dp[0][0]=0;
    int res=0;
    for(int i=1;i<=k;i++) {
        deque<int> q;
        for(int j=0;j<SZ(b);j++) {
            while(SZ(q)&&dp[i-1][q.back()]+b[q.back()].SE<=dp[i-1][j]+b[j].SE) q.pop_back();
            while(SZ(q)&&b[q[0]].SE<=b[j].FI) q.pop_front();
            q.PB(j);
            dp[i][j+1]=dp[i-1][q[0]]+b[q[0]].SE-b[j].FI;
        }
        if(SZ(c)>=k-i) res=max(res,dp[i][SZ(b)]+sum[k-i]);
    }
    cout<<res<<'\n';
    return 0;
}