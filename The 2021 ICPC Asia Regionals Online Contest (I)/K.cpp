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
const int N=2e6+5;
VI g[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        cout<<"Case #"<<cs<<": \n";
        int n,m;cin>>n>>m;
        for(int i=1;i<=n;i++) {
            int t;cin>>t;
            while(t--) {
                int v;cin>>v;
                g[i].PB(v);
            }
        }
        for(int i=1;i<=m;i++) {
            int s,t;cin>>s>>t;
            int f=0;
            while(t--) {
                int x;cin>>x;
                if(f==0&&(int)SZ(g[s])>=x) s=g[s][x-1];
                else f=1;
            }
            if(f==1) cout<<"Packet Loss";
            else cout<<s;
            if(cs<T||cs==T&&i<m) cout<<'\n';
        }
        for(int i=1;i<=n;i++) g[i].clear();
    }
    return 0;
}