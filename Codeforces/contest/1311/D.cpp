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
        int a,b,c;cin>>a>>b>>c;
        int res=INT_MAX,aa,bb,cc;
        for(int i=1;i<=10000;i++) {
            for(int j=i;j<=10000+i;j+=i) {
                for(int k=j;k<=10000+j;k+=j) {
                    int t=abs(a-i)+abs(b-j)+abs(c-k);
                    if(t<res) {
                        res=t;
                        aa=i,bb=j,cc=k;
                    }
                }
            }
        }
        cout<<res<<'\n';
        cout<<aa<<' '<<bb<<' '<<cc<<'\n';
    }
    return 0;
}