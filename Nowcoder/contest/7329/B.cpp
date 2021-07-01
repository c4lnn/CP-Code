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
const int N=1e5+5;
int n,x,y,a[N];
LL sum[N];
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d%d",&x,&y);
    sort(a+1,a+1+n,greater<int>());
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    LL res=0;
    for(int i=1;i<=x;i++)
        for(int j=1;j<=y;j++)
            res+=sum[i*j];
    printf("%lld\n",res);
    return 0;
}