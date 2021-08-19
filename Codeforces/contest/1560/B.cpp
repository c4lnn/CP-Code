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
        int a,b,c;cin>>a>>b>>c;
        if(a>b) swap(a,b);
        int n=(b-a)*2;
        if(c>n||a>n/2) cout<<-1<<'\n';
        else {
            if(c<=n/2) cout<<c+n/2<<'\n';
            else cout<<c-n/2<<'\n';
        }
    }
    return 0;
}