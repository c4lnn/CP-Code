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
const int N=9e4+5;
int n,sz,last,len[N<<1],link[N<<1],nxt[N<<1][26],dp[N<<1];
void sam_insert(int x) {
    int cur=++sz,p=last;
    len[cur]=len[last]+1;
    while(p!=-1&&!nxt[p][x]) nxt[p][x]=cur,p=link[p];
    if(p==-1) link[cur]=0;
    else {
        int q=nxt[p][x];
        if(len[p]+1==len[q]) link[cur]=q;
        else {
            int t=++sz;
            len[t]=len[p]+1;
            for(int i=0;i<26;i++) nxt[t][i]=nxt[q][i];
            link[t]=link[q];
            while(p!=-1&&nxt[p][x]==q) nxt[p][x]=t,p=link[p];
            link[q]=link[cur]=t;
        }
    }
    last=cur;
}
int c[N<<1],a[N<<1]; // a 是拓扑次序
void topo() {
    for(int i=1;i<=n;i++) c[i]=0;
    for(int i=1;i<=sz;i++) ++c[len[i]];
    for(int i=1;i<=n;i++) c[i]+=c[i-1];
    for(int i=sz;i>=1;i--) a[c[len[i]]--]=i;
    for(int i=sz;i>=1;i--) dp[i]=1;
    for(int i=sz;~i;i--)
        for(int j=0;j<26;j++)
            dp[a[i]]+=dp[nxt[a[i]][j]];
}
void find(int u,int k) {
    if(!k) {
        cout<<'\n';
        return;
    }
    for(int i=0;i<26;i++) {
        if(!nxt[u][i]) continue;
        if(dp[nxt[u][i]]<k) k-=dp[nxt[u][i]];
        else if(dp[nxt[u][i]]>=k) {
            cout<<(char)(i+'a');
            find(nxt[u][i],k-1);
            return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    n=SZ(s);
    link[0]=-1;
    for(int i=0;i<n;i++) sam_insert(s[i]-'a');
    topo();
    int T;
    cin>>T;
    while(T--) {
        int k;
        cin>>k;
        find(0,k);
    }
    return 0;
}