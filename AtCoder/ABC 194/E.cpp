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
const int N=1500005;
VI pos[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        pos[x].PB(i);
    }
    for(int i=0;i<=n;i++) {
        if(!SZ(pos[i])) return cout<<i<<'\n',0;
        for(int j=0;j<SZ(pos[i]);j++) {
            if(!j&&pos[i][j]>m) return cout<<i<<'\n',0;
            if(j&&pos[i][j]-pos[i][j-1]-1>=m) return cout<<i<<'\n',0;
            if(j==SZ(pos[i])-1&&n-pos[i][j]>=m) return cout<<i<<'\n',0;
        }
    }
    return 0;
}