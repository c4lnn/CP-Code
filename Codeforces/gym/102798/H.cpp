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
const int N=1e6+5;
int sum[N],cnt[N],res[N];
VPII a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,s;cin>>n>>m>>s;
    for(int i=1;i<=s;i++) {
        int t,x,y;cin>>t>>x>>y;
        a[y].EB(t,x);
    }
    for(int i=1;i<=n;i++) {
        unordered_map<int,int> bg;
        sum[0]=0;
        for(int j=0;j<SZ(a[i]);j++) {
            int t=a[i][j].FI,x=a[i][j].SE;
            if(j) sum[j]=sum[j-1];
            if(t==1) bg[x]=j,cnt[x]=0;
            else if(t==2) res[x]+=sum[j]-sum[bg[x]]-cnt[x],cnt[x]=0,bg.erase(x);
            else ++cnt[x],++sum[j];
        }
        for(auto x:bg) res[x.FI]+=sum[SZ(a[i])-1]-sum[x.SE]-cnt[x.FI];
    }
    for(int i=1;i<=m;i++) cout<<res[i]<<'\n';
    return 0;
}