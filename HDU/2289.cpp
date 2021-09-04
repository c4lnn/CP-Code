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
const DB EPS=1e-8;
const DB PI=acos(-1);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        DB rr,R,H,V;cin>>rr>>R>>H>>V;
        DB l=0,r=H;
        for(int i=0;i<100;i++) {
            DB mid=(l+r)/2,y=mid*(R-rr)/H+rr;
            if(PI*mid*(y*y+rr*rr+y*rr)/3-V>=-EPS) r=mid;
            else l=mid;
        }
        cout<<fixed<<setprecision(6)<<l<<'\n';
    }
    return 0;
}