#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
const int N=100;
int n,m,k,a[N],res[N],mn;
DB x[N],y[N],dist[N][N],dp[N];
void dfs(int pos,int tot,int sum,DB *dp) {
    if(tot==k) {
        if(sum<mn) {
            mn=sum;
            for(int i=1;i<=tot;i++) res[i]=a[i];
        }
        return;
    }
    if(pos>m) return;
    DB temp[N];
    for(int i=1;i<=n;i++) {
        if(dp[i]>dist[i][pos]) temp[i]=dist[i][pos];
        else temp[i]=dp[i];
    }
    DB t=0;
    for(int i=1;i<=n;i++) t+=temp[i];
    a[tot+1]=pos;
    dfs(pos+1,tot+1,t,temp);
    dfs(pos+1,tot,sum,dp);
}
DB calc(int x1,int y1,int x2,int y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
    for(int i=1;i<=m;i++) {
        DB p,q;
        scanf("%lf%lf",&p,&q);
        for(int j=1;j<=n;j++) dist[j][i]=calc(p,q,x[j],y[j]);
    }
    for(int i=1;i<=n;i++) dp[i]=0x3f3f3f3f;
    mn=0x3f3f3f3f;
    dfs(1,0,0,dp);
    for(int i=1;i<=k;i++) printf("%d%c",res[i],i==k?'\n':' ');
    return 0;
}