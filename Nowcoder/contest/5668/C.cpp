#include<bits/stdc++.h>
using namespace std;
double eps=1e-5;
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

    int relation(P p) {  // 1在左侧，2在右侧，3在直线上
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
int main() {
    int T;
    scanf("%d",&T);
    P a[25];
    while(T--) {
        for(int i=0;i<20;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
        for(int i=0;i<20;i++) {
            if(fabs(a[i].dist(a[(i+1)%20])-9)<eps) {
                if(fabs(a[(i+1)%20].dist(a[(i+2)%20])-6)<eps) {
                    if(L(a[(i+2)%20],a[i]).relation(a[(i+1)%20])==2) puts("right");
                    else puts("left");
                }
                else {
                    if(L(a[(i-1+20)%20],a[(i+1)%20]).relation(a[i])==2) puts("right");
                    else puts("left");
                }
            }
        }
    }
    return 0;
}