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
    int n,m;cin>>n>>m;
    int c=0;
    for(int i=1;i<=n;i++) {
        if(i%4==1||i%4==2) c=1;
        else c=0;
        for(int j=1;j<=m;j++) {
            cout<<(j&1?c:c^1);
        }
        cout<<'\n';
    }
    return 0;
}