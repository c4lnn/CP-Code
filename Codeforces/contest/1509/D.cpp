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
        string a,b,c;cin>>a>>b>>c;
        int aa=0,bb=0,cc=0;
        while(aa<2*n&&bb<2*n&&cc<2*n) {
            if(a[aa]==b[bb]) cout<<a[aa],++aa,++bb;
            else if(a[aa]==c[cc]) cout<<a[aa],++aa,++cc;
            else if(b[bb]==c[cc]) cout<<b[bb],++bb,++cc;
        }
        if(aa==2*n) cout<<(bb>cc?b.substr(bb,2*n-bb):c.substr(cc,2*n-cc))<<'\n';
        else if(bb==2*n) cout<<(aa>cc?a.substr(aa,2*n-aa):c.substr(cc,2*n-cc))<<'\n';
        else if(cc==2*n) cout<<(aa>bb?a.substr(aa,2*n-aa):b.substr(bb,2*n-bb))<<'\n';
    }
    return 0;
}