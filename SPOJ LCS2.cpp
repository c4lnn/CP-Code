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
//head
const int N=1e5+5; // 单个字符串最大长度
const int M=10; // 字符串个数
int n,sz,string_num,len[N*M*2],nxt[N*M*2][26],link[N*M*2];
bool f[N*M*2][M];
void trie_insert(const string &s) {
    ++string_num;
    n=max(n,SZ(s));
    int rt=0;
    for(auto c:s) {
        int now=c-'a';
        if(!nxt[rt][now]) nxt[rt][now]=++sz;
        rt=nxt[rt][now];
        f[rt][string_num]=true;
    }
}
int gsa_insert(int last,int x) {
    int cur=nxt[last][x],p=link[last];
    len[cur]=len[last]+1;
    while(p!=-1&&!nxt[p][x]) nxt[p][x]=cur,p=link[p];
    if(p==-1) {link[cur]=0;return cur;}
    int q=nxt[p][x];
    if(len[p]+1==len[q]) {link[cur]=q;return cur;}
    int t=++sz;
    len[t]=len[p]+1;
    for(int i=0;i<26;i++) nxt[t][i]=len[nxt[q][i]]!=0?nxt[q][i]:0;
    link[t]=link[q];
    while(p!=-1&&nxt[p][x]==q) nxt[p][x]=t,p=link[p];
    link[q]=link[cur]=t;
    return cur;
}
void gsa_build() {
    link[0]=-1;
    queue<PII> q;
    for(int i=0;i<26;i++) if(nxt[0][i]) q.emplace(0,i);
    while(SZ(q)) {
        auto u=q.front();
        q.pop();
        auto last=gsa_insert(u.FI,u.SE);
        for(int i=0;i<26;i++) if(nxt[last][i]) q.emplace(last,i);
    }
}
int c[N],a[N*M*2];
int gsa_topo() {
    for(int i=1;i<=n;i++) c[i]=0;
    for(int i=1;i<=sz;i++) ++c[len[i]];
    for(int i=1;i<=n;i++) c[i]+=c[i-1];
    for(int i=sz;i>=1;i--) a[c[len[i]]--]=i;
    for(int i=sz;i>=1;i--)
        for(int j=1;j<=string_num;j++)
            f[link[a[i]]][j]|=f[a[i]][j];
    for(int i=sz;i>=1;i--)
        for(int j=1;j<=string_num;j++) {
            if(!f[a[i]][j]) break;
            else if(j==string_num) return len[a[i]];
        }
    return 0;
}
int main() {
    string s;
    while(cin>>s) trie_insert(s);
    gsa_build();
    cout<<gsa_topo()<<'\n';
    return 0;
}