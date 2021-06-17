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
        int n;cin>>n;
        int sum=0;
        VI a(n+1);
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%n) cout<<-1<<'\n';
        else {
            int cnt=0;
            for(int i=1;i<=n;i++) if(a[i]>sum/n) ++cnt;
            cout<<cnt<<'\n';
        }
    }
    return 0;
}