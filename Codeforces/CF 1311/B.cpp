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
int a[105];
bool st[105];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,m;cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        memset(st,false,sizeof st);
        for(int i=1;i<=m;i++) {
            int x;cin>>x;
            st[x]=true;
        }
        bool f=false;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<n;j++) if(a[j]>a[j+1]) {
                if(st[j]) swap(a[j],a[j+1]);
                else {f=true;break;}
            }
            if(f) break;
        }
        cout<<(f?"NO":"YES")<<'\n';
    }
    return 0;
}