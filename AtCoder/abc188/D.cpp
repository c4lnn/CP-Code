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
//head
const int N=2e5+5;
LL C,a[N],b[N],c[N],tot[N<<1];
vector<LL> d;
int n;
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>C;
    for(int i=0;i<n;i++) {
        cin>>a[i]>>b[i]>>c[i];
        ++b[i];
        d.PB(a[i]),d.PB(b[i]);
    }
    sort(ALL(d));
    d.resize(unique(ALL(d))-d.begin());
    LL mx=d[SZ(d)-1];
    d.PB(mx+1);
    for(int i=0;i<n;i++) {
        tot[lower_bound(ALL(d),a[i])-d.begin()]+=c[i];
        tot[lower_bound(ALL(d),b[i])-d.begin()]-=c[i];
    }
    LL res=0,t=0;
    for(int i=0;i<SZ(d)-1;i++) {
        t+=tot[i];
        res+=min(C,t)*(d[i+1]-d[i]);
    }
    cout<<res<<'\n';
    return 0;
}