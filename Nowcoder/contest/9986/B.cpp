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
LL C(LL a,LL b) {
    if(a<b) return 0;
    if(a<3) return a==2&&b==1?2:1;
    return C(a/3,b/3)*C(a%3,b%3)%3;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        LL n,k;
        cin>>n>>k;
        cout<<C(2*n,k)*(((2*n-k)&1?-1:1)+3)%3<<'\n';
    }
    return 0;
}