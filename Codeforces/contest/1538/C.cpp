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
        int n,l,r;cin>>n>>l>>r;
        VI a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        sort(ALL(a));
        LL res=0;
        for(int i=0;i<n;i++) {
            res+=upper_bound(ALL(a),r-a[i])-a.begin();
            res-=lower_bound(ALL(a),l-a[i])-a.begin();
            if(a[i]<=r-a[i]&&a[i]>=l-a[i]) --res;
        }
        cout<<res/2<<'\n';
    }
    return 0;
}