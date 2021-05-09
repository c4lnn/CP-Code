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
        VI a,b;
        for(int i=1;i<=n;i++) {
            int x;cin>>x;
            if(x&1) a.PB(x);
            else b.PB(x);
        }
        for(auto x:a) cout<<x<<' ';
        for(auto x:b) cout<<x<<' ';
        cout<<'\n';
    }
    return 0;
}