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
        LL mx=0,sum=0;
        for(int i=1;i<=n;i++) {
            LL x;cin>>x;
            mx=max(mx,x);
            sum+=x;
        }
        cout<<(sum-mx>=mx-1?"Yes":"No")<<'\n';
    }
    return 0;
}