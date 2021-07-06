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
    int n,m,k;cin>>n>>m>>k;
    int res=0;
    for(int i=1;i<=m;i++) {
        int l,r;cin>>l>>r;
        res+=r-l;
    }
    for(int i=1;i<=k;i++) {
        int x;cin>>x;
    }
    cout<<res<<'\n';
    return 0;
}