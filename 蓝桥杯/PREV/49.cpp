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
const int N=1e5+5;
int top,s[N];
bool ins[N];
VI g[N],res;
bool dfs(int u,int fa) {
    s[++top]=u;
    ins[u]=true;
    for(int i=0;i<SZ(g[u]);i++) {
        int v=g[u][i];
        if(v!=fa) {
            if(ins[v]) {
                int x;
                do {
                    x=s[top--];
                    res.PB(x);
                    ins[x]=false;
                } while(x!=v);
                return true;
            }
            if(dfs(v,u)) return true;
        }
    }
    --top;
    ins[u]=false;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int u,v;cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1,0);
    sort(ALL(res));
    for(int i=0;i<SZ(res);i++) cout<<res[i]<<" \n"[i==SZ(res)-1];
    return 0;
}