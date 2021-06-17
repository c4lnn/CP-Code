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
const int N=35;
int n,u,p[N];
LL r,a[N][N],b[N],k[N],res=LLONG_MIN;
void dfs(int x,int pre) {
    if((x-u)%2==0) {
        LL sum=0;
        for(int i=1;i<=n;i++) sum+=a[x][i]*k[i];
        res=max(res,sum);
    }
    if(x==u) return;
    for(int i=1;i<=n;i++) a[x+1][i]=a[x][p[i]]+r;
    dfs(x+1,0);
    if(pre) return;
    for(int i=1;i<=n;i++) a[x+1][i]=a[x][i]^b[i];
    dfs(x+1,1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>u>>r;
    for(int i=1;i<=n;i++) cin>>a[0][i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>k[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    dfs(0,0);
    cout<<res<<'\n';
    return 0;
}