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
//head
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        int n,k;
        cin>>n>>k;
        if(k>=n) {
            if(k%n) cout<<k/n+1<<'\n';
            else cout<<k/n<<'\n';
        }
        else {
            if(n%k) cout<<2<<'\n';
            else cout<<1<<'\n';
        }
    }
    return 0;
}