#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
const int N=1e3+5;
int n,m,s,t,pre[N];
bool st[N];
VI g[N];
void bfs1() {
    queue<int> q;
    for(int i=1;i<=n;i++) st[i]=false;
    q.push(s);
    st[s]=true;
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        if(u==t) return;
        for(int i=0;i<SZ(g[u]);i++) {
            int v=g[u][i];
            if(st[v]) continue;
            st[v]=true;
            pre[v]=u;
            q.push(v);
        }
    }
}
bool bfs2(int x) {
    queue<int> q;
    for(int i=1;i<=n;i++) st[i]=false;
    q.push(s);
    st[s]=true;
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        if(u==t) return true;
        for(int i=0;i<SZ(g[u]);i++) {
            int v=g[u][i];
            if(st[v]||v==x) continue;
            st[v]=true;
            pre[v]=u;
            q.push(v);
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v;cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    cin>>s>>t;
    bfs1();
    if(!pre[t]) cout<<-1<<'\n';
    else {
        int res=0;
        for(int u=pre[t];u!=s;u=pre[u]) if(!bfs2(u)) ++res;
        cout<<res<<'\n';
    }
    return 0;
}