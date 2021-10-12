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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
int a[20];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int s,n;cin>>s>>n;
        s-=n;
        for(int i=0;i<n-1;i++) {
            int t=1;
            while(t*10-1<=s) t*=10;
            cout<<t<<' ';
            s=s-t+1;
        }
        cout<<s+1<<'\n';
    }
    return 0;
}