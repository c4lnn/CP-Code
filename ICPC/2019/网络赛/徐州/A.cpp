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
map<LL,bool> mp;
LL f[1000],a[15],m[15];
LL qmul(LL a,LL b,LL m) {
    LL ret=0;
    while(b) {
        if(b&1) ret=(ret+a)%m;
        a=(a+a)%m;
        b>>=1;
    }
    return ret;
}
LL exgcd(LL a,LL b,LL &x,LL &y) {
    if(!b) {x=1,y=0;return a;}
    LL ret=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return ret;
}
LL excrt(LL *m,LL *a,int n) {
    if(!n) return 0;
    LL M=m[1],A=a[1],x,y;
    for(int i=2;i<=n;i++) {
        LL d=exgcd(M,m[i],x,y);
        LL c=(a[i]-A%m[i]+m[i])%m[i];
        if(c%d) return -1;
        x=qmul(x,c/d,m[i]/d);
        A+=M*x;
        M*=m[i]/d;
        A%=M;
    }
    return (A%M+M)%M;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>m[i]>>a[i];
    LL ret=excrt(m,a,n);
    if(ret==-1||ret<=1) cout<<"Tankernb!"<<'\n';
    else {
        f[1]=f[2]=1;
        for(int i=3;;i++) {
            f[i]=f[i-1]+f[i-2];
            if(f[i]==ret) return cout<<"Lbnb!"<<'\n',0;
            else if(f[i]>ret) return cout<<"Zgxnb!"<<'\n',0;
        }
    }
    return 0;
}