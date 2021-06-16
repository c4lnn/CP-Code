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
const int N=3e4+5;
int tr[N][2],fail[N],sz;
bool f[N],st[N],ins[N];
void insert(const string &s) {
    int u=0;
    for(auto c:s) {
        int v=c-'0';
        if(!tr[u][v]) tr[u][v]=++sz;
        u=tr[u][v];
    }
    f[u]=true;
}
void build() {
    queue<int> q;
    for(int v=0;v<2;v++) if(tr[0][v]) q.push(tr[0][v]);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int v=0;v<2;v++) {
            if(tr[u][v]) {
                fail[tr[u][v]]=tr[fail[u]][v];
                f[tr[u][v]]|=f[fail[tr[u][v]]];
                q.push(tr[u][v]);
            }
            else tr[u][v]=tr[fail[u]][v];
        }
    }
}
bool dfs(int u) {
    if(ins[u]) return true;
    if(st[u]||f[u]) return false;
    ins[u]=st[u]=true;
    if(dfs(tr[u][0])) return true;
    if(dfs(tr[u][1])) return true;
    ins[u]=false;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        string s;cin>>s;
        insert(s);
    }
    build();
    cout<<(dfs(0)?"TAK":"NIE")<<'\n';
    return 0;
}