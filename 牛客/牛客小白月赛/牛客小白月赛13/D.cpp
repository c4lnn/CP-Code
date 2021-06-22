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
const int N=5e6+5;
int n;
LL a[N],pre[N],suf[N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) pre[i]=(pre[i-1]|a[i]);
    for(int i=n;i>=1;i--) suf[i]=(suf[i+1]|a[i]);
    LL res=0;
    for(int i=1;i<=n;i++) res=max(res,pre[i-1]|suf[i+1]);
    printf("%lld\n",res);
    return 0;
}