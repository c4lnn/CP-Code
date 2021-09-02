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
const int N=305;
char s[N][N];
int sum[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    while(cin>>n>>m>>k) {
        if(!n&&!m&&!k) break;
        for(int i=1;i<=n;i++) cin>>s[i]+1;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(s[i][j]=='.');
            }
        }
        int res=INT_MAX;
        for(int x1=1;x1<=n;x1++) {
            for(int x2=x1;x2<=n;x2++) {
                for(int y1=1,y2=1;y2<=m;y2++) {
                    while(sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]>=k) {
                        res=min(res,(x2-x1+1)*(y2-y1+1));
                        ++y1;
                    }
                }
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}