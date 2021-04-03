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
int n;
PII a[N];
struct Splay {
    int rt,ch[N][2],sz[N],fa[N],mark[N];
    PII val[N];
    bool get(int x) {return x==ch[fa[x]][1];}
    void clear(int x) {ch[x][0]=ch[x][1]=fa[x]=mark[x]=sz[x]=0;}
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
        val[mid]=a[mid];
        if(f==-1) rt=mid;
        else fa[mid]=f,ch[f][r>f]=mid,ch[mid][0]=ch[mid][1]=0;
        if(l<mid) build(l,mid-1,mid);
        if(r>mid) build(mid+1,r,mid);
        push_up(mid);
    }
    void rotate(int x) {
        int y=fa[x],z=fa[y];
        push_down(z);
        push_down(y);
        push_down(x);
        int chk=get(x);
        ch[y][chk]=ch[x][chk^1];
        if(ch[x][chk^1]) fa[ch[x][chk^1]]=y;
        ch[x][chk^1]=y;
        fa[y]=x,fa[x]=z;
        if(z) ch[z][y==ch[z][1]]=x;
        push_up(y);
        push_up(x);
    }
    void splay(int x) {
        push_down(x);
        for(int f=fa[x];f=fa[x],f;rotate(x)) {
            if(fa[f]) {
                push_down(fa[f]);
                push_down(f);
                push_down(x);
                rotate(get(x)==get(f)?f:x);
            }
            else {
                push_down(f);
                push_down(x);
            }
        }
        rt=x;
    }
    int pre() {
        int cur=ch[rt][0];
        push_down(cur);
        while(ch[cur][1]) cur=ch[cur][1],push_down(cur);
        splay(cur);
        return cur;
    }
    void del(int x) {
        if(!ch[rt][0]&&!ch[rt][1]) {
            clear(rt);
            rt=0;
            return;
        }
        else if(!ch[rt][0]) {
            int cur=rt;
            rt=ch[rt][1];
            fa[rt]=0;
            clear(cur);
        }
        else if(!ch[rt][1]) {
            int cur=rt;
            rt=ch[rt][0];
            fa[rt]=0;
            clear(cur);
        }
        else {
            int cur=rt;
            x=pre();
            fa[ch[cur][1]]=x;
            ch[x][1]=ch[cur][1];
            clear(cur);
            push_up(rt);
        }
    }
    void reverse(int x,int t) {
        splay(x);
        mark[ch[rt][0]]^=1;
        printf("%d%c",sz[ch[rt][0]]+t,t==n?'\n':' ');
        del(rt);
    }
}splay;
bool cmp(PII a,PII b) {
    return a.SE<b.SE||a.SE==b.SE&&a.FI<b.FI;
}
int main() {
    while(~scanf("%d",&n)&&n) {
        for(int i=1;i<=n;i++) {
            int x;
            cin>>x;
            a[i]=MP(i,x);
        }
        splay.build(1,n,-1);
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++) splay.reverse(a[i].FI,i);
    }
    return 0;
}