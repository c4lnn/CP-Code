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
const int N=1e5+5;
int n,m,tot[N],c[N<<1];
PII a[N];
VI b;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        cin>>a[i].FI>>a[i].SE;
        ++a[i].SE;
        b.PB(a[i].FI);
        b.PB(a[i].SE);
    }
    sort(ALL(b));
    b.resize(unique(ALL(b))-b.begin());
    for(int i=1;i<=m;i++) {
        a[i].FI=lower_bound(ALL(b),a[i].FI)-b.begin();
        a[i].SE=lower_bound(ALL(b),a[i].SE)-b.begin();
        ++c[a[i].FI];
        --c[a[i].SE];
    }
    int t=0,pre=0;
    for(int i=0;i<SZ(b);i++) {
        if(!c[i]) continue;
        if(i) tot[t]+=b[i]-b[pre];
        pre=i;
        t+=c[i];
        if(i==SZ(b)-1) tot[t]+=b[SZ(b)-1]-b[pre]+1;
    }
    int a=ceil(n/10.0),b=ceil(n/4.0),c=ceil(n/2.0);
    int ta=0,tb=0,tc=0;
    for(int i=m;i>=1;i--) {
        if(!tot[i]) continue;
        if(ta<a) ta+=tot[i];
        else if(ta+tb<b) tb+=tot[i];
        else if(ta+tb+tc<c) tc+=tot[i];
    }
    cout<<ta<<' '<<tb<<' '<<tc<<'\n';
    return 0;
}