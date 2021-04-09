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
LL exgcd(LL a,LL b,LL &x,LL &y) {
    if(!b) {x=1,y=0;return a;}
    LL ret=exgcd(b,a%b,x,y);
    LL z=x;
    x=y,y=z-(a/b*y);
    return ret;
}
LL solve() {
    LL a,b,c,l1,r1,l2,r2;
    scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&l1,&r1,&l2,&r2);
    if(!a&&!b) {
        if(!c) return (r1-l1+1)*(r2-l2+1);
        return 0;
    }
    else if(!a) {
        if(!c) {
            if(l2<=0&&r2>=0) return r1-l1+1;
            return 0;
        }
        else {
            if(c%b==0&&c/b>=l2&&c/b<=r2) return r1-l1+1;
            return 0;
        }
    }
    else if(!b) {
        if(!c) {
            if(l1<=0&&r1>=0) return r2-l2+1;
            return 0;
        }
        else {
            if(c%a==0&&c/a>=l1&&c/a<=r1) return r2-l2+1;
            return 0;
        }
    }
    else {
        if(a>0) c=-c;
        else a=-a,b=-b;
        LL x,y;
        LL t=abs(exgcd(a,b,x,y));
        if(c%t) return 0;
        x=x*c/t;
        LL tb=b/t,ta=a/t;
        LL l,r;
        if(a>0&&b>0) {
            x+=tb*(LL)ceil(1.0*(l1-x)/tb);
            y=(c-a*x)/b;
            if(y<l2) return 0;
            if(y>r2) {
                LL k=(LL)ceil(1.0*(y-r2)/ta);
                y-=k*ta;
                x+=k*tb;
                if(x>r1) return 0;
            }
            l=x;
            x+=(r1-x)/tb*tb;
            y=(c-a*x)/b;
            if(y>r2) return 0;
            if(y<l2) {
                LL k=(LL)ceil(1.0*(l2-y)/ta);
                y+=k*ta;
                x-=k*tb;
                if(x<l1) return 0;
            }
            r=x;
        }
        else {
            x+=(l1-x)/tb*tb;
            y=(c-a*x)/b;
            if(y>r2) return 0;
            if(y<l2) {
                LL k=(LL)ceil(1.0*(l2-y)/ta);
                y+=k*ta;
                x-=k*tb;
                if(x>r1) return 0;
            }
            l=x;
            x+=tb*(LL)ceil(1.0*(r1-x)/tb);
            y=(c-a*x)/b;
            if(y<l2) return 0;
            if(y>r2) {
                LL k=(LL)ceil(1.0*(y-r2)/ta);
                y-=k*ta;
                x+=k*tb;
                if(x<l1) return 0;
            }
            r=x;
        }
        return abs((r-l)/tb)+1;
    }
    return 0;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    printf("%lld\n",solve());
    return 0;
}