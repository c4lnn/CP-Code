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
const LL MOD=1e6;
const int N=8e4+5;
LL res;
struct Splay {
    int rt,cnt,ch[N][2],fa[N],sz[N],val[N],tot[N];
    void clear(int x) {ch[x][0]=ch[x][1]=sz[x]=val[x]=fa[x]=tot[x]=0;}
    bool get(int x) {return x==ch[fa[x]][1];}
    void push_up(int x) {sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+tot[x];}
    void rotate(int x) {
        int y=fa[x],z=fa[y],chk=get(x);
        ch[y][chk]=ch[x][chk^1];
        if(ch[x][chk^1]) fa[ch[x][chk^1]]=y;
        ch[x][chk^1]=y;
        fa[y]=x,fa[x]=z;
        if(z) ch[z][ch[z][1]==y]=x;
        push_up(y);
    }
    void splay(int x) {
        for(int f=fa[x];f=fa[x],f;rotate(x)) if(fa[f])
            rotate(get(f)==get(x)?f:x);
        push_up(x);
        rt=x;
    }
    void insert(int x) {
        if(!rt) {
            val[++cnt]=x;
            sz[cnt]=tot[cnt]=1;
            rt=cnt;
        }
        else {
            int cur=rt,f=0;
            for(;;) {
                if(val[cur]==x) {
                    ++tot[cur];
                    push_up(cur);push_up(f);
                    splay(cur);
                    break;
                }
                f=cur;
                cur=ch[cur][val[cur]<x];
                if(!cur) {
                    val[++cnt]=x;
                    ++tot[cnt];
                    fa[cnt]=f;
                    ch[f][val[f]<x]=cnt;
                    push_up(cnt),push_up(f);
                    splay(cnt);
                    break;
                }
            }
        }
    }
    void del() {
        if(!ch[rt][0]||!ch[rt][1]) {
            int cur=rt;
            fa[rt=ch[rt][0]+ch[rt][1]]=0;
            clear(cur);
        }
        else {
            int cur=rt;
            int x=ch[cur][0];
            while(ch[x][1]) x=ch[x][1];
            splay(x);
            fa[ch[cur][1]]=x;
            ch[x][1]=ch[cur][1];
            clear(cur);
            push_up(rt);
        }
    }
    bool solve(int x) {
        if(!rt) return false;
        insert(x);
        if(tot[rt]==2) {
            del();
            return true;
        }
        int t1=ch[rt][0];
        while(ch[t1][1]) t1=ch[t1][1];
        int t2=ch[rt][1];
        while(ch[t2][0]) t2=ch[t2][0];
        if(t1&&t2&&abs(val[t1]-x)<=abs(val[t2]-x)||t1&&!t2) {
            res=(res+abs(x-val[t1]))%MOD;
            del();
            splay(t1);
            del();
        }
        else {
            res=(res+abs(x-val[t2]))%MOD;
            del();
            splay(t2);
            del();
        }
        return true;
    }
}s1,s2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int a,b;cin>>a>>b;
        if(a&&!s1.solve(b)) s2.insert(b);
        else if(!a&&!s2.solve(b)) s1.insert(b);
    }
    cout<<res<<'\n';
    return 0;
}