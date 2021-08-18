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
        VI a(n),b(n);
        VPII c;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            c.EB(a[i],i);
        }
        for(int i=0;i<n;i++) cin>>b[i];
        reverse(ALL(b));
        sort(ALL(c));
        for(int i=0;i<n;i++) {
            int mx=a[i]+b[n-1];
            int l=n-2,cnt=0;
            for(int j=0;j<n;j++) if(c[j].SE!=i) {
                while(l>=0&&c[j].FI+b[l]>mx) --l;
                if(l<0) break;
                ++cnt,--l;
            }
            cout<<n-cnt<<' ';
            int mn=a[i]+b[0];
            l=1,cnt=0;
            for(int j=n-1;~j;j--) if(c[j].SE!=i) {
                while(l<n&&c[j].FI+b[l]<=mn) ++l;
                if(l==n) break;
                ++cnt,++l;
            }
            cout<<cnt+1<<'\n';
        }
    }
    return 0;
}