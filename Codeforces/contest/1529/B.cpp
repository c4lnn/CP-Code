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
int a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        int cnt=1,mn=INT_MAX;
        for(int i=2;i<=n;i++) {
            if(a[i]<=0) ++cnt,mn=min(mn,a[i]-a[i-1]);
            else if(a[i]>0) {
                mn=min(mn,a[i]-a[i-1]);
                if(mn<a[i]) break;
                else ++cnt;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}