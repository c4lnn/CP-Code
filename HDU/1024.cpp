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
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e6+5;
int n,m,dp[N],a[N],mx[N],t;
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%d%d",&m,&n)) {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=0;i<=n;i++) dp[i]=mx[i]=0;
        for(int i=1;i<=m;i++) {
            t=0xc0c0c0c0;
            for(int j=i;j<=n;j++) {
                dp[j]=max(dp[j-1],mx[j-1])+a[j];
                mx[j-1]=t;
                t=max(t,dp[j]);
            }
        }
        printf("%d\n",t);
    }
    return 0;
}