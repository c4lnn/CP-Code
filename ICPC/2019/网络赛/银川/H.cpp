#include <bits/stdc++.h>
#define int long long
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
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
const int N=1e5+5;
int sum[N];
bool cmp(PII a,PII b) {
    return a.FI*b.SE<b.FI*a.SE;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    for(int i=1;i<=100000;i++) sum[i]=sum[i-1]+i;
    for(int cs=1;cs<=T;cs++) {
        int n;cin>>n;
        VPII a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i].FI>>a[i].SE;
            a[i].FI=lower_bound(sum+1,sum+100001,a[i].FI)-sum;
        }
        sort(ALL(a),cmp);
        int t=0,res=0;
        for(int i=0;i<n;i++) {
            t+=a[i].FI;
            res+=t*a[i].SE;
        }
        cout<<"Case #"<<cs<<": "<<res<<'\n';
    }
    return 0;
}