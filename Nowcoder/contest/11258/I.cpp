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
    int x,s;cin>>x>>s;
    LL res=1;
    for(int i=0;i<31;i++) {
        int a=(x>>i)&1,b=(s>>i)&1;
        if(a==1&&b==1) res<<=1;
        else if(a==1&&b==0) return cout<<0<<'\n',0;
    }
    cout<<res-(x==s)<<'\n';
    return 0;
}