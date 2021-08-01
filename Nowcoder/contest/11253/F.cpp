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
const DB PI=acos(-1);
const DB EPS=1e-5;
int sgn(double x) {return fabs(x)<EPS?0:(x>0?1:-1);}
DB p[4][3];
struct P {
    DB x,y,z;
    P() {}
    P(DB x,DB y,DB z):x(x),y(y),z(z) {}
    DB dist(const P &p) {return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y)+(z-p.z)*(z-p.z));}
};
struct S {
    P p;
    DB r;
    S() {}
    S(P p,DB r):p(p),r(r) {}
    DB vol() {return 4*PI*r*r*r/3;} // 体积
    DB s_s_area(S &T) { // 两球体积交
        DB d=p.dist(T.p);
        if(sgn(d-r-T.r)>=0) return 0;
        if(sgn(d-fabs(r-T.r))<=0) return r<T.r?vol():T.vol();
        DB h1=r-(r*r-T.r*T.r+d*d)/(2*d);
        DB h2=T.r-(T.r*T.r-r*r+d*d)/(2*d);
        return PI/3*(h1*h1*(3*r-h1)+h2*h2*(3*T.r-h2));
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        for(int i=0;i<4;i++) {
            for(int j=0;j<3;j++) {
                cin>>p[i][j];
            }
        }
        DB k1,k2;cin>>k1>>k2;
        DB a,b,c,d;
        a=(k1*k1*p[1][0]-p[0][0])/(k1*k1-1);
        b=(k1*k1*p[1][1]-p[0][1])/(k1*k1-1);
        c=(k1*k1*p[1][2]-p[0][2])/(k1*k1-1);
        d=(k1*k1*(p[1][0]*p[1][0]+p[1][1]*p[1][1]+p[1][2]*p[1][2])-p[0][0]*p[0][0]-p[0][1]*p[0][1]-p[0][2]*p[0][2])/(k1*k1-1);
        S s1={{a,b,c},sqrt(a*a+b*b+c*c-d)};
        a=(k2*k2*p[3][0]-p[2][0])/(k2*k2-1);
        b=(k2*k2*p[3][1]-p[2][1])/(k2*k2-1);
        c=(k2*k2*p[3][2]-p[2][2])/(k2*k2-1);
        d=(k2*k2*(p[3][0]*p[3][0]+p[3][1]*p[3][1]+p[3][2]*p[3][2])-p[2][0]*p[2][0]-p[2][1]*p[2][1]-p[2][2]*p[2][2])/(k2*k2-1);
        S s2={{a,b,c},sqrt(a*a+b*b+c*c-d)};
        cout<<fixed<<setprecision(3)<<s1.s_s_area(s2)<<'\n';
    }
    return 0;
}