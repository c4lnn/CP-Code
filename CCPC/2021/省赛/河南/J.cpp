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
int n,m,a[N],b[N],c[N];
void update(int x) {
    for(int i=x;i<=n+m;i+=i&-i) ++c[i];
}
int query(int l,int r) {
    int ret=0;
    for(int i=r;i;i-=i&-i) ret+=c[i];
    for(int i=l-1;i;i-=i&-i) ret-=c[i];
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=n;i>=1;i--) cin>>a[i];
    for(int i=n+1;i<=n+m;i++) cin>>a[i];
    for(int i=1;i<=n+m;i++) b[i]=i;
    sort(b+1,b+1+n+m,[](int x,int y) {
        return a[x]>a[y];
    });
    LL res=0;
    int top1=n,top2=n+1;
    for(int i=1;i<=n+m;i++) {
        if(b[i]<=top1) {
            res+=top1-b[i]-query(b[i],top1);
            top1=b[i]-1,top2=b[i];
            update(b[i]);
        }
        else {
            res+=b[i]-top2-query(top2,b[i]);
            top2=b[i]+1;top1=b[i];
            update(b[i]);
        }
    }
    cout<<res<<'\n';
    return 0;
}