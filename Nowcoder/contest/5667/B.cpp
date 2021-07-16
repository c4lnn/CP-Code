#include<bits/stdc++.h>
using namespace std;
const int N=2005;
const double eps=5e-7;
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
    double operator ^ (const P &a) const {return x*a.y-y*a.x;}  //叉积
    P rotleft() {return P(-y,x);}  //绕原点逆时针旋转 90 度
}a[N],ps[N*N];
struct L {
    P s,t;
    L(){}
    L(P s,P t):s(s),t(t){}
    bool parallel(const L &a) {return sgn((t-s)^(a.t-a.s))==0;} //平行
    P cross_point(L a) { //两直线交点 需保证不平行不重合
        double t1=(t-s)^(a.t-a.s);
        double t2=(t-a.t)^(a.t-a.s);
        double l=(t1==0?0:t2/t1);
        P dd=P(t.x-(t.x-s.x)*l,t.y-(t.y-s.y)*l);
        return dd;
    }
};
P compute_circle_center(P a,P b,P c) {
    if(L(a,b).parallel(L(a,c))) return P(1e18,1e18);
    L u=L((a+b)/2,(a+b)/2+(b-a).rotleft());
    L v=L((a+c)/2,(a+c)/2+(c-a).rotleft());
    return u.cross_point(v);
}
int n,res,cnt;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lf%lf",&a[i].x,&a[i].y);
        for(int j=1;j<i;j++) {
            P t=compute_circle_center(P(0,0),a[i],a[j]);
            if(t.x==t.y&&fabs(t.x-1e18)<eps) continue;
            ps[++cnt]=t;
        }
    }
    if(cnt==0) res=1;
    else {
        sort(ps+1,ps+1+cnt);
        P pre=ps[1];
        int tot=1,mx=1;
        for(int i=2;i<=cnt;i++) {
            if(ps[i]==ps[i-1]) tot++,mx=max(mx,tot);
            else tot=1,pre=ps[i];
        }
        for(int i=n;i>=1;i--) if(i*(i-1)/2==mx) {res=i;break;}
    }
    printf("%d\n",res);
    return 0;
}