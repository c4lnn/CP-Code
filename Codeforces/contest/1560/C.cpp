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
        int k;cin>>k;
        int t=sqrt(k);
        int a=k-t*t;
        if(!a) cout<<t<<' '<<1<<'\n';
        else {
            int b=2*(t+1)-1;
            if(a<=b/2) cout<<a<<' '<<t+1<<'\n';
            else cout<<t+1<<' '<<t+1-(a-b/2)+1<<'\n';
        }
    }
    return 0;
}