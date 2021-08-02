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
const LL MOD=1e9+7;
const int N=5005;
int f[N][N],g[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b;cin>>a>>b;
    for(int i=0;i<=5000;i++) f[i][0]=f[0][i]=1;
    for(int i=1;i<=SZ(a);i++) {
        for(int j=1;j<=SZ(b);j++) {
            f[i][j]=((f[i-1][j]+f[i][j-1])%MOD-f[i-1][j-1]+MOD)%MOD;
            if(a[i-1]==b[j-1]) f[i][j]=(f[i][j]+f[i-1][j-1])%MOD;
        }
    }
    for(int i=0;i<=5000;i++) g[0][i]=g[i][0]=1;
    for(int i=1;i<=5000;i++) {
        for(int j=i;j<=5000;j++) {
            g[i][j]=g[j][i]=(g[i][j-1]+g[i-1][j])%MOD;
        }
    }
    LL res=0;
    for(int i=1;i<=SZ(a);i++) {
        for(int j=1;j<=SZ(b);j++) if(b[j-1]>a[i-1]) {
            res=(res+1ll*(f[i-1][j-1])*(g[SZ(a)-i][SZ(b)-j])%MOD)%MOD;
        }
    }
    cout<<res<<'\n';
    return 0;
}