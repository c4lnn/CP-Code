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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    VI cnt(n+1);
    for(int i=1;i<=m;i++) {
        int mx=-1,t;
        for(int j=1;j<=n;j++) {
            int x;cin>>x;
            if(x>mx) mx=x,t=j;
        }
        ++cnt[t];
    }
    int res=1;
    for(int i=1;i<=n;i++) if(cnt[i]>cnt[res]) res=i;
    cout<<res<<'\n';
    return 0;
}