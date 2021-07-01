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
const int N=505;
char c[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>(c[i]+1);
    for(int i=1;i<=n;i++) {
        if(i&1) {
            for(int j=1;j<m;j++) cout<<1;
            cout<<0;
            cout<<'\n';
        }
        else {
            cout<<1;
            for(int j=2;j<=m;j++) cout<<c[i][j];
            cout<<'\n';
        }
    }
    for(int i=1;i<=n;i++) {
        if(i&1) {
            for(int j=1;j<m;j++) cout<<c[i][j];
            cout<<1;
            cout<<'\n';
        }
        else {
            cout<<0;
            for(int j=1;j<m;j++) cout<<1;
            cout<<'\n';
        }
    }
    return 0;
}