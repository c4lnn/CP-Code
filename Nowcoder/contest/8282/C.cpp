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
const double EPS=1e-8;
const int N=1e6+5;
int n,top;
int sgn(double x) {return fabs(x)<EPS?0:(x>0?1:-1);}
struct P {
    double x,y;
    P() {}
    P(double x,double y):x(x),y(y) {}

    bool operator == (const P &a) const {return !sgn(x-a.x)&&!sgn(y-a.y);}
    bool operator < (const P &a) const {return sgn(x-a.x)<0||sgn(x-a.x)==0&&sgn(y-a.y)<0;}

    P operator - (const P &a) const {return P(x-a.x,y-a.y);}

    double operator ^ (const P &a) const {return x*a.y-y*a.x;}  // 叉积

    double dist(P p) {return hypot(x-p.x,y-p.y);}  // 两点距离
}p[N],stk[N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        DB y;
        scanf("%lf",&y);
        p[i]=P(i,y);
    }
    sort(p+1,p+1+n);
    for(int i=1;i<=min(n,2);i++) stk[++top]=p[i];
    for(int i=3;i<=n;i++) {
        while(top>=2&&sgn((stk[top]-stk[top-1])^(p[i]-stk[top]))<=0) --top;
        stk[++top]=p[i];
    }
    double res=stk[1].y;
    for(int i=2;i<=top;i++) {
        double d=(stk[i].y-stk[i-1].y)/(stk[i].x-stk[i-1].x);
        res+=(stk[i].x-stk[i-1].x)*(stk[i-1].y+d)+(stk[i].x-stk[i-1].x)*(stk[i].x-stk[i-1].x-1)*d/2;
    }
    printf("%.10f\n",res);
    return 0;
}