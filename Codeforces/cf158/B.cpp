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
int cnt[5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        ++cnt[x];
    }
    int res=cnt[4]+cnt[3]+cnt[2]/2;
    cnt[1]-=cnt[3];
    if(cnt[2]&1) ++res,cnt[1]-=2;
    if(cnt[1]>0) {
        res+=cnt[1]/4;
        if(cnt[1]%4) ++res;
    }
    cout<<res<<'\n';
    return 0;
}