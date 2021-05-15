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
const int N=1e4+5;
int e,f,n,p[N],w[N],dp[N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d%d%d,",&e,&f,&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&p[i],&w[i]);
        for(int i=1;i<=f-e;i++) dp[i]=0x3f3f3f3f;
        for(int i=1;i<=n;i++)
            for(int j=w[i];j<=f-e;j++)
                dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
        if(dp[f-e]==0x3f3f3f3f) puts("This is impossible.");
        else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[f-e]);
    }
    return 0;
}