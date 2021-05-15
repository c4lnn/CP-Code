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
const int N=1e5+5;
int x[N],rt,ch[N<<1][2],sz[N<<1],fa[N<<1],id[N*1000];
PII val[N<<1];
char o[N][8];
bool get(int x) {return x==ch[fa[x]][1];}
void clear(int x) {ch[x][0]=ch[x][1]=fa[x]=sz[x]=0;}
void push_up(int x) {sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+val[x].SE;}
void build(int l,int r,int f) {
    if(l>r) return;
    int mid=l+r>>1;
    ch[mid][0]=ch[mid][1]=0;
    if(f==-1) rt=mid,fa[rt]=0;
    else fa[mid]=f,ch[f][r>f]=mid;
    build(l,mid-1,mid);
    build(mid+1,r,mid);
    push_up(mid);
}
void rotate(int x) {
    int y=fa[x],z=fa[y],chk=get(x);
    ch[y][chk]=ch[x][chk^1];
    if(ch[x][chk^1]) fa[ch[x][chk^1]]=y;
    ch[x][chk^1]=y;
    fa[y]=x,fa[x]=z;
    if(z) ch[z][y==ch[z][1]]=x;
    push_up(y);
}
void splay(int x) {
    for(int f=fa[x];f=fa[x],f;rotate(x)) if(fa[f])
        rotate(get(x)==get(f)?f:x);
    push_up(x);
    rt=x;
}
int kth(int k) {
    int cur=rt;
    for(;;) {
        if(ch[cur][0]&&k<=sz[ch[cur][0]]) cur=ch[cur][0];
        else {
            k-=val[cur].SE+sz[ch[cur][0]];
            if(k<=0) break;
            cur=ch[cur][1];
        }
    }
    splay(cur);
    return k+val[rt].SE+val[rt].FI-1;
}
int pre() {
    int cur=ch[rt][0];
    while(ch[cur][1]) cur=ch[cur][1];
    splay(cur);
    return cur;
}
void del() {
    if(!ch[rt][0]||!ch[rt][1]) {
        int cur=rt;
        fa[rt=ch[rt][0]+ch[rt][1]]=0;
        clear(cur);
        return;
    }
    else {
        int cur=rt;
        int x=pre();
        fa[ch[cur][1]]=x;
        ch[x][1]=ch[cur][1];
        clear(cur);
        push_up(rt);
    }
}
void top(int x) {
    if(sz[rt]==1) return;
    splay(x);
    del();
    int t=rt;
    while(ch[t][0]) t=ch[t][0];
    ch[t][0]=x;
    fa[x]=t;
    push_up(x);
    push_up(t);
    splay(x);
}
int main() {
    int T;scanf("%d",&T);
    for(int cs=1;cs<=T;cs++) {
        printf("Case %d:\n",cs);
        int n,q;scanf("%d%d",&n,&q);
        VI a;
        for(int i=1;i<=q;i++) {
            scanf("%s%d",o[i],&x[i]);
            if(o[i][0]!='R') a.PB(x[i]);
        }
        sort(ALL(a));
        a.resize(unique(ALL(a))-a.begin());
        int pre=1,cnt=0;
        for(int i=0;i<SZ(a);i++) {
            if(a[i]-pre) val[++cnt]=MP(pre,a[i]-pre);
            val[++cnt]=MP(a[i],1),id[a[i]]=cnt;
            pre=a[i]+1;
        }
        if(pre<=n) val[++cnt]=MP(pre,n-pre+1);
        build(1,cnt,-1);
        for(int i=1;i<=q;i++) {
            if(o[i][0]=='T') top(id[x[i]]);
            else if(o[i][0]=='Q') {
                splay(id[x[i]]);
                printf("%d\n",sz[ch[rt][0]]+1);
            }
            else printf("%d\n",kth(x[i]));
        }
    }
    return 0;
}