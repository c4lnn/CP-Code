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
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        VI a,b;
        for(int i=0;n;i++) {
            if(i&1) a.PB(n%10);
            else b.PB(n%10);
            n/=10;
        }
        int t=0;
        for(int i=SZ(a)-1;~i;i--) t=t*10+a[i];
        int res=t+1;
        t=0;
        for(int i=SZ(b)-1;~i;i--) t=t*10+b[i];
        cout<<res*(t+1)-2<<'\n';
    }
    return 0;
}