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
template<typename T>
bool read(T &t){
    static char ch;
    int f=1;
    while(ch!=EOF&&!isdigit(ch)) {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    if(ch==EOF) return false;
    for(t=0;isdigit(ch);ch=getchar()) t=t*10+ch-'0';
    t*=f;
    return true;
}
template<typename T>
void print(T t) {
    static int stk[70],top;
    if(t==0) {putchar('0');return;}
    if(t<0) {t=-t;putchar('-');}
    while(t) stk[++top]=t%10,t/=10;
    while(top) putchar(stk[top--]+'0');
}
const int N=1e5+5;
int ls[N<<2],rs[N<<2];
LL sum[N<<2],laz[N<<2];
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r,laz[p]=-1;
    if(l==r) {sum[p]=1e11;return;}
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    sum[p]=sum[p<<1]+sum[p<<1|1];
}
void push_down(int p) {
    if(laz[p]!=-1) {
        sum[p<<1]=laz[p]*(rs[p<<1]-ls[p<<1]+1);
        sum[p<<1|1]=laz[p]*(rs[p<<1|1]-ls[p<<1|1]+1);
        laz[p<<1]=laz[p<<1|1]=laz[p];
        laz[p]=-1;
    }
}
void update(int p,int l,int r,int v) {
    if(ls[p]>=l&&rs[p]<=r) {
        sum[p]=v*(rs[p]-ls[p]+1);
        laz[p]=v;
        return;
    }
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,v);
    if(r>mid) update(p<<1|1,l,r,v);
    sum[p]=sum[p<<1]+sum[p<<1|1];
}
struct R {
    int l,r,v;
    bool operator < (const R &T) const {
        return v>T.v;
    }
}a[N];
int main() {
    int T;read(T);
    for(int cs=1;cs<=T;cs++) {
        int n,m;read(n),read(m);
        printf("Case #%d: ",cs);
        if(n==1) putchar('0');
        else {
            for(int i=1;i<=m;i++) read(a[i].l),read(a[i].r),read(a[i].v);
            build(1,1,n-1);
            sort(a+1,a+1+m);
            LL res=0;
            for(int i=1;i<=m;i++) {
                update(1,a[i].l,a[i].r-1,a[i].v);
                res+=1ll*(a[i].r-a[i].l+1)*(a[i].r-a[i].l)/2*a[i].v;
            }
            if(sum[1]>=1e11) printf("Gotta prepare a lesson");
            else print(res-sum[1]);
        }
        if(cs<T) putchar('\n');
    }
    return 0;
}