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
bool cmp(PII a,PII b) {
    return a.FI>b.FI;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i].FI;
        a[i].SE=i;
        mx=max(mx,a[i].FI);
    }
    sort(a+1,a+1+n,cmp);
    int sum1=0,sum2=0;
    VPII p,q;
    for(int i=1;i<=n;i+=2) p.PB(a[i]),sum1+=a[i].FI;
    for(int i=2;i<=n;i+=2) q.PB(a[i]),sum2+=a[i].FI;
    if(sum1-sum2>mx) {
        auto x=p[SZ(p)-1];
        sum1-=x.FI;
        sum2+=x.FI;
        q.PB(x),p.pop_back();
    }
    cout<<SZ(p)<<'\n';
    for(int i=0;i<SZ(p);i++) cout<<p[i].SE<<" \n"[i==SZ(p)-1];
    cout<<'\n';
    cout<<SZ(q)<<'\n';
    for(int i=0;i<SZ(q);i++) cout<<q[i].SE<<" \n"[i==SZ(q)-1];
    cout<<'\n';
    return 0;
}