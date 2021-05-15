#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
const int N=20005;
int n;
VI b;
struct R {
    int x,y1,y2,w;
    R() {}
    R(int x,int y1,int y2,int w):x(x),y1(y1),y2(y2),w(w) {}
    bool operator < (const R &a) const {
        return x<a.x;
    }
};
vector<R> a;
struct Seg {
    int l,r,ls,rs,cover,cnt,len;
    #define l(x) tr[x].l
    #define r(x) tr[x].r
    #define ls(x) tr[x].ls
    #define rs(x) tr[x].rs
    #define cover(x) tr[x].cover
    #define cnt(x) tr[x].cnt
    #define len(x) tr[x].len
}tr[N<<2];
void build(int p,int l,int r) {
    l(p)=l,r(p)=r;
    if(l==r) return;
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
void push_up(int p) {
    if(cover(p)) {
        ls(p)=rs(p)=cnt(p)=1;
        len(p)=b[r(p)]-b[l(p)-1];
    }
    else if(l(p)==r(p)) {
        cnt(p)=len(p)=ls(p)=rs(p)=0;
    }
    else {
        cnt(p)=cnt(p<<1)+cnt(p<<1|1);
        len(p)=len(p<<1)+len(p<<1|1);
        ls(p)=ls(p<<1),rs(p)=rs(p<<1|1);
        if(rs(p<<1)&&ls(p<<1|1)) cnt(p)--;
    }
}
void update(int p,int l,int r,int w) {
    if(l(p)>=l&&r(p)<=r) {
        cover(p)+=w;
        push_up(p);
        return;
    }
    int mid=l(p)+r(p)>>1;
    if(l<=mid) update(p<<1,l,r,w);
    if(r>mid) update(p<<1|1,l,r,w);
    push_up(p);
}
int getID(int x) {
    return lower_bound(ALL(b),x)-b.begin()+1;
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        a.PB(R(x1,y1,y2,1));
        a.PB(R(x2,y1,y2,-1));
        b.PB(y1),b.PB(y2);
    }
    sort(ALL(b));
    b.resize(unique(ALL(b))-b.begin());
    sort(ALL(a));
    build(1,1,SZ(b)-1);
    int res=0;
    for(int i=0;i<SZ(a);i++) {
        int t=len(1);
        if(i) res+=cnt(1)*2*(a[i].x-a[i-1].x);
        update(1,getID(a[i].y1),getID(a[i].y2)-1,a[i].w);
        res+=abs(len(1)-t);
    }
    printf("%d\n",res);
    return 0;
}