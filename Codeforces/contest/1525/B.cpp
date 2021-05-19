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
int a[55];
int solve(int n) {
    for(int i=1;i<=n;i++) if(a[i]!=i) {
        if(a[1]==1||a[n]==n) return 1;
        if(a[1]==n&&a[n]==1) return 3;
        return 2;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        cout<<solve(n)<<'\n';
    }
    return 0;
}