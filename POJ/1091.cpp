#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
struct bign {
    int len;
    int num[1005];
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
};
bign get(int n) {
    bign res;
    while(n) {
        res.num[res.len++]=n%10;
        n/=10;
    }
    if(res.len>1) res.len--;
    return res;
}
void print(bign a) {
    for(int i=a.len;i;i--) cout<<a.num[i];
    cout<<'\n';
}
bool non_zero(bign T) {
    return T.len>1||T.len==1&&T.num[1];
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
bign operator / (bign a,int b) {
    bign res;
    res.len=a.len;
    for(int i=a.len,t=0;i>=1;i--) {
        t=t*10+a.num[i];
        if(t>=b) res.num[i]=t/b,t%=b;
    }
    while(res.len>1&&res.num[res.len]==0) res.len--;
    return res;
}
bign qpow(bign a,bign b) {
    bign ret;
    ret.num[1]=1;
    while(non_zero(b)) {
        if(b.num[1]&1) ret=ret*a;
        a=a*a;
        b=b/2;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    int t=m;
    VI p;
    for(int i=2;i*i<=t;i++) if(t%i==0) {
        while(t%i==0) t/=i;
        p.PB(i);
    }
    if(t>1) p.PB(t);
    bign tt=get(n);
    bign res=qpow(get(m),tt);
    for(int i=1;i<1<<SZ(p);i++) {
        int cnt=0,d=1;
        for(int j=0;j<SZ(p);j++) if(i&(1<<j)) {
            ++cnt;
            d*=p[j];
        }
        if(cnt&1) res=res-qpow(get(((m-1)/d+1)),tt);
        else res=res+qpow(get((m-1)/d+1),tt);
    }
    print(res);
    return 0;
}