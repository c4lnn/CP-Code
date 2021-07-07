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
int a[N],pre[N],mx[N];
LL sum[N];
VI b;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        b.PB(a[i]);
    }
    sort(ALL(b));
    b.resize(unique(ALL(b))-b.begin());
    for(int i=1;i<=n;i++) a[i]=lower_bound(ALL(b),a[i])-b.begin()+1;
    memset(mx,0x3f,sizeof mx);
    for(int l=1,r=0,cnt=0;l<=n;l++) {
        while(r<n&&cnt<k) {
            int d=a[++r];
            if(pre[d]<l) ++cnt;
            pre[d]=r;
        }
        if(cnt==k) mx[l]=r;
        else break;
        if(pre[a[l]]==l) --cnt;
    }
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+mx[i];
    LL res=0;
    for(int i=1;i<=m;i++) {
        LL a,b;cin>>a>>b;
        LL l=min(a^res,b^res)+1;
        LL r=max(a^res,b^res)+1;
        int pos=upper_bound(mx+1,mx+n+1,r)-mx-1;
        if(pos>r) pos=r;
        if(pos<l) res=0;
        else res=1ll*(pos-l+1)*(r+1)-(sum[pos]-sum[l-1]);
        cout<<res<<'\n';
    }
    return 0;
}