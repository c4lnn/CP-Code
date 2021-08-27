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
        for(int i=1;i<=n;i++) cin>>a[i];
        int cnt=0;
        for(int i=1;;i++) {
            int t=0;
            for(int j=i&1?1:2;j+1<=n;j+=2) {
                if(a[j]>a[j+1]) {
                    swap(a[j],a[j+1]);
                    ++t;
                }
            }
            if(!t) {
                bool f=false;
                for(int j=1;j<n;j++) if(a[j]>a[j+1]) {f=true;break;}
                if(!f) break;
            }
            ++cnt;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}