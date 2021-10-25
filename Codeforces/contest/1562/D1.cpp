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
        int n,q;string s;cin>>n>>q>>s;
        VI sum(n+1);
        for(int i=0;i<SZ(s);i++) sum[i+1]=sum[i]+(i&1?-1:1)*(s[i]=='+'?1:-1);
        while(q--) {
            int l,r;cin>>l>>r;
            if(sum[r]-sum[l-1]==0) cout<<0<<'\n';
            else if((r-l+1)&1) cout<<1<<'\n';
            else cout<<2<<'\n';
        }
    }
    return 0;
}