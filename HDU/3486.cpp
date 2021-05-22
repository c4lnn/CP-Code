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
const int N=2e5+5;
int n,k,st[20][N],a[N];
void init(int n) {
    int t=log2(n);
    for(int i=1;i<=n;i++) st[0][i]=a[i];
    for(int i=1;i<=t;i++)
        for(int j=1;j+(1<<i)-1<=n;j++)
         st[i][j]=max(st[i-1][j],st[i-1][j+(1<<i-1)]);
}
int query(int l,int r) {
    int t=log2(r-l+1);
    return max(st[t][l],st[t][r-(1<<t)+1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n>>k) {
        if(n<0&&k<0) break;
        for(int i=1;i<=n;i++) cin>>a[i];
        init(n);
        int mx=query(1,n),mn=(k+1)/mx,res=-1;
        for(int i=mn;i<=n;i++) {
            int sum=0;
            for(int j=1;j<=i;j++) {
                sum+=query((j-1)*(n/i)+1,j*(n/i));
                if(sum>k) break;
            }
            if(sum>k) {res=i;break;}
        }
        cout<<res<<'\n';
    }
    return 0;
}