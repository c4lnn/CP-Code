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
    for(LL i=2;i<=N;i++) {
        if(!mn[i]) mn[i]=i,p.PB(i);
        for(auto x:p) {
            if(x>mn[i]||i*x>N) break;
            mn[i*x]=x;
        }
    }
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        LL a,b;
        scanf("%lld%lld",&a,&b);
        if(b*b>a) {printf("Case %d: 0\n",cs);continue;}
        LL t=a,res=1;
        for(auto x:p) {
            if(x>t) break;
            int tot=0;
            while(t%x==0) {
                ++tot;
                t/=x;
            }
            res*=tot+1;
        }
        if(t>1) res*=2;
        res/=2;
        for(LL i=1;i<b;i++) if(a%i==0) res--;
        printf("Case %d: %lld\n",cs,res);
    }
    return 0;
}