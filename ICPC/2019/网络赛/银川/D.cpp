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
     int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        int n,m;cin>>n>>m;
        cout<<"Case #"<<cs<<": "<<fixed<<setprecision(6)<<(n==1?1:1.0/2)<<' '<<(m==1?1:1.0*(m+1)/(2*m))<<'\n';
    }
    return 0;
}