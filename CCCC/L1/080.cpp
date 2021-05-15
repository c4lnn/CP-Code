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
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,n;cin>>a>>b>>n;
    VI t;
    t.PB(a),t.PB(b);
    int l=0;
    while(SZ(t)<=n) {
        int x=t[l]*t[l+1];
        VI tt;
        if(!x) tt.PB(x);
        else {
            while(x) {
                tt.PB(x%10),x/=10;
            }
        }
        for(int i=SZ(tt)-1;~i;i--) t.PB(tt[i]);
        ++l;
        if(SZ(t)>n) break;
    }
    for(int i=0;i<n;i++) cout<<t[i]<<" \n"[i==n-1];
    return 0;
}