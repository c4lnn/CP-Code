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
    for(int cs=1;cs<=T;cs++) {
        int n;cin>>n;
        VI a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
            a[i]-=i;
        }
        VI dp(n,0x3f3f3f3f);
        for(int i=0;i<n;i++) *upper_bound(ALL(dp),a[i])=a[i];
        cout<<"Case #"<<cs<<":\n"<<n-(lower_bound(ALL(dp),0x3f3f3f3f)-dp.begin())<<'\n';
    }
    return 0;
}