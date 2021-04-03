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
const int N=3e5+5;
LL a[N],sum[N],ssum[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        ssum[i]=ssum[i-1]+a[i]*a[i];
    }
    LL res=0;
    for(int i=1;i<=n;i++) res+=(n-i)*a[i]*a[i]-2*a[i]*(sum[n]-sum[i])+ssum[n]-ssum[i];
    cout<<res<<'\n';
    return 0;
}