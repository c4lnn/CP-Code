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
int n,cnt,p[N],mn[N],phi[N],a[N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    for(int i=2;i<=1000003;i++) {
        if(!mn[i]) mn[i]=i,p[++cnt]=i,phi[i]=i-1;
        for(int j=1;j<=cnt;j++) {
            if(p[j]>mn[i]||i*p[j]>1000003) break;
            mn[i*p[j]]=p[j];
            phi[i*p[j]]=i%p[j]?phi[i]*(p[j]-1):phi[i]*p[j];
        }
    }
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        LL sum=0;
        for(int i=1,j=1;i<=n;j++) while(i<=n&&phi[j]>=a[i]) ++i,sum+=j;
        printf("Case %d: %lld Xukha\n",cs,sum);
    }
    return 0;
}