#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
const double EPS=1e-2;
const double PI=3.1415926535;
const int N=1005;
int n,l,top;
int sgn(double x) {
    return fabs(x)<EPS?0:(x>0?1:-1);
}
struct P {
    double x,y;
    P() {}
    P(double x,double y):x(x),y(y) {}
    bool operator == (const P &a) const {return !sgn(x-a.x)&&!sgn(y-a.y);}
    bool operator < (const P &a) const {return sgn(x-a.x)<0||sgn(x-a.x)==0&&sgn(y-a.y)<0;}

    P operator - (const P &a) const {return P(x-a.x,y-a.y);}

    double operator ^ (const P &a) const {return x*a.y-y*a.x;}

    double dist(P p) {return hypot(x-p.x,y-p.y);}
}p[N],stk[N];
void andrew() {
    sort(p+1,p+1+n);
    for(int i=1;i<=min(n,2);i++) stk[++top]=p[i];
    if(n==2&&stk[1]==stk[2]) --top;
    if(n<=2) return;
    for(int i=3;i<=n;i++) {
        while(top>=2&&sgn((stk[top]-stk[top-1])^(p[i]-stk[top]))<=0) --top;
        stk[++top]=p[i];
    }
    int temp=top;
    stk[++top]=p[n-1];
    for(int i=n-2;i>=1;i--) {
        while(top>=temp&&sgn((stk[top]-stk[top-1])^(p[i]-stk[top]))<=0) --top;
        stk[++top]=p[i];
    }
    if(top==2&&stk[1]==stk[2]) --top;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
    andrew();
    double res=0;
    for(int i=2;i<=top;i++) res+=stk[i].dist(stk[i-1]);
    res+=2*PI*l;
    printf("%.0f\n",res);
    return 0;
}