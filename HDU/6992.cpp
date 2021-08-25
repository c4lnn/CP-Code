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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,m,k;cin>>n>>m>>k;
        vector<VI> a(n+1);
        VPII interval[2];
        for(int i=1;i<=k;i++) {
            int x,y;cin>>x>>y;
            a[x].PB(y);
        }
        for(int i=1;i<=n;i++) sort(ALL(a[i]));
        LL res=0;
        if(SZ(a[1])) res=a[1][0]-1,interval[0].EB(1,a[1][0]-1);
        else res=m,interval[0].EB(1,m);
        for(int i=2;i<=n;i++) {
            a[i].PB(m+1);
            int l=1,cnt=0;
            for(auto x:a[i]) {
                while(cnt<SZ(interval[0])&&l>interval[0][cnt].SE) ++cnt;
                if(cnt==SZ(interval[0])) break;
                if(x-1>=max(l,interval[0][cnt].FI)) interval[1].EB(max(l,interval[0][cnt].FI),x-1);
                l=x+1;
            }
            for(auto x:interval[1]) res+=x.SE-x.FI+1;
            swap(interval[0],interval[1]);
            interval[1].clear();
        }
        cout<<res<<'\n';
    }
    return 0;
}