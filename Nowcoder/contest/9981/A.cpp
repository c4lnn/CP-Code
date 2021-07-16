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
//head
const LL MOD=1e9+7;
const int N=1e6+5;
int n;
LL f[N],a[N],b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    f[2]=a[2]=b[2]=1;
    for(int i=3;i<=n;i++) {
        f[i]=((f[i-1]*25%MOD+a[i-1]*25%MOD)%MOD+b[i-1]*26%MOD)%MOD;
        a[i]=(a[i-1]*25%MOD+b[i-1]*26%MOD)%MOD;
        b[i]=b[i-1]*26%MOD;
    }
    LL res=0;
    for(int i=2;i<=n;i++) res=(res+f[i])%MOD;
    cout<<res<<'\n';
    return 0;
}