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
const int N=1005;
int pre[N],dp[N];
struct R {
    int w,v,id;
    R() {}
    R(int w,int v,int id):w(w),v(v),id(id) {}
    bool operator < (const R &a) const {
        return w<a.w;
    }
}a[N];
void print(int x) {
    if(pre[x]) print(pre[x]);
    printf("%d\n",a[x].id);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int t=0;
    int p,q;
    while(~scanf("%d%d",&p,&q)) ++t,a[t]=R(p,q,t);
    sort(a+1,a+1+t);
    for(int i=1;i<=t;i++) dp[i]=1;
    for(int i=1;i<=t;i++)
        for(int j=1;j<i;j++) {
            if(a[i].w>a[j].w&&a[i].v<a[j].v&&dp[i]<dp[j]+1)
                dp[i]=dp[j]+1,pre[i]=j;
        }
    int mx=0;
    for(int i=1;i<=t;i++) if(dp[i]>dp[mx]) mx=i;
    printf("%d\n",dp[mx]);
    print(mx);
    return 0;
}