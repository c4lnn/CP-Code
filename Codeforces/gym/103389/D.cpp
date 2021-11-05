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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    VI a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    LL res=0;
    for(int i=2;i<=n;i++) {
        if(a[i]>a[i-1]) res+=a[i];
        else res+=a[i-1];
    }
    cout<<res<<'\n';
    return 0;
}