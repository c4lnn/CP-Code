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
const int N=1e4+5;
PII a[N];
int st[15][N];
void init(int n) {
    int t=log2(n);
    for(int i=1;i<=n;i++) st[0][i]=a[i].SE;
    for(int i=1;i<=t;i++)
        for(int j=1;j+(1<<i)-1<=n;j++)
         st[i][j]=min(st[i-1][j],st[i-1][j+(1<<i-1)]);
}
int query(int l,int r) {
    int t=log2(r-l+1);
    return min(st[t][l],st[t][r-(1<<t)+1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin>>n) {
        for(int i=1;i<=n;i++) cin>>a[i].FI>>a[i].SE;
        sort(a+1,a+1+n);
        init(n);
        VI t;
        t.PB(1);
        int tt=0;
        for(int i=2;i<=n;i++) {
            while(a[tt+1].FI<a[i].FI) ++tt;
            if(!tt||query(1,tt)>=a[i].SE) t.PB(i);
        }
        sort(ALL(t));
        cout<<SZ(t)<<'\n';
        for(auto x:t) cout<<a[x].FI<<' '<<a[x].SE<<'\n';
    }
    return 0;
}