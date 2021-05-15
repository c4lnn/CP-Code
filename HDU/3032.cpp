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
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        int res=0;
        for(int i=1;i<=n;i++) {
            int x;
            cin>>x;
            res=res^(x%4==3?x+1:(x%4==0?x-1:x));
        }
        cout<<(res?"Alice":"Bob")<<'\n';
    }
    return 0;
}