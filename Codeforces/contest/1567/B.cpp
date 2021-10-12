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
    VI c(300001);
    for(int i=1;i<=3e5;i++) c[i]=c[i-1]^i;
    while(T--) {
        int a,b;cin>>a>>b;
        if(c[a-1]==b) cout<<a<<'\n';
        else if((c[a-1]^b)==a) cout<<a+2<<'\n';
        else cout<<a+1<<'\n';
    }
    return 0;
}