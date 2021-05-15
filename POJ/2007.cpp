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
const DB EPS=1e-8;
const int N=100;
int n,top;
int sgn(DB x) {return fabs(x)<EPS?0:(x>0?1:-1);}
struct P {
    DB x,y;
    P() {}
    P(DB x,DB y):x(x),y(y) {}

    bool operator == (const P &a) const {return !sgn(x-a.x)&&!sgn(y-a.y);}
    bool operator < (const P &a) const {return sgn(x-a.x)<0||sgn(x-a.x)==0&&sgn(y-a.y)<0;}

    P operator - (const P &a) const {return P(x-a.x,y-a.y);}

    DB operator ^ (const P &a) const {return x*a.y-y*a.x;}
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
    for(int i=n-1;i>=1;i--) {
        while(top>temp&&sgn((stk[top]-stk[top-1])^(p[i]-stk[top]))<=0) --top;
        stk[++top]=p[i];
    }
    if(top==2&&stk[1]==stk[2]) --top;
    // 凸包上有 top - 1 个点，栈中 1 号点被记录了两次，分别为 stk[1] 和 stk[top]
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    n=1;
    while(~scanf("%lf%lf",&p[n].x,&p[n].y)) ++n;
    andrew();
    int t;
    for(int i=1;i<top;i++) if(stk[i]==P(0,0)) {t=i;break;}
    for(int i=t;i<top;i++) printf("(%.0f,%.0f)\n",stk[i].x,stk[i].y);
    for(int i=1;i<t;i++) printf("(%.0f,%.0f)\n",stk[i].x,stk[i].y);
    return 0;
}