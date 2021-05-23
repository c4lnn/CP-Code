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
const int N=605;
struct bign {
    int len;
    int num[3005];
    bign() {
        len=1;
        memset(num,0,sizeof num);
    }
    bool operator < (const bign &a) const {
        if(len!=a.len) return len<a.len;
        for(int i=len;i>=1;i--) if(num[i]!=a.num[i]) return num[i]<a.num[i];
        return false;
    }
    bool operator > (const bign &a) const {return a<*this;}
    bool operator <= (const bign &a) const {return !(a<*this);}
    bool operator >= (const bign &a) const {return !(*this<a);}
    bool operator != (const bign &a) const {return a<*this||*this<a;}
    bool operator == (const bign &a) const {return !(a<*this)&&!(*this<a);}
}fac[N];
void print(bign a) {
    for(int i=a.len;i;i--) cout<<a.num[i];
    cout<<'\n';
}
bign operator + (bign a,bign b) {
    bign res;
    res.len=max(a.len,b.len);
    int x=0;
    for(int i=1;i<=res.len;i++) {
        res.num[i]=x+a.num[i]+b.num[i];
        x=res.num[i]/10;
        res.num[i]%=10;
    }
    if(x) res.num[++res.len]=x;
    return res;
}
bign operator - (bign a,bign b) { // a > b
    bign res;
    res.len=max(a.len,b.len);
    for(int i=1;i<=res.len;i++) {
        if(a.num[i]<b.num[i]) --a.num[i+1],a.num[i]+=10;
        res.num[i]=a.num[i]-b.num[i];
    }
    while(res.len>1&&res.num[res.len]==0) res.len--;
    return res;
}
bign operator * (bign a,int b) {
    bign res;
    int x=0;
    for(int i=1;i<=a.len;i++) {
        x+=a.num[i]*b;
        res.num[res.len++]=x%10;
        x/=10;
    }
    while(x) {
        res.num[res.len++]=x%10;
        x/=10;
    }
    while(res.len>1&&res.num[res.len]==0) res.len--;
    return res;
}
bign operator * (bign a,bign b) {
    bign res;
    res.len=a.len+b.len;
    for(int i=1;i<=res.len;i++) res.num[i]=0;
    for(int i=1;i<=a.len;i++) {
        int x=0;
        for(int j=1;j<=b.len;j++) {
            res.num[i+j-1]+=a.num[i]*b.num[j]+x;
            x=res.num[i+j-1]/10;
            res.num[i+j-1]%=10;
        }
        res.num[i+b.len]+=x;
    }
    while(res.len>1&&res.num[res.len]==0) res.len--;
    return res;
}
bign operator / (bign a,bign b) {
    bign res,x;
    res.len=a.len;
    for(int i=1;i<=res.len;i++) res.num[i]=0;
    for(int i=a.len;i>=1;i--) {
        x=x*10; // bign * int
        x.num[1]=a.num[i];
        while(x>b||x==b) {
            x=x-b; // bign - bign
            res.num[i]++;
        }
    }
    while(res.len>1&&res.num[res.len]==0) res.len--;
    return res;
}
bign C(int a,int b) {
    return fac[a]/fac[b]/fac[a-b];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,s;cin>>n>>s;
    if(s&1||s>18*n) return cout<<0<<'\n',0;
    s/=2;
    fac[0].num[1]=1;
    for(int i=1;i<=600;i++) fac[i]=fac[i-1]*i;
    bign res=C(s+n-1,n-1);
    for(int i=2;i<=n;i+=2) {
        int a=s+n-10*i-1,b=n-1;
        if(a<b) continue;
        res=res+C(n,i)*C(a,b);
    }
    for(int i=1;i<=n;i+=2) {
        int a=s+n-10*i-1,b=n-1;
        if(a<b) continue;
        res=res-C(n,i)*C(a,b);
    }
    print(res*res);
    return 0;
}