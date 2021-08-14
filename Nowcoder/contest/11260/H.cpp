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
    int n;cin>>n;
    VI a;
    do {
        --n;
        a.PB(n%3);
        n/=3;
    } while(n);
    for(int i=SZ(a)-1;~i;i--) {
        if(a[i]==0) cout<<2;
        else if(a[i]==1) cout<<3;
        else cout<<6;
    }
    cout<<'\n';
    return 0;
}
