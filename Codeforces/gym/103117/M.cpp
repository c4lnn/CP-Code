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
const int N=1e5+5;
int v[N],t[N],p[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k,x;cin>>n>>k>>x>>p[0];
    for(int i=1;i<=n;i++) cin>>v[i];
    sort(v+1,v+1+n);
    for(int i=1;i<=k;i++) cin>>t[i];
    for(int i=1;i<=k;i++) cin>>p[i];
    int mx=p[0];
    for(int i=1;i<=k;i++) mx=max(mx,p[i]-t[i]);
    int res=0;
    for(int i=1;i<=n;i++) if(mx>=(int)ceil(1.0*x/v[i])) ++res;
    cout<<res<<'\n';
    return 0;
}