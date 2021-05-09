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
        VI a(n+1);
        int pos=1;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            if(a[i]<a[pos]) pos=i;
        }
        cout<<n-1<<'\n';
        for(int i=pos-1,t=a[pos];i>=1;i--) cout<<i<<' '<<pos<<' '<<++t<<' '<<a[pos]<<'\n';
        for(int i=pos+1,t=a[pos];i<=n;i++) cout<<i<<' '<<pos<<' '<<++t<<' '<<a[pos]<<'\n';

    }
    return 0;
}