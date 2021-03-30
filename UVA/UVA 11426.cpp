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
const int N=4e6+5;
LL mn[N],phi[N];
VI p;
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    for(LL i=2;i<=4000000;i++) {
        if(!mn[i]) mn[i]=i,p.PB(i),phi[i]=i-1;
        for(auto x:p) {
            if(x>mn[i]||x*i>4000000) break;
            mn[i*x]=x;
            phi[i*x]=i%x?phi[i]*(x-1):phi[i]*x;
        }
    }
    for(int i=3;i<=4000000;i++) phi[i]+=phi[i-1];
    LL n;
    while(~scanf("%lld",&n)&&n) {
        LL res=0;
        for(int i=1;i<=n;i++) res+=i*phi[n/i];
        printf("%lld\n",res);
    }
    return 0;
}