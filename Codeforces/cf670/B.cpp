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
    VI a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1,sum=0;i<=n;i++) {
        if(sum+i>=k) return cout<<a[k-sum-1]<<'\n',0;
        else sum+=i;
    }
    return 0;
}