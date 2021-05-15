#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
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
const int N=1e6+5;
int n,m,t;
LL dp[N];
VI b;
struct R {
    int l,r;
    LL w;
    bool operator < (const R &a) const {
        return r<a.r;
    }
}a[N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=m;i++) {
        scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].w);
        b.PB(a[i].r);
    }
    sort(a+1,a+1+m);
    sort(ALL(b));
    b.resize(unique(ALL(b))-b.begin());
    int pre=-1;
    for(int i=1;i<=m;i++) {
        if(a[i].r!=pre) dp[a[i].r]=dp[pre],pre=a[i].r;
        int pos=upper_bound(ALL(b),a[i].l-t)-b.begin();
        if(!pos) dp[a[i].r]=max(dp[a[i].r],a[i].w);
        else {
            --pos;
            dp[a[i].r]=max(dp[a[i].r],dp[b[pos]]+a[i].w);
        }
    }
    printf("%lld\n",dp[a[m].r]);
    return 0;
}