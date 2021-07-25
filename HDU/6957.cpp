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
const int N=2e3+5;
int a[N][N],dp[N][N],l[N][N],r[N][N],stk[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,m;cin>>n>>m;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>a[i][j];
            }
        }
        for(int j=1;j<=m;j++) {
            for(int i=1;i<=n;i++) {
                if(a[i][j]>=a[i-1][j]) dp[i][j]=dp[i-1][j]+1;
                else dp[i][j]=1;
            }
        }
        int top=0;
        for(int i=1;i<=n;i++) {
            for(int j=m;j;j--) {
                while(top>=1&&dp[i][stk[top]]>dp[i][j]) {
                    l[i][stk[top]]=j+1;
                    --top;
                }
                stk[++top]=j;
            }
            while(top>=1) l[i][stk[top--]]=1;
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                while(top>=1&&dp[i][stk[top]]>dp[i][j]) {
                    r[i][stk[top]]=j-1;
                    --top;
                }
                stk[++top]=j;
            }
            while(top>=1) r[i][stk[top--]]=m;
        }
        int res=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                res=max(res,dp[i][j]*(r[i][j]-l[i][j]+1));
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}