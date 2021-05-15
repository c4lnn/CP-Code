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
const int N=250005;
int n,sz,last,len[N<<1],link[N<<1],tot[N<<1];
map<int,int> nxt[N<<1];
void sam_insert(int x) {
    int cur=++sz,p=last;
    len[cur]=len[last]+1;
    tot[cur]=1;
    while(p!=-1&&!nxt[p].count(x)) nxt[p][x]=cur,p=link[p];
    if(p==-1) link[cur]=0;
    else {
        int q=nxt[p][x];
        if(len[p]+1==len[q]) link[cur]=q;
        else {
            int t=++sz;
            len[t]=len[p]+1;
            nxt[t]=nxt[q];
            link[t]=link[q];
            while(p!=-1&&nxt[p][x]==q) nxt[p][x]=t,p=link[p];
            link[q]=link[cur]=t;
        }
    }
    last=cur;
}
int lcs(const string &S,const string &T) {
    n=SZ(S);
    for(int i=0;i<n;i++) sam_insert(S[i]);
    int v=0,l=0,mx=0;
    for(int i=0;i<SZ(T);i++) {
        while(v&&!nxt[v].count(T[i])) v=link[v],l=len[v];
        if(nxt[v].count(T[i])) v=nxt[v][T[i]],++l;
        mx=max(mx,l);
    }
    return mx;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    link[0]=-1;
    string s,t;
    cin>>s>>t;
    cout<<lcs(s,t)<<'\n';
    return 0;
}