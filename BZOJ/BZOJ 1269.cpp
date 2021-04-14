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
const int N=2100000;
int rt,cnt,fa[N],sz[N],ch[N][2],mark[N],val[N];
char s[N];
void clear(int x) {ch[x][0]=ch[x][1]=val[x]=fa[x]=sz[x]=0;}
bool get(int x) {return x==ch[fa[x]][1];}
void push_up(int x) {sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;}
void push_down(int x) {
    if(mark[x]) {
        mark[ch[x][0]]^=1;
        mark[ch[x][1]]^=1;
        mark[x]=0;
        swap(ch[x][0],ch[x][1]);
    }
}
int build(int l,int r,int f) {
    if(l>r) return 0;
    int mid=l+r>>1;
    val[++cnt]=s[mid];
    int cur=cnt;
    if(f==-1) rt=cur,fa[cur]=0;
    else fa[cur]=f;
    ch[cur][0]=build(l,mid-1,cur);
    ch[cur][1]=build(mid+1,r,cur);
    push_up(cur);
    return cur;
}
void rotate(int x) {
    int y=fa[x],z=fa[y];
    push_down(y);
    push_down(x);
    int chk=get(x);
    ch[y][chk]=ch[x][chk^1];
    if(ch[y][chk]) fa[ch[y][chk]]=y;
    ch[x][chk^1]=y;
    fa[y]=x,fa[x]=z;
    if(z) ch[z][y==ch[z][1]]=x;
    push_up(y);
}
void splay(int x,int t) {
    push_down(x);
    for(int f=fa[x];f=fa[x],f!=t;rotate(x)) if(fa[f]!=t)
        rotate(get(f)==get(x)?f:x);
    push_up(x);
    if(!t) rt=x;
}
void insert(int n) {
    int cur=ch[rt][1];
    push_down(cur);
    while(ch[cur][0]) cur=ch[cur][0],push_down(cur);
    splay(cur,rt);
    ch[cur][0]=build(0,n-1,cur);
    push_up(cur);
    push_up(rt);
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
    return cur;
}
void move(int n) {
    int r=kth(n+1);
    splay(r,0);
}
void del(int n) {
    push_up(rt);
    int r=kth(sz[ch[rt][0]]+1+n+1);
    splay(r,rt);
    ch[r][0]=0;
    push_up(r);
    push_up(rt);
}
void rev(int n) {
    int r=kth(sz[ch[rt][0]]+1+n+1);
    splay(r,rt);
    mark[ch[r][0]]^=1;
}
void get() {
    int cur=ch[rt][1];
    push_down(cur);
    while(ch[cur][0]) cur=ch[cur][0],push_down(cur);
    if(val[cur]!='\n') putchar(val[cur]);
    putchar('\n');
}
void prev() {
    int cur=ch[rt][0];
    push_down(cur);
    while(ch[cur][1]) cur=ch[cur][1],push_down(cur);
    splay(cur,0);
}
void next() {
    int cur=ch[rt][1];
    push_down(cur);
    while(ch[cur][0]) cur=ch[cur][0],push_down(cur);
    splay(cur,0);
}
int main() {
    int n;scanf("%d",&n);
    cnt=4;
    sz[1]=4;sz[2]=3;sz[3]=1;sz[4]=1;
    fa[2]=1;fa[3]=2;fa[4]=2;
    ch[1][1]=2;ch[2][0]=3;ch[2][1]=4;
    rt=1;
    char o[15];
    while(~scanf("%s",o)) {
        if(o[0]=='I') {
            int x;scanf("%d",&x);getchar();
            for(int j=0;j<x;j++) s[j]=getchar();
            insert(x);
        }
        else if(o[0]=='M') {
            int x;scanf("%d",&x);
            move(x);
        }
        else if(o[0]=='D') {
            int x;scanf("%d",&x);
            del(x);
        }
        else if(o[0]=='R') {
            int x;scanf("%d",&x);
            rev(x);
        }
        else if(o[0]=='G') get();
        else if(o[0]=='P') prev();
        else next();
    }
    return 0;
}