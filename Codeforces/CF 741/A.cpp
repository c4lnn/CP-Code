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
const int N=105;
int cnt,nxt[N];
bool st[N];
bool dfs(int u,int t) {
    if(st[u]) {
        if(u==t) return true;
        return false;
    }
    ++cnt;
    st[u]=true;
    return dfs(nxt[u],t);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    int res=1;
    for(int i=1;i<=n;i++) cin>>nxt[i];
    for(int i=1;i<=n;i++) if(!st[i]) {
        cnt=0;
        if(!dfs(i,i)) return cout<<-1<<'\n',0;
        else {
            if(cnt&1) res=res*cnt/__gcd(res,cnt);
            else res=res*(cnt/2)/__gcd(res,cnt/2);
        }
    }
    cout<<res<<'\n';
    return 0;
}