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
    LL n;cin>>n;
    LL a;
    for(LL i=1;i<=n;i++) {
        if(i==1) {
            cout<<14<<'\n';
            a=4;
        }
        else {
            cout<<(i+1)*(i+1)*i-a/i<<'\n';
            a=(i+1)*i;
        }
    }
    return 0;
}