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
    int n;cin>>n;
    VI tot(1<<24);
    for(int i=1;i<=n;i++) {
        string s;cin>>s;
        sort(ALL(s));
        s.resize(unique(ALL(s))-s.begin());
        int bit=0;
        for(auto c:s) bit|=(1<<(c-'a'));
        ++tot[bit];
    }
    for(int i=0;i<24;i++) {
        for(int j=0;j<1<<24;j++) if(j&(1<<i)) {
            tot[j]+=tot[j^(1<<i)];
        }
    }
    int res=0;
    for(int i=0;i<1<<24;i++) res^=(n-tot[i^((1<<24)-1)])*(n-tot[i^((1<<24)-1)]);
    cout<<res<<'\n';
    return 0;
}