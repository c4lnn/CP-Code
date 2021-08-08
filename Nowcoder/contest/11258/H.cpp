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
int cnt[1000005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        ++cnt[x];
    }
    int lim=1e6;
    LL res=0;
    for(int i=1;i<=lim;i++) {
        for(int j=i;j<=lim;j+=i) if(cnt[i]&&cnt[j]&&cnt[j/i]) {
            res+=1ll*cnt[i]*cnt[j]*cnt[j/i];
        }
    }
    cout<<res<<'\n';
    return 0;
}