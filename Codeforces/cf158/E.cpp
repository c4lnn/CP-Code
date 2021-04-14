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
const int N=4005;
int n,m,t[N],d[N],ed[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>t[i]>>d[i];
    int mx=0;
    memset(ed,0x3f,sizeof ed);
    ed[0][0]=0;
    for(int i=1;i<=n;i++) ed[i][0]=max(ed[i-1][0]+1,t[i])+d[i]-1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ed[i][j]=min(ed[i-1][j-1],max(ed[i-1][j]+1,t[i])+d[i]-1);
    for(int i=1;i<=n;i++) if(t[i]>ed[i-1][m]) mx=max(mx,t[i]-1-ed[i-1][m]);
    mx=max(mx,86400-ed[n][m]);
    cout<<mx<<'\n';
    return 0;
}