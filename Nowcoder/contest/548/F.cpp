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
const int P[]={2,3,5,7,11,13,17,19};
LL res,n;
int lim;
void dfs(int x,int d,int tot) {
    for(int i=x;i<=lim;i++) {
        if(i==lim) {
            if(tot) res+=(tot&1?-1:1)*n/d;
            return;
        }
        dfs(i+1,d*P[i],tot+1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        LL k,q,m;cin>>k>>q>>n>>m;
        lim=upper_bound(P,P+8,m)-P;
        res=n;
        dfs(0,1,0);
        cout<<(k&&k>q-res?"Yes":"QAQ")<<'\n';
    }
    return 0;
}