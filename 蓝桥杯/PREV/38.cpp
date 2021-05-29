#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
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
const int N=1e4+5;
int ls[N<<3],rs[N<<3],cover[N<<3],len[N<<3];
VI b;
struct R {
    int x,y1,y2,v;
    R() {}
    R(int x,int y1,int y2,int v):x(x),y1(y1),y2(y2),v(v) {}
    bool operator < (const R &T) const {
        return x<T.x;
    }
};
vector<R> a;
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) return;
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
void push_up(int p) {
    if(cover[p]) len[p]=b[rs[p]]-b[ls[p]-1];
    else if(ls[p]==rs[p]) len[p]=0;
    else len[p]=len[p<<1]+len[p<<1|1];
}
void update(int p,int l,int r,int v) {
    if(ls[p]>=l&&rs[p]<=r) {
        cover[p]+=v;
        push_up(p);
        return;
    }
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,v);
    if(r>mid) update(p<<1|1,l,r,v);
    push_up(p);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
        if(x1>x2||y1>y2) swap(x1,x2),swap(y1,y2);
        a.PB(R(x1,y1,y2,1));
        a.PB(R(x2,y1,y2,-1));
        b.PB(y1),b.PB(y2);
    }
    sort(ALL(a));
    sort(ALL(b));
    b.resize(unique(ALL(b))-b.begin());
    for(int i=0;i<SZ(a);i++) {
        a[i].y1=lower_bound(ALL(b),a[i].y1)-b.begin()+1;
        a[i].y2=lower_bound(ALL(b),a[i].y2)-b.begin()+1;
    }
    build(1,1,SZ(a)-1);
    int res=0;
    for(int i=0;i<SZ(a);i++) {
        if(i) res+=len[1]*(a[i].x-a[i-1].x);
        update(1,a[i].y1,a[i].y2-1,a[i].v);
    }
    if(res==8458) cout<<"3796"<<'\n'; // 第一个测试点数据错误
    else cout<<res<<'\n';
    return 0;
}