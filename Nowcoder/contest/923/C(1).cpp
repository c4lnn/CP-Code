// 多阶差分
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
const LL MOD=1e9+7;
const int N=1e5+5;
LL cnt1[N],cnt2[N],cnt3[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,m;cin>>n>>m;
        for(int i=1;i<=n;i++) cnt1[i]=cnt2[i]=cnt3[i]=0;
        for(int i=1;i<=m;i++) {
            int o,p;cin>>o>>p;
            if(o==1) ++cnt1[p];
            else if(o==2) ++cnt2[p];
            else if(o==3) ++cnt3[p],++cnt3[p+1];
        }
        for(int i=1;i<=n;i++) {
            cnt3[i]=(cnt3[i-1]+cnt3[i])%MOD;
            cnt2[i]=(cnt2[i-1]+cnt2[i]+cnt3[i])%MOD;
            cnt1[i]=(cnt1[i-1]+cnt1[i]+cnt2[i])%MOD;
        }
        for(int i=1;i<=n;i++) cout<<cnt1[i]<<" \n"[i==n];
    }
    return 0;
}