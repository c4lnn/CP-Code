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
const int N=1e5+5;
int b[N],res[N];
PII a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i].FI;
        a[i].SE=i;
        int v;cin>>v;
        b[i]=a[i].FI+v*k;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++) res[a[i].SE]=b[i];
    for(int i=1;i<=n;i++) cout<<res[i]<<" \n"[i==n];
    return 0;
}