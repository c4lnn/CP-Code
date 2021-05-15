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
const int N=5e4+5;
int n,m,ls[N<<2],rs[N<<2],lsum[N<<2],rsum[N<<2];
stack<int> stk;
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {lsum[p]=rsum[p]=1;return;}
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    lsum[p]=rsum[p]=rs[p]-ls[p]+1;
}
void update(int p,int x,int v) {
    if(ls[p]==rs[p]&&x==ls[p]) {
        lsum[p]=rsum[p]=v;
        return;
    }
    int mid=ls[p]+rs[p]>>1;
    if(x<=mid) update(p<<1,x,v);
    else update(p<<1|1,x,v);
    lsum[p]=(lsum[p<<1]==rs[p<<1]-ls[p<<1]+1?lsum[p<<1]+lsum[p<<1|1]:lsum[p<<1]);
    rsum[p]=(rsum[p<<1|1]==rs[p<<1|1]-ls[p<<1|1]+1?rsum[p<<1|1]+rsum[p<<1]:rsum[p<<1|1]);
}
int query1(int p,int l,int r) {
    if(ls[p]>=l&&rs[p]<=r) return rsum[p];
    int mid=ls[p]+rs[p]>>1;
    if(r<=mid) return query1(p<<1,l,r);
    if(l>mid) return query1(p<<1|1,l,r);
    int t=query1(p<<1|1,mid+1,r);
    return t==r-mid?t+query1(p<<1,l,mid):t;
}
int query2(int p,int l,int r) {
    if(ls[p]>=l&&rs[p]<=r) return lsum[p];
    int mid=ls[p]+rs[p]>>1;
    if(r<=mid) return query2(p<<1,l,r);
    if(l>mid) return query2(p<<1|1,l,r);
    int t=query2(p<<1,l,mid);
    return t==mid-l+1?t+query2(p<<1|1,mid+1,r):t;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        while(SZ(stk)) stk.pop();
        build(1,1,n);
        for(int i=1;i<=m;i++) {
            char c;
            scanf(" %c",&c);
            if(c=='D') {
                int x;
                scanf("%d",&x);
                update(1,x,0);
                stk.push(x);
            }
            else if(c=='Q') {
                int x;
                scanf("%d",&x);
                int t=query1(1,1,x);
                printf("%d\n",t?(x!=n?t+query2(1,x+1,n):t):0);
            }
            else if(SZ(stk)) update(1,stk.top(),1),stk.pop();
        }
    }
    return 0;
}