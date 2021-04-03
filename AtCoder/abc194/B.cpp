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
    int n;
    cin>>n;
    int res=INT_MAX,aa=INT_MAX,bb=INT_MAX;
    for(int i=1;i<=n;i++) {
        int a,b;
        cin>>a>>b;
        res=min({res,max(a,bb),max(aa,b),a+b});
        aa=min(aa,a);
        bb=min(bb,b);
    }
    cout<<res<<'\n';
    return 0;
}