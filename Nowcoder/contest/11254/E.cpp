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
vector<LL> res;
int main() {
    res.PB(1);
    for(LL i=2;i<=1e6;i++) {
        LL a=i,b=i*i*i;
        while(b<=1e18) {
            res.PB(b);
            LL t=b;
            if(b>(1e18+a)/i/i) break;
            b=b*i*i-a;
            a=t;
        }
    }
    sort(ALL(res));
    int T;cin>>T;
    while(T--) {
        LL n;cin>>n;
        cout<<upper_bound(ALL(res),n)-res.begin()<<'\n';
    }
    return 0;
}