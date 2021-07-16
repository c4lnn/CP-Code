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
const int N=25;
int tot[N],ac[N],m,n;
bool st[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n;
    for(int i=1;i<=m;i++) {
        int a;
        string op;
        cin>>a>>op;
        ++tot[a];
        if(op=="AC") ++ac[a];
        if(ac[a]*2<tot[a]) st[a]=true;
    }
    bool f=false;
    for(int i=1;i<=n;i++) if(tot[i]&&!st[i]) f=true,cout<<i<<' ';
    if(!f) cout<<-1<<'\n';
    else cout<<'\n';
    return 0;
}