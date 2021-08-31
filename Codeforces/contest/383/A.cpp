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
    int n;cin>>n;
    VI a(n+1),pre(n+1),suf(n+2);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]+!a[i];
    LL mn=LLONG_MAX,sum=0;
    for(int i=1;i<=n;i++) if(!a[i]) sum+=pre[i];
    mn=min(mn,sum);
    sum=0;
    for(int i=1;i<=n;i++) if(a[i]) sum+=suf[i];
    mn=min(mn,sum);
    cout<<mn<<'\n';
    return 0;
}