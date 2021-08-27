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
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        VPII mx(n);
        for(int i=0;i<n;i++) {
            int k;cin>>k;
            mx[i].SE=k;
            for(int j=1;j<=k;j++) {
                int x;cin>>x;
                mx[i].FI=max(mx[i].FI,x-j+2);
            }
        }
        sort(ALL(mx));
        int res=0,sz=0;
        for(int i=0;i<n;i++) {
            res=max(res,mx[i].FI-sz);
            sz+=mx[i].SE;
        }
        cout<<res<<'\n';
    }
    return 0;
}