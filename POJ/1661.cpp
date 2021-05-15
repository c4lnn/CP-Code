#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
const int N=1005;
struct R {
    int x1,x2,h;
    R() {}
    R(int x1,int x2,int h):x1(x1),x2(x2),h(h) {}
    bool operator < (const R &a) const {
        return h>a.h;
    }
};
vector<R> a;
int n,x,y,mx,dp[N][2];
bool st[N][2];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        memset(dp,0x3f,sizeof dp);
        memset(st,false,sizeof st);
        a.clear();
        scanf("%d%d%d%d",&n,&x,&y,&mx);
        a.PB(R(x,x,y));
        for(int i=1;i<=n;i++) {
            int x1,x2,h;
            scanf("%d%d%d",&x1,&x2,&h);
            a.PB(R(x1,x2,h));
        }
        sort(ALL(a));
        int res=0x3f3f3f3f;
        dp[0][0]=dp[0][1]=0;
        for(int i=0;i<SZ(a);i++) {
            for(int j=0;j<i;j++) {
                if(a[j].h-a[i].h>mx||a[i].h==a[j].h) continue;
                bool p=false,q=false;
                if(!st[j][0]&&a[j].x1<=a[i].x2&&a[j].x1>=a[i].x1) p=true,dp[i][0]=min(dp[i][0],dp[j][0]+a[j].x1-a[i].x1+a[j].h-a[i].h);
                if(!st[j][1]&&a[j].x2>=a[i].x1&&a[j].x2<=a[i].x2) q=true,dp[i][0]=min(dp[i][0],dp[j][1]+a[j].x2-a[i].x1+a[j].h-a[i].h);
                if(!st[j][0]&&a[j].x1<=a[i].x2&&a[j].x1>=a[i].x1) p=true,dp[i][1]=min(dp[i][1],dp[j][0]+a[i].x2-a[j].x1+a[j].h-a[i].h);
                if(!st[j][1]&&a[j].x2>=a[i].x1&&a[j].x2<=a[i].x2) q=true,dp[i][1]=min(dp[i][1],dp[j][1]+a[i].x2-a[j].x2+a[j].h-a[i].h);
                if(p) st[j][0]=true;
                if(q) st[j][1]=true;
            }
        }
        for(int i=0;i<SZ(a);i++) {
            if(a[i].h>mx) continue;
            if(!st[i][0]) res=min(res,dp[i][0]+a[i].h);
            if(!st[i][1]) res=min(res,dp[i][1]+a[i].h);
        }
        printf("%d\n",res);
    }
    return 0;
}