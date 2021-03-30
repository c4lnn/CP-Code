#include<cstdio>
#include<cmath>
using namespace std;

const double eps=1e-8;
const double PI=3.1415926535;

int sgn(double x) {return fabs(x)<eps?0:(x>0?1:-1);}
struct P {
    double x,y;
    P(){}
    P(double x,double y):x(x),y(y){}

    bool operator == (const P &a) const {return !sgn(x-a.x)&&!sgn(y-a.y);}  
    bool operator < (const P &a) const {return sgn(x-a.x)<0||sgn(x-a.x)==0&&sgn(y-a.y)<0;}  
    
    P operator + (const P &a) const {return P(x+a.x,y+a.y);}
    P operator - (const P &a) const {return P(x-a.x,y-a.y);}
    P operator * (const double &k) const {return P(x*k,y*k);}
    P operator / (const double &k) const {return P(x/k,y/k);}

    double operator * (const P &a) const {return x*a.x+y*a.y;}  //点积
    double operator ^ (const P &a) const {return x*a.y-y*a.x;}  //叉积

    double rad(P a,P b) {return fabs(atan2(fabs((a-*this)^(b-*this)),(a-*this)*(b-*this)));} //这个点与 a，b 所成的夹角
    double len() {return hypot(x,y);}  //点到原点的距离
    double len2() {return x*x+y*y;}  //点到原点的距离的平方
    double dist(P p) {return hypot(x-p.x,y-p.y);}  //两点距离
    
    P rotleft() {return P(-y,x);}  //绕原点逆时针旋转 90 度
    P rotright() {return P(y,-x);}  //绕原点顺时针旋转 90 度
    P rotate(P p,double angle) {  //绕 P 点逆时针旋转 angle 度
        P v=*this-p;
        double c=cos(angle),s=sin(angle);
        return P(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }
};

struct L {
    P s,t;
    L(){}
    L(P s,P t):s(s),t(t){}
    
    bool operator == (const L &a) const {return s==a.s&&t==a.t;}

    int relation(P p) {  // 1 点在左侧，2在右侧，3在直线上
        int c=sgn((p-s)^(t-s));
        if(c<0) return 1;
        else if(c>0) return 2;
        else return 3;
    }
    bool parallel(const L &a) {return sgn((t-s)^(a.t-a.s))==0;} //平行

    P cross_point(L a) { //两直线交点 需保证不平行不重合
        double t1=(t-s)^(a.t-a.s);
        double t2=(t-a.t)^(a.t-a.s);
        double l=(t1==0?0:t2/t1);
        return P(t.x-(t.x-s.x)*l,t.y-(t.y-s.y)*l);
    }
};
double a[10];
int main() {
    int T;
    scanf("%d",&T);
    puts("INTERSECTING LINES OUTPUT");
    while(T--) {
        for(int i=1;i<=8;i++) scanf("%lf",&a[i]);
        L u=L(P(a[1],a[2]),P(a[3],a[4]));
        L v=L(P(a[5],a[6]),P(a[7],a[8]));
        if(u.parallel(v)) {
            if(u.relation(v.s)==3) puts("LINE");
            else puts("NONE");
        }
        else {
            P res=u.cross_point(v);
            printf("POINT %.2f %.2f\n",res.x,res.y);
        }
    }
    puts("END OF OUTPUT");
    return 0;
}