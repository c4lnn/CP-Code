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
const LD PI=acos(-1);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        LD n,m;cin>>n>>m;
        LD a=min(n,m),b=sqrt(n*n+m*m);
        int res=0;
        for(int i=0;i<3;i++) if(PI>i*a) res=max(res,2*i+(int)((PI-i*a)/b)*3);
        for(int i=0;i<2;i++) if(PI>i*b) res=max(res,3*i+(int)((PI-i*b)/a)*2);
        cout<<res+4<<'\n';
    }
    return 0;
}