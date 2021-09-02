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
const int N=2e4+5;
int n;
LL a[N],b[N],c[N];
bool check(LL mid) {
    LL tot=0;
    for(int i=1;i<=n;i++) {
        LL d=(min(b[i],mid)-a[i]);
        if(d<0) continue;
        tot+=d/c[i]+1;
    }
    return tot&1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n) {
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
        LL l=1,r=1ll<<32;
        while(l<r) {
            LL mid=l+r>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        if(l==1ll<<32) cout<<"DC Qiang is unhappy.\n";
        else {
            LL res=0;
            for(int i=1;i<=n;i++) {
                LL d1=(min(b[i],l)-a[i])/c[i];
                if(d1>=0) res+=d1+1;
                LL d2=(min(b[i],l-1)-a[i])/c[i];
                if(d2>=0) res-=d2+1;
            }
            cout<<l<<' '<<res<<'\n';
        }
    }
    return 0;
}