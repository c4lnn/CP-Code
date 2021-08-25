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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,m;LL k;cin>>n>>m>>k;
        VI mx(n+1),mn(m+1,0x3f3f3f3f);
        int t=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) {
                int x;cin>>x;
                mx[i]=max(mx[i],x);
                mn[j]=min(mn[j],x);
                if(i==1&&j==1) t=x;
            }
        if(k==1) cout<<mx[1]<<'\n';
        else if(k&1) {
            int res=0x3f3f3f3f;
            for(int i=1;i<=n;i++) res=min(res,mx[i]);
            cout<<max(t,res)<<'\n';
        }
        else {
            int res=0;
            for(int i=1;i<=m;i++) res=max(res,mn[i]);
            cout<<max(t,res)<<'\n';
        }
    }
    return 0;
}