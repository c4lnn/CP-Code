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
const int N=3e5+5;
int n,m;
VI res;
struct Splay {
    int rt,ch[N][2],sz[N],fa[N],mark[N];
    bool get(int x) {return x==ch[fa[x]][1];}
    void clear(int x) {ch[x][0]=ch[x][1]=fa[x]=sz[x]=mark[x]=0;}
    void push_up(int x) {sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;}
    void push_down(int x) {
        if(mark[x]) {
            mark[ch[x][0]]^=1;
            mark[ch[x][1]]^=1;
            mark[x]=0;
            swap(ch[x][0],ch[x][1]);
        }
    }
    void build(int l,int r,int f) {
        int mid=l+r>>1;
        ch[mid][0]=ch[mid][1]=0;
        if(f==-1) fa[mid]=0,rt=mid;
        else fa[mid]=f,ch[f][r>f]=mid;
        if(l<mid) build(l,mid-1,mid);
        if(r>mid) build(mid+1,r,mid);
        push_up(mid);
    }
    void rotate(int x) {
        int y=fa[x],z=fa[y];
        push_down(y);
        push_down(x);
        int chk=get(x);
        ch[y][chk]=ch[x][chk^1];
        if(ch[x][chk^1]) fa[ch[x][chk^1]]=y;
        ch[x][chk^1]=y;
        fa[y]=x,fa[x]=z;
        if(z) ch[z][y==ch[z][1]]=x;
        push_up(y);
    }
    void splay(int x,int t) {
        push_down(x);
        for(int f=fa[x];f=fa[x],f!=t;rotate(x)) if(fa[f]!=t)
            rotate(get(x)==get(f)?f:x);
        push_up(x);
        if(!t) rt=x;
    }
    int kth(int k) {
        int cur=rt;
        for(;;) {
            push_down(cur);
            if(ch[cur][0]&&k<=sz[ch[cur][0]]) cur=ch[cur][0];
            else {
                k-=1+sz[ch[cur][0]];
                if(k<=0) break;
                cur=ch[cur][1];
            }
        }
        splay(cur,0);
        return cur;
    }
    int get_max(int x){
        push_down(x);
        while(ch[x][1]){
            x=ch[x][1];
            push_down(x);
        }
        return x;
    }
    void cut(int l,int r,int k) {
        l=kth(l);
        r=kth(r+2);
        splay(l,0);
        splay(r,l);
        int t=ch[ch[rt][1]][0];
        ch[ch[rt][1]][0]=0;
        fa[t]=0;
        push_up(ch[rt][1]);
        push_up(rt);
        splay(kth(k),0);
        int tt=ch[rt][1];
        ch[rt][1]=t;
        fa[t]=rt;
        push_up(rt);
        splay(get_max(rt),0);
        ch[rt][1]=tt;
        fa[tt]=rt;
        push_up(rt);
    }
    void reverse(int l,int r) {
        l=kth(l);
        r=kth(r+2);
        splay(l,0);
        splay(r,l);
        mark[ch[ch[rt][1]][0]]^=1;
    }
    void print(int u) {
        if(u) {
            push_down(u);
            print(ch[u][0]);
            if(u>1&&u<n+2) res.PB(u-1);
            print(ch[u][1]);
        }
    }
}splay;
int main() {
    while(scanf("%d%d",&n,&m)) {
        if(n<0&&m<0) break;
        splay.build(1,n+2,-1);
        for(int i=1;i<=m;i++) {
            char s[5];
            scanf("%s",s);
            if(s[0]=='C') {
                int a,b,c;
                scanf("%d%d%d",&a,&b,&c);
                splay.cut(a,b,c+1);
            }
            else {
                int a,b;
                scanf("%d%d",&a,&b);
                splay.reverse(a,b);
            }
        }
        res.clear();
        splay.print(splay.rt);
        for(int i=0;i<n;i++) printf("%d%c",res[i],i==n-1?'\n':' ');
    }
    return 0;
}