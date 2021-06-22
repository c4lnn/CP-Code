#include <bits/stdc++.h>
#define int long long
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e6+5;
int a[N],b[N],n,m;
signed main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%lld%lld",&n,&m);
    vector<vector<int>>c(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            scanf("%lld",&c[i][j]);
            a[i]+=c[i][j];
            b[j]+=c[i][j];
        }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) printf("%lld ",a[i]+b[j]-c[i][j]);
        puts("");
    }
    return 0;
}