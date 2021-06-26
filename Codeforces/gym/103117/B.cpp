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
int tot[N];
VI b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,k,m;cin>>n>>k>>m;
        for(int i=1;i<=n;i++) tot[i]=0;
        for(int i=1;i<=k;i++) b[i].clear();
        for(int i=1;i<=n;i++) {
            int x;cin>>x;
            b[x].PB(i);
        }
        int t=m/n,tt=m%n;
        for(int i=1;i<=k;i++) {
            for(int j=0;j<SZ(b[i]);j++) {
                int cnt=b[i][j]<=tt?t+1:t;
                if(SZ(b[i])&1) {
                    if(j&1) tot[b[i][j]]=(cnt+1)/2;
                    else tot[b[i][j]]=cnt/2;
                }
                else tot[b[i][j]]=j&1?cnt:0;
            }
        }
        for(int i=1;i<=n;i++) cout<<tot[i]<<" \n"[i==n];
    }
    return 0;
}