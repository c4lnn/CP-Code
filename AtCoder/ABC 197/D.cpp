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
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
const DB EPS=1e-8;
const DB PI=acos(-1);
int sgn(DB x) {return fabs(x)<EPS?0:(x>0?1:-1);}
struct P {
    DB x,y;
    P() {}
    P(DB x,DB y):x(x),y(y) {}

    bool operator == (const P &a) const {return !sgn(x-a.x)&&!sgn(y-a.y);}
    bool operator < (const P &a) const {return sgn(x-a.x)<0||sgn(x-a.x)==0&&sgn(y-a.y)<0;}

    P operator + (const P &a) const {return P(x+a.x,y+a.y);}
    P operator - (const P &a) const {return P(x-a.x,y-a.y);}
    P operator * (const DB &k) const {return P(x*k,y*k);}
    P operator / (const DB &k) const {return P(x/k,y/k);}

    DB operator * (const P &a) const {return x*a.x+y*a.y;}  // 点积
    DB operator ^ (const P &a) const {return x*a.y-y*a.x;}  // 叉积
    // 这个点与 a，b 所成的夹角
    DB rad(P a,P b) {return fabs(atan2(fabs((a-*this)^(b-*this)),(a-*this)*(b-*this)));}

    DB len() {return hypot(x,y);}  // 点到原点的距离
    DB len2() {return x*x+y*y;}  // 点到原点的距离的平方
    DB dist(P p) {return hypot(x-p.x,y-p.y);}  // 两点距离

    P rotleft() {return P(-y,x);}  // 绕原点逆时针旋转 90 度
    P rotright() {return P(y,-x);}  // 绕原点顺时针旋转 90 度
    P rotate(P p,DB angle) {  // 绕 P 点逆时针旋转 angle 度
        P v=*this-p;
        DB c=cos(angle),s=sin(angle);
        return P(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }
};
P compute_circle_center(P a,P b) {return(a+b)/2;} // 两点定圆
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    DB x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    P t=compute_circle_center(P(x1,y1),P(x2,y2));
    t=P(x1,y1).rotate(t,PI/(n/2));
    cout<<fixed<<setprecision(10)<<t.x<<' '<<t.y<<'\n';
    return 0;
}