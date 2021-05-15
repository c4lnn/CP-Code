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
    VI a(n+1),cnt(2);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    int res=0;
    for(int i=1;i<=k;i++) {
        cnt[0]=cnt[1]=0;
        for(int j=i;j<=n;j+=k) {
            ++cnt[a[j]-1];
        }
        res+=min(cnt[0],cnt[1]);
    }
    cout<<res<<'\n';
    return 0;
}