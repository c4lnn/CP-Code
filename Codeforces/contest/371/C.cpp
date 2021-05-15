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
int cnt[3],nb,ns,nc,pb,ps,pc;
LL m;
bool check(LL mid) {
    return max(0ll,(mid*cnt[0]-nb))*pb+max(0ll,(mid*cnt[1]-ns))*ps+max(0ll,(mid*cnt[2]-nc))*pc<=m;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;cin>>s;
    for(int i=0;i<SZ(s);i++) {
        if(s[i]=='B') ++cnt[0];
        else if(s[i]=='S') ++cnt[1];
        else ++cnt[2];
    }
    cin>>nb>>ns>>nc;
    cin>>pb>>ps>>pc;
    cin>>m;
    LL l=0,r=1e12+100;
    while(l<r) {
        LL mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
    return 0;
}