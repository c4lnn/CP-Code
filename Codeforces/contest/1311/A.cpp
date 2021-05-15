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
        int a,b;cin>>a>>b;
        if(a<b) {
            if((b-a)&1) cout<<1<<'\n';
            else cout<<2<<'\n';
        }
        else if(a>b) {
            if((a-b)&1) cout<<2<<'\n';
            else cout<<1<<'\n';
        }
        else cout<<0<<'\n';
    }
    return 0;
}