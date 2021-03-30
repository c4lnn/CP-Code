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
const int N=105;
int n,a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n) {
        if(!n) break;
        int res=0;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            res^=a[i];
        }
        if(!res) cout<<0<<'\n';
        else {
            int tot=0;
            for(int i=1;i<=n;i++) if((res^a[i])<a[i]) ++tot;
            cout<<tot<<'\n';
        }
    }
    return 0;
}