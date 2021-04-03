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
const int N=55;
PII a[N];
int n,m,q,b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>a[i].FI>>a[i].SE;
    sort(a+1,a+1+n);
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=q;i++) {
        int l,r;
        cin>>l>>r;
        int t=1,res=0;
        priority_queue<int> q;
        VI c;
        for(int j=1;j<l;j++) c.PB(b[j]);
        for(int j=r+1;j<=m;j++) c.PB(b[j]);
        sort(ALL(c));
        for(auto x:c) {
            while(t<=n&&a[t].FI<=x) q.push(a[t].SE),++t;
            if(SZ(q)) res+=q.top(),q.pop();
        }
        cout<<res<<'\n';
    }
    return 0;
}