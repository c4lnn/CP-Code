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
LL mn[N];
vector<LL> p;
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    for(LL i=2;i<=1000000;i++) {
        if(!mn[i]) mn[i]=i,p.PB(i);
        for(auto x:p) {
            if(x>mn[i]||x*i>1000000) break;
            mn[i*x]=x;
        }
    }
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        LL x;
        scanf("%lld",&x);
        bool f=false;
        if(x<0) f=true,x=abs(x);
        if(x==1) {printf("Case %d: 1\n",cs);continue;}
        int res=-1;
        LL t=x;
        for(int i=0;i<SZ(p);i++) {
            if(p[i]*p[i]>t) break;
            if(t%p[i]) continue;
            int tot=0;
            while(t%p[i]==0) {
                t/=p[i];
                ++tot;
            }
            if(res==-1) res=tot;
            else res=__gcd(res,tot);
        }
        if(t>1) res=1;
        while(f&&res%2==0) res>>=1;
        printf("Case %d: %lld\n",cs,res);
    }
    return 0;
}