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
        int x,y;cin>>x>>y;
        VI res;
        while(1) {
            res.PB(x/y);
            x%=y;
            if(x==1) break;
            swap(x,y);
        }
        cout<<SZ(res)<<' ';
        for(auto v:res) cout<<v<<' ';
        cout<<y<<'\n';
    }
    return 0;
}