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
LL l,r,mn[N];
bool st[N];
vector<LL> p;
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    for(LL i=2;i<=50000;i++) {
        if(!mn[i]) mn[i]=i,p.PB(i);
        for(auto x:p) {
            if(x>mn[i]||x*i>50000) break;
            mn[i*x]=x;
        }
    }
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        scanf("%lld%lld",&l,&r);
        for(LL i=0;i<=r-l;i++) st[i]=false;
        for(auto x:p) {
            if(x>r) break;
            LL t=(l+x-1)/x;
            if(t==1) ++t;
            for(LL i=t*x;i<=r;i+=x) {
                st[i-l]=true;
            }
        }
        int res=0;
        for(LL i=0;i<=r-l;i++) if(!st[i]&&i+l!=1) res++;
        printf("Case %d: %d\n",cs,res);
    }
    return 0;
}