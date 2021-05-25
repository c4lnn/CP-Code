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
const LL MOD=1000007;
const int N=405;
LL c[N][N];
void init(int n) {
    for(int i=0;i<=n;i++) c[i][0]=c[i][i]=1;
    for(int i=2;i<=n;i++) {
        for(int j=1;j<i;j++) {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
        }
    }
}
LL C(int n,int m) {
    if(n<m) return 0;
    return c[n][m];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init(400);
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        int n,m,k;cin>>n>>m>>k;
        LL ret=C(n*m,k);
        ret=(ret-C(n*m-n,k))%MOD;
        ret=(ret-C(n*m-n,k))%MOD;
        ret=(ret-C(n*m-m,k))%MOD;
        ret=(ret-C(n*m-m,k))%MOD;
        ret=(ret+C(n*m-(n+m-1),k))%MOD;
        ret=(ret+C(n*m-(n+m-1),k))%MOD;
        ret=(ret+C(n*m-(n+m-1),k))%MOD;
        ret=(ret+C(n*m-(n+m-1),k))%MOD;
        ret=(ret+C(n*m-(n+n),k))%MOD;
        ret=(ret+C(n*m-(m+m),k))%MOD;
        ret=(ret-C(n*m-(n+n+m-2),k))%MOD;
        ret=(ret-C(n*m-(n+n+m-2),k))%MOD;
        ret=(ret-C(n*m-(n+m+m-2),k))%MOD;
        ret=(ret-C(n*m-(n+m+m-2),k))%MOD;
        ret=(ret+C(n*m-2*(n+m-2),k))%MOD;
        cout<<"Case "<<cs<<": "<<(ret+MOD)%MOD<<'\n';
    }
    return 0;
}