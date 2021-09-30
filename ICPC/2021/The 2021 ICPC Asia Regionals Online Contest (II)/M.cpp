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
    int n;cin>>n;
    VI sgn(n),a(n),b(n),c(n);
    for(int i=0;i<n;i++) cin>>sgn[i];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0,d=0;i<n;i++) {
        d+=sgn[i]*(a[i]+b[i]);
        if(sgn[i]==-1) {
            if(d==-3) c[i]=1,d=-1;
            else if(d==-2) c[i]=0,d=-1;
            else if(d==-1) c[i]=1,d=0;
            else if(d==1) c[i]=1,d=1;
        }
        else {
            if(d==3) c[i]=1,d=1;
            else if(d==2) c[i]=0,d=1;
            else if(d==1) c[i]=1,d=0;
            else if(d==-1) c[i]=1,d=-1;
        }
    }
    for(int i=0;i<n;i++) {
        cout<<c[i];
        if(i<n-1) cout<<' ';
    }
    return 0;
}