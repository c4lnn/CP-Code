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
int n,k;
LL a[N],b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1];
        LL res=0;
        for(int i=1;i+k-1<=n;i++) {
            if(b[i]>=0) continue;
            res-=b[i],b[i+k]+=b[i],b[i]=0;
        }
        for(int i=n;i-k>=1;i--) {
            if(b[i]<=0) continue;
            res+=b[i],b[i-k]+=b[i],b[i]=0;
        }
        for(int i=2;i<=n;i++) if(b[i]!=0) res=-1;
        cout<<res<<'\n';
    }
    return 0;
}