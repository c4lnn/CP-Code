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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
const int N=1e6+5;
int sz[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<n;i++) {
        int u,v;cin>>u>>v;
        ++sz[u];
        ++sz[v];
    }
    int cnt=0;
    for(int i=1;i<=n;i++) {
        if(sz[i]>3) return cout<<0<<'\n',0;
        else if(sz[i]==3) ++cnt;
    }
    cout<<n-cnt<<'\n';
    return 0;
}