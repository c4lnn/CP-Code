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
//head
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    if(k<n/2) {
        for(int i=1;i<=k+1;i++) cout<<2*i<<' ';
        for(int i=1;i<=n;i++) {
            if(!(i&1)&&i<=k*2+2) continue;
            cout<<i<<' ';
        }
    }
    else {
        if(n<6) {cout<<-1<<'\n';return 0;}
        for(int i=1;i<=k;i++) if(i!=3) cout<<2*i<<' ';
        cout<<6<<' '<<3<<' ';
        for(int i=1;i<=n;i++) {
            if(!(i&1)&&i<=k*2+2||i==3) continue;
            cout<<i<<' ';
        }
    }
    cout<<'\n';
    return 0;
}