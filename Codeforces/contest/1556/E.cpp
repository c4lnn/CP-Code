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
LL a[N],s[N],mx[25][N],mn[25][N];
int hightbit(int x) {return 31-__builtin_clz(x);}
void init(int n) {
    for(int i=1;i<=n;i++) mx[0][i]=mn[0][i]=s[i];
    int t=hightbit(n);
    for(int i=1;i<=t;i++)
        for(int j=1;j+(1<<i)-1<=n;j++) {
            mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
            mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
        }
}
LL query1(int l,int r) {
    int k=hightbit(r-l+1);
    return max(mx[k][l],mx[k][r-(1<<k)+1]);
}
LL query2(int l,int r) {
    int k=hightbit(r-l+1);
    return min(mn[k][l],mn[k][r-(1<<k)+1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        int b;cin>>b;
        a[i]=b-a[i];
        s[i]=s[i-1]+a[i];
    }
    init(n);
    for(int i=1;i<=q;i++) {
        int l,r;cin>>l>>r;
        LL mxx=query1(l,r),mnn=query2(l,r);
        if(mnn-s[l-1]<0||s[r]-s[l-1]!=0) cout<<-1<<'\n';
        else cout<<mxx-s[l-1]<<'\n';
    }
    return 0;
}