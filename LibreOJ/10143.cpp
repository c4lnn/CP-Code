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
const int N=4e4+5;
int rt,cnt,ch[N][2],tot[N],val[N],sz[N],fa[N];
LL res;
void clear(int x) {ch[x][0]=ch[x][1]=sz[x]=tot[x]=val[x]=fa[x]=0;}
int get(int x) {return x==ch[fa[x]][1];}
void push_up(int x) {sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+tot[x];}
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
void insert(int x) {
    if(!rt) {
        val[++cnt]=x;
        ++tot[cnt];
        rt=cnt;
        push_up(rt);
        return;
    }
    int cur=rt,f=0;
    for(;;) {
        if(val[cur]==x) {
            ++tot[cur];
            push_up(cur),push_up(f);
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
void solve(int i,int x) {
    insert(x);
    if(tot[rt]>1) {return;}
    int t1=ch[rt][0];
    while(ch[t1][1]) t1=ch[t1][1];
    int t2=ch[rt][1];
    while(ch[t2][0]) t2=ch[t2][0];
    if(t1&&t2) res+=min(abs(x-val[t1]),abs(x-val[t2]));
    else if(t1) res+=abs(x-val[t1]);
    else res+=abs(x-val[t2]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        if(i==1) res+=x,insert(x);
        else solve(i,x);
    }
    cout<<res<<'\n';
    return 0;
}