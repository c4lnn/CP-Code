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
    int n,k;cin>>n>>k;
    VI a(n+1);
    for(int i=1;i<n;i++) a[i]=1;
    for(int i=1;i<=k;i++) {
        for(int j=1;j<=n;j++) {
            if(a[j]*2<=n-j) cout<<j,a[j]<<=1;
            else if(a[j]==n-j) cout<<n;
            else cout<<j+a[j],a[j]+=a[j+a[j]];
            cout<<" \n"[j==n];
        }
    }
    return 0;
}