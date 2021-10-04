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
int a[N],b[N],mxa[N],mxb[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    LL res=0;
    for(int i=n;i>=1;i--) {
        mxb[i]=max(a[i+1],mxa[i+1]);
        mxa[i]=max(b[i],mxb[i]);
        res+=max({0,mxb[i]-b[i],mxa[i]-a[i]});
    }
    cout<<res<<'\n';
    return 0;
}