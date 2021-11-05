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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,n;cin>>a>>b>>n;
    int aa=0,bb=0;
    for(int i=1;i<=n;i++) {
        int p1,q1,p2,q2;cin>>p1>>q1>>p2>>q2;
        if(a<aa||b<bb) break;
        if(p1+p2==q1&&p1+p2!=q2) ++aa;
        else if(p1+p2!=q1&&p1+p2==q2) ++bb;
    }
    if(a<aa) cout<<'A'<<'\n'<<bb<<'\n';
    else cout<<'B'<<'\n'<<aa<<'\n';
    return 0;
}