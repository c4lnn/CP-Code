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
    int n;cin>>n;
    VI a(n),b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(ALL(b));
    LL res=0,sum=0;
    for(int i=0;i<n;i++) {
        sum+=a[i];
        sum-=b[i];
        if(!sum) ++res;
    }
    cout<<res<<'\n';
    return 0;
}