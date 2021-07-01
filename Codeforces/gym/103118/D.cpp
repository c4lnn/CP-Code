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
const int N=2e5+5;
int cnt1[N],cnt2[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    int res1=0,res2=0;
    for(int i=1;i<=n;i++) {
        int x,y;cin>>x>>y;
        res1+=4;
        if(cnt1[x]) res1-=2;
        ++cnt1[x];
        if(cnt1[x-1]>=cnt1[x]) res1-=2;
        if(cnt1[x+1]>=cnt1[x]) res1-=2;
        res2+=4;
        if(cnt2[y]) res2-=2;
        ++cnt2[y];
        if(cnt2[y-1]>=cnt2[y]) res2-=2;
        if(cnt2[y+1]>=cnt2[y]) res2-=2;
        cout<<res1<<' '<<res2<<'\n';
    }
    return 0;
}