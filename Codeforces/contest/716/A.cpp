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
    int n,m;cin>>n>>m;
    VI a(n);
    int cnt=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(i) {
            if(a[i]-a[i-1]<=m) ++cnt;
            else cnt=1;
        }
        else ++cnt;
    }
    cout<<cnt<<'\n';
    return 0;
}