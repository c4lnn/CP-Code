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
    int T;cin>>T;
    while(T--) {
        int a,b;cin>>a>>b;
        int tot1=(a+b+1)/2,tot2=a+b-(a+b+1)/2;
        set<int> res;
        for(int i=0;i<=a;i++) {
            int x=i,y=a-i;
            if(y<=tot1&&x<=a+b-tot1&&tot1+x-y>=0) res.insert(tot1+x-y);
            if(y<=tot2&&x<=a+b-tot2&&tot2+x-y>=0) res.insert(tot2+x-y);
        }
        cout<<SZ(res)<<'\n';
        for(auto x:res) cout<<x<<' ';
        cout<<'\n';
    }
    return 0;
}