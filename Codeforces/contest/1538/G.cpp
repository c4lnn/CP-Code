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
LL x,y,a,b;
bool check(LL mid) {
    return max(0ll,(LL)ceil(1.0*(y-a*mid)/(b-a)))<=min(mid,(LL)floor(1.0*(x-b*mid)/(a-b)));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        cin>>x>>y>>a>>b;
        if(a==b) cout<<min(x,y)/a<<'\n';
        else {
            if(a<b) swap(a,b);
            LL l=0,r=1e9;
            while(l<r) {
                LL mid=l+r+1>>1;
                if(check(mid)) l=mid;
                else r=mid-1;
            }
            cout<<l<<'\n';
        }
    }
    return 0;
}