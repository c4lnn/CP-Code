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
const int N=1e3+5;
int a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    LL res=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i+=2) {
        LL sum=a[i],l=a[i];
        for(int j=i+1;j<=n;j+=2) {
            sum-=a[j];
            if(j==i+1) res+=min(a[i],a[j]);
            else res+=max(0ll,l-max(0ll,sum)+1);
            if(sum<0) break;
            l=min(l,sum);
            sum+=a[j+1];
        }
    }
    cout<<res<<'\n';
    return 0;
}