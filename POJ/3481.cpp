#include <iostream>
using namespace std;
const int N=1e6+5;
int id[N*10];
struct Splay {
    int rt,cnt,ch[N][2],sz[N],tot[N],val[N],fa[N];
    void maintain(int x) {sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+tot[x];}
    bool get(int x) {return x==ch[fa[x]][1];}
    void clear(int x) {ch[x][0]=ch[x][1]=fa[x]=val[x]=sz[x]=tot[x]=0;}
    void rotate(int x) {
        int y=fa[x],z=fa[y],chk=get(x);
        ch[y][chk]=ch[x][chk^1];
        if(ch[x][chk^1]) fa[ch[x][chk^1]]=y;
        ch[x][chk^1]=y;
        fa[y]=x,fa[x]=z;
        if(z) ch[z][y==ch[z][1]]=x;
        maintain(y);
        maintain(x);
    }
    void splay(int x) {
        for(int f=fa[x];f=fa[x],f;rotate(x)) if(fa[f])
            rotate(get(x)==get(f)?f:x);
        rt=x;
    }
    void insert(int x) {
        if(!rt) {
            val[++cnt]=x;
            ++tot[cnt];
            rt=cnt;
            maintain(rt);
            return;
        }
        int cur=rt,f=0;
        for(;;) {
            if(val[cur]==x) {
                ++tot[cur];
                maintain(cur),maintain(f);
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
                maintain(cnt),maintain(f);
                splay(cnt);
                break;
            }
        }
    }
    int rk(int x) { // 树中存在 x
        int res=0,cur=rt;
        for(;;) {
            if(x<val[cur]) cur=ch[cur][0];
            else {
                res+=sz[ch[cur][0]];
                if(x==val[cur]) break;
                res+=tot[cur];
                cur=ch[cur][1];
            }
        }
        splay(cur);
        return res+1;
    }
    int kth(int k) {
        int cur=rt;
        for(;;) {
            if(ch[cur][0]&&k<=sz[ch[cur][0]]) cur=ch[cur][0];
            else {
                k-=tot[cur]+sz[ch[cur][0]];
                if(k<=0) break;
                cur=ch[cur][1];
            }
        }
        splay(cur);
        return val[cur];
    }
    int pre() {
        int cur=rt;
        while(ch[cur][0]) cur=ch[cur][0];
        splay(cur);
        return cur;
    }
    int nxt() {
        int cur=rt;
        while(ch[cur][1]) cur=ch[cur][1];
        splay(cur);
        return cur;
    }
    void del(int x) {
        rk(x);
        if(tot[rt]>1) {
            --tot[rt];
            maintain(rt);
            return;
        }
        if(!ch[rt][0]&&!ch[rt][1]) {
            clear(rt);
            rt=0;
            return;
        }
        if(!ch[rt][0]) {
            int cur=rt;
            rt=ch[rt][1];
            fa[rt]=0;
            clear(cur);
            return;
        }
        if(!ch[rt][1]) {
            int cur=rt;
            rt=ch[rt][0];
            fa[rt]=0;
            clear(cur);
            return;
        }
        // 合并左右子树，将左子树最大值 Splay 到根，然后把它的右子树设置为右子树并更新节点的信息
        int cur=rt;
        x=pre();
        fa[ch[cur][1]]=x;
        ch[x][1]=ch[cur][1];
        clear(cur);
        maintain(rt);
    }
}splay;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int o;
    while(cin>>o) {
        if(o==0) break;
        else if(o==1) {
            int k,p;
            cin>>k>>p;
            id[p]=k;
            splay.insert(p);
        }
        else if(o==2) {
            cout<<id[splay.val[splay.nxt()]]<<'\n';
            splay.del(splay.val[splay.rt]);
        }
        else if(o==3) {
            cout<<id[splay.val[splay.pre()]]<<'\n';
            splay.del(splay.val[splay.rt]);
        }
    }
    return 0;
}