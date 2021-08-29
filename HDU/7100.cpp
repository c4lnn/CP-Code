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
        int res=n-n/2;
        int t=0;
        if((n-1)%3==0) t=(n-1)/3+1;
        else t=(n+1)/3;
        if(t%2==0) ++t;
        res+=(n-t)/2+1;
        cout<<res<<'\n';
    }
    return 0;
}