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
    int n,m;
    while(cin>>m>>n) {
        if(m%(n+1)==0) cout<<"none"<<'\n';
        else {
            VI x;
            for(int i=1;i<=n;i++) if((m-i)%(n+1)==0||i>=m) x.PB(i);
            for(int i=0;i<SZ(x);i++) cout<<x[i]<<" \n"[i==SZ(x)-1];
        }
    }
    return 0;
}