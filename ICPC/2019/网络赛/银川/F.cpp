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
const int N=205;
int n;
LL dp[N][N][N];
PII a[N];
void floyd() {
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[k][i][j]=min(dp[k-1][i][j],dp[k-1][i][a[k].SE]+dp[k-1][a[k].SE][j]);
}
int find(int x) {
    int l=0,r=n;
    while(l<r) {
        int mid=l+r+1>>1;
        if(a[mid].FI<=x) l=mid;
        else r=mid-1;
    }
    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        int q;cin>>n>>q;
        for(int i=1;i<=n;i++) {
            cin>>a[i].FI;
            a[i].SE=i;
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>dp[0][i][j];
        floyd();
        cout<<"Case #"<<cs<<":\n";
        for(int i=1;i<=q;i++) {
            int s,t,mx;cin>>s>>t>>mx;
            int tt=find(mx);
            cout<<dp[tt][s][t]<<'\n';
        }
    }
    return 0;
}