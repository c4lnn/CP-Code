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
const int N=1<<15;
int dp1[N],dp2[N];
string path[N];
struct R {
    string s;int d,c;
    R() {}
    R(string s,int d,int c):s(s),d(d),c(c) {}
    bool operator < (const R &T) const {
        return s<T.s;
    }
}a[20];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        int n;cin>>n;
        for(int i=0;i<n;i++) cin>>a[i].s>>a[i].d>>a[i].c;
        sort(a,a+n);
        for(int i=0;i<1<<n;i++) dp1[i]=0x3f3f3f3f;
        dp1[0]=0;
        for(int i=0;i<1<<n;i++) {
            for(int j=0;j<n;j++) if(i&(1<<j)) {
                int t=max(dp1[i^(1<<j)],dp1[i^(1<<j)]+dp2[i^(1<<j)]+a[j].c-a[j].d);
                if(t<dp1[i]||t==dp1[i]&&path[i^(1<<j)]+(char)(j+'a')<path[i]) {
                    dp1[i]=t;
                    dp2[i]=dp2[i^(1<<j)]+a[j].c;
                    path[i]=path[i^(1<<j)]+char(j+'a');
                }
            }
        }
        cout<<dp1[(1<<n)-1]<<'\n';
        for(int i=0;i<n;i++) cout<<a[path[(1<<n)-1][i]-'a'].s<<'\n';
    }
    return 0;
}