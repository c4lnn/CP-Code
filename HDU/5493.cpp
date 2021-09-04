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
const int N=1e5+5;
PII a[N];
int n,b[N],c[N];
void update(int x) {
    for(int i=x;i<=n;i+=i&-i) ++c[i];
}
int query(int x) {
    int ret=0;
    for(int i=x;i;i-=i&-i) ret+=c[i];
    return ret;
}
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) c[i]=0;
    for(int i=1;i<=n;i++) cin>>a[i].FI>>a[i].SE;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) {
        if(a[i].SE>n-i) {cout<<"impossible\n";return;}
        int l=1,r=n,t=min(a[i].SE,n-i-a[i].SE);
        while(l<r) {
            int mid=l+r>>1;
            if(mid-query(mid)>=t+1) r=mid;
            else l=mid+1;
        }
        update(l);
        b[l]=a[i].FI;
    }
    for(int i=1;i<=n;i++) cout<<b[i]<<" \n"[i==n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        cout<<"Case #"<<cs<<": ";
        solve();
    }
    return 0;
}