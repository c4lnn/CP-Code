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
    // 两点距离
    DB dist(const P &p) {return hypot(x-p.x,y-p.y);}
};
struct C {
    P p;
    DB r;
    C() {}
    C(P p,DB r):p(p),r(r) {}
    DB area() {return PI*r*r;}
    // 圆与圆的关系
    // 5 相离
    // 4 外切
    // 3 相交
    // 2 内切
    // 1 内含
    int c_relation(C c) {
        DB d=p.dist(c.p);
        if(sgn(d-r-c.r)>0) return 5;
        if(sgn(d-r-c.r)==0) return 4;
        DB l=fabs(r-c.r);
        if(sgn(d-r-c.r)<0&&sgn(d-l)>0) return 3;
        if(sgn(d-l)==0) return 2;
        if(sgn(d-l)<0) return 1;
    }
    DB c_area(C c) {
        int rel=c_relation(c);
        if(rel>=4) return 0;
        if(rel<=2) return min(area(),c.area());
        DB d=p.dist(c.p);
        DB hf=(r+c.r+d)/2;
        DB ss=2*sqrt(hf*(hf-r)*(hf-c.r)*(hf-d));
        DB a1=acos((r*r+d*d-c.r*c.r)/(2*r*d))*r*r;
        DB a2=acos((c.r*c.r+d*d-r*r)/(2*c.r*d))*c.r*c.r;
        return a1+a2-ss;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        DB r1,x1,y1;cin>>r1>>x1>>y1;
        DB r2,x2,y2;cin>>r2>>x2>>y2;
        DB a;cin>>a;
        C c1=C(P(x1,y1),sqrt(r1*r1-(a/2)*(a/2))-a/2);
        C c2=C(P(x2,y2),sqrt(r2*r2-(a/2)*(a/2))-a/2);
        if(sgn(c2.r)<0) cout<<fixed<<setprecision(6)<<0.0<<'\n';
        else cout<<fixed<<setprecision(6)<<c1.c_area(c2)/c1.area()<<'\n';
    }
    return 0;
}