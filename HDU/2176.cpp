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
const int N=2e5+5;
int n,a[N],pre[N],nxt[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n) {
        if(!n) break;
        int res=0;
        for(int i=1;i<=n;i++) cin>>a[i],res^=a[i];
        if(res) {
            cout<<"Yes"<<'\n';
            sort(a+1,a+1+n);
            n=unique(a+1,a+1+n)-a-1;
            for(int i=1;i<=n;i++) if((res^a[i])<a[i]) cout<<a[i]<<' '<<(res^a[i])<<'\n';
        }
        else cout<<"No"<<'\n';
    }
    return 0;
}