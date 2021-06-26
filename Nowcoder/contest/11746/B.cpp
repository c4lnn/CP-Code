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
const int N=1e5+5;
int n,k,a[N],s[N],id[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        memset(id,-1,sizeof id);
        id[0]=0;
        for(int i=1;i<=n;i++) {
            cin>>a[i],a[i]%=k;
            s[i]=(s[i-1]+a[i])%k;
            if(id[s[i]]==-1) id[s[i]]=i;
        }
        int res=-1;
        for(int i=1;i<=n;i++) if(id[s[i]]<i) res=max(res,i-id[s[i]]);
        cout<<res<<'\n';
    }
    return 0;
}