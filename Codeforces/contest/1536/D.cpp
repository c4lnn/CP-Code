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
        set<int> s;
        for(int i=1;i<=n;i++) cin>>a[i];
        bool f=false;
        s.insert(a[1]);
        for(int i=2;i<=n;i++) {
            if(a[i]<a[i-1]) {
                auto pos=s.upper_bound(a[i]);
                if(pos==s.end()||*pos!=a[i-1]) {
                    f=true;
                    break;
                }
            }
            else if(a[i]>a[i-1]) {
                auto pos=s.lower_bound(a[i]);
                if(pos==s.begin()||*prev(pos,1)!=a[i-1]) {
                    f=true;
                    break;
                }
            }
            s.insert(a[i]);
        }
        cout<<(f?"NO":"YES")<<'\n';
    }
    return 0;
}