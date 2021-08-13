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
LL x[N],y[N],w[N][N],f[N];
bool vis[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>x[i]>>y[i];
        }
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                w[i][j]=w[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            }
        }
        memset(f,0x3f,sizeof f);
        memset(vis,false,sizeof vis);
        f[1]=0;
        LL res=0;
        for(int i=1;i<=n;i++) {
            int x=0;
            for(int j=1;j<=n;j++) if(!vis[j]&&(x==0||f[j]<f[x])) {
                x=j;
            }
            vis[x]=true;
            res=max(res,f[x]);
            for(int j=1;j<=n;j++) if(!vis[j]&&w[x][j]<f[j]) {
                f[j]=w[x][j];
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}