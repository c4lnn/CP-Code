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
const int N=1e3+5;
int n,a[N],dp[N],res;
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%d",&n)&&n) {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        res=INT_MIN;
        for(int i=1;i<=n;i++) {
            dp[i]=a[i];
            for(int j=1;j<i;j++)
                if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]+a[i]);
                res=max(res,dp[i]);
        }
        printf("%d\n",res);
    }
    return 0;
}