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
const int N=55;
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
    DB rad(const P &a,const P &b) {return fabs(atan2(fabs((a-*this)^(b-*this)),(a-*this)*(b-*this)));}

    DB len() {return hypot(x,y);}  // 点到原点的距离
    DB len2() {return x*x+y*y;}  // 点到原点的距离的平方
    DB dist(const P &p) {return hypot(x-p.x,y-p.y);}  // 两点距离

    P rotleft() {return P(-y,x);}  // 绕原点逆时针旋转 90 度
    P rotright() {return P(y,-x);}  // 绕原点顺时针旋转 90 度
    P rotate(const P &p,const DB &angle) {  // 绕 P 点逆时针旋转 angle 度
        P v=*this-p;
        DB c=cos(angle),s=sin(angle);
        return P(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }
}p[N],o;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        int n;cin>>n;
        for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
        cin>>o.x>>o.y;
        p[n+1]=p[1];
        p[0]=p[n];
        DB res=0;
        for(int i=1;i<=n;i++) {
            DB d=p[i].rad(p[i-1],p[i+1]);
            DB r=o.dist(p[i]);
            res+=(PI-d)*r;
        }
        cout<<"Case #"<<cs<<": "<<fixed<<setprecision(3)<<res<<'\n';
    }
    return 0;
}