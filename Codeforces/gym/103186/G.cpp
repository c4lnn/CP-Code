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
const LL MOD=998244353;
const int N=1e5+5;
int a[N];
LL pre[N],suf[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    pre[0]=1;
    for(int i=1;i<=n;i++) {
        pre[i]=pre[i-1]*a[i]%MOD;
    }
    suf[n+1]=1;
    for(int i=n;i>=1;i--) {
        suf[i]=suf[i+1]*a[i]%MOD;
    }
    for(int i=1;i<=n;i++) {
        cout<<pre[i-1]*suf[i+1]%MOD<<" \n"[i==n];
    }
    return 0;
}