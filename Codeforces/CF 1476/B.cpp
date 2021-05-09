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
const int N=1e3+5;
int n,k;
LL a[N],sum[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
        LL res=0;
        for(int i=n;i>=2;i--)
            if(ceil(1.0*(100*a[i]-k*sum[i-1])/k)>0)
                res=max(res,(LL)ceil(1.0*(100*a[i]-k*sum[i-1])/k));
        cout<<res<<'\n';
    }
    return 0;
}