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
const int N=51;
int a[N],cnt;
map<int,bool> mp;
PII b[N*N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) {
        int t=cnt;
        for(int j=1;j<=t;j++) if(!mp.count(a[i]+b[j].FI)) {
            mp[a[i]+b[j].FI]=true;
            b[++cnt]=MP(a[i]+b[j].FI,j);
            if(--k==0) break;
        }
        if(!k) break;
        if(!mp.count(a[i])) {
            mp[a[i]]=true;
            b[++cnt]=MP(a[i],0);
            if(--k==0) break;
        }
    }
    for(int i=1;i<=cnt;i++) {
        VI res;
        for(int j=i;j;j=b[j].SE) res.PB(b[j].FI-b[b[j].SE].FI);
        cout<<SZ(res)<<' ';
        for(auto y:res) cout<<y<<' ';
        cout<<'\n';
    }
    return 0;
}