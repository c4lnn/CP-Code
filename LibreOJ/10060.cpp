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
const int N=1e6+5;
int id[205],w[N],tot[N],tr[N][26],fail[N],sz;
VI g[N];
void insert(const string &s,int i) {
    int u=0;
    for(auto c:s) {
        int v=c-'a';
        if(!tr[u][v]) tr[u][v]=++sz;
        u=tr[u][v];
        ++tot[u];
    }
    id[i]=u;
}
void build() {
    queue<int> q;
    for(int v=0;v<26;v++) if(tr[0][v]) q.push(tr[0][v]);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int v=0;v<26;v++) {
            if(tr[u][v]) fail[tr[u][v]]=tr[fail[u]][v],q.push(tr[u][v]);
            else tr[u][v]=tr[fail[u]][v];
        }
    }
    for(int i=1;i<=sz;i++) g[fail[i]].PB(i);
}
void dfs(int u) {
    w[u]=tot[u];
    for(auto v:g[u]) {
        dfs(v);
        w[u]+=w[v];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        string s;cin>>s;
        insert(s,i);
    }
    build();
    dfs(0);
    for(int i=1;i<=n;i++) cout<<w[id[i]]<<'\n';
    return 0;
}