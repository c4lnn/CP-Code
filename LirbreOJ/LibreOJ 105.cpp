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
int n,m;
struct Splay {
    int rt,cnt,ch[N][2],sz[N],val[N],fa[N],mark[N];
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
    void insert(int x) {
        val[++cnt]=x;
        if(!rt) {
            rt=cnt;
            push_up(rt);
            return;
        }
        int cur=rt,f=0;
        for(;;) {
            f=cur;
            cur=ch[cur][val[cur]<x];
            if(!cur) {
                fa[cnt]=f;
                ch[f][val[f]<x]=cnt;
                push_up(cnt),push_up(f);
                splay(cnt,0);
                break;
            }
        }
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
            if(val[u]>1&&val[u]<n+2) cout<<val[u]-1<<' ';
            print(ch[u][1]);
        }
    }
}splay;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n+2;i++) splay.insert(i);
    for(int i=1;i<=m;i++) {
        int l,r;
        cin>>l>>r;
        splay.reverse(l,r);
    }
    splay.print(splay.rt);
    cout<<'\n';
    return 0;
}