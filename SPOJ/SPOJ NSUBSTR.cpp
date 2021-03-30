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
void sam_init() {
    link[0]=-1;
    len[0]=sz=last=0;
}
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
int c[N<<1],a[N<<1],dp[N]; // a 是拓扑次序
void topo() {
    for(int i=1;i<=n;i++) c[i]=0;
    for(int i=1;i<=sz;i++) ++c[len[i]];
    for(int i=1;i<=n;i++) c[i]+=c[i-1];
    for(int i=sz;i>=1;i--) a[c[len[i]]--]=i;
}
int main() {
    #ifdef DEBUG
        freopen("E:/OneDrive/IO/in.txt","r",stdin);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sam_init();
    string s;
    cin>>s;
    n=SZ(s);
    for(int i=0;i<n;i++) sam_insert(s[i]);
    topo();
    for(int i=sz;i>=1;i--) tot[link[a[i]]]+=tot[a[i]];
    for(int i=sz;i>=1;i--) dp[len[a[i]]]=max(dp[len[a[i]]],tot[a[i]]);
    for(int i=n-1;i>=1;i--) dp[i]=max(dp[i],dp[i+1]);
    for(int i=1;i<=n;i++) cout<<dp[i]<<'\n';
    return 0;
}