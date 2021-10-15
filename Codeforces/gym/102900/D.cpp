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
DB n,p1,p2,v1,v2;
bool check(DB t) {
    DB a,b;
    a=min(p2-p1,max(0.0,v1*t-2*p1));
    b=min(p2-p1,max(0.0,v2*t-2*(n-p2)));
    if(v1*t>=p1&&v2*t>=n-p2&&a+b>=p2-p1) return true;
    if(v1*t>=p1&&v2*t>=n-p2+2*(p2-p1-a)) return true;
    if(v1*t>=p1+2*(p2-p1-b)&&v2*t>=n-p2) return true;
    a=min(p2-p1,max(0.0,(t-p1/v1)*v1/2));
    b=min(p2-p1,max(0.0,(t-(n-p2)/v2)*v2/2));
    if(t*v1>=p1&&t*v2>=n-p2&&a+b>=p2-p1) return true;
    return false;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%lf%lf%lf%lf%lf",&n,&p1,&v1,&p2,&v2);
        if(p1>p2) swap(p1,p2),swap(v1,v2);
        DB l=0,r=min({min(n+p1,n+n-p1)/v1,min(n+p2,n+n-p2)/v2,max((n-p1)/v1,p2/v2)});
        for(int i=0;i<200;i++) {
            DB mid=(l+r)/2.0;
            if(check(mid)) r=mid;
            else l=mid;
        }
        printf("%.10f\n",r);
    }
    return 0;
}