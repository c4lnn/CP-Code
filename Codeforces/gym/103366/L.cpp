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
const int N=1e5+5;
int a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        ++a[x1+1];
        --a[x2+1];
    }
    int res=0;
    for(int i=1,t=0;i<=1e5;i++) {
        t+=a[i];
        if(t) ++res;
    }
    cout<<res<<'\n';
    return 0;
}