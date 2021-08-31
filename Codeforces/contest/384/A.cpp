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
    int n;cin>>n;
    int tot=0;
    if(n&1) tot=((n+1)/2)*((n+1)/2)+(n/2)*(n/2);
    else tot=n*(n/2);
    cout<<tot<<'\n';
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i&1) cout<<(j&1?'C':'.');
            else cout<<(j&1?'.':'C');
        }
        cout<<'\n';
    }
    return 0;
}