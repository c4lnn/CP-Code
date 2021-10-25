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
void solve(const string &s) {
    int len=SZ(s)/2;
    for(int i=len;i<SZ(s);i++) if(s[i]=='0') {
        cout<<1<<' '<<i+1<<' '<<1<<' '<<i<<'\n';
        return;
    }
    for(int i=len-1;~i;i--) if(s[i]=='0') {
        cout<<i+1<<' '<<i+1+len<<' '<<SZ(s)-len+1<<' '<<SZ(s)<<'\n';
        return;
    }
    cout<<1<<' '<<SZ(s)-1<<' '<<2<<' '<<SZ(s)<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;string s;cin>>n>>s;
        solve(s);
    }
    return 0;
}