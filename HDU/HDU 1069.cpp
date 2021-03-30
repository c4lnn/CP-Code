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
const int N=200;
int n,dp[N];
struct R {
    int a,b,c;
    R() {}
    R(int a,int b,int c):a(a),b(b),c(c) {}
    bool operator < (const R &t) const {
        return a>t.a||a==t.a&&b>t.b;
    }
}x[N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int cs=0;
    while(~scanf("%d",&n)&&n) {
        for(int i=1;i<=n;i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            x[6*i-5]=R(a,b,c);
            x[6*i-4]=R(b,a,c);
            x[6*i-3]=R(a,c,b);
            x[6*i-2]=R(c,a,b);
            x[6*i-1]=R(b,c,a);
            x[6*i]=R(c,b,a);
        }
        sort(x+1,x+1+6*n);
        int res=0;
        for(int i=1;i<=6*n;i++) {
            dp[i]=x[i].c;
            for(int j=1;j<i;j++)
                if(x[i].a<x[j].a&&x[i].b<x[j].b)
                    dp[i]=max(dp[i],dp[j]+x[i].c);
            res=max(res,dp[i]);
        }
        printf("Case %d: maximum height = %d\n",++cs,res);
    }
    return 0;
}