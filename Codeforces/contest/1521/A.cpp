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
        LL a,b;cin>>a>>b;
        if(b==1) cout<<"NO"<<'\n';
        else {
            cout<<"YES"<<'\n';
            cout<<a*(b+1)<<' '<<a*(b-1)<<' '<<a*b*2<<'\n';
        }
    }
    return 0;
}