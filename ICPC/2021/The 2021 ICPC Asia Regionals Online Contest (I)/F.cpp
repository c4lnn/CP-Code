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
    for(int cs=1;cs<=T;cs++) {
        cout<<"Case #"<<cs<<": ";
        double a,b,r;cin>>a>>b>>r;
        double x1=a,y1=b-r;
        if(y1<=0) cout<<fixed<<setprecision(2)<<max(0.0,2*a-r);
        else {
            double t=sqrt(x1*x1+y1*y1);
            cout<<fixed<<setprecision(2)<<t+max(0.0,t-r);
        }
        if(cs<T) cout<<'\n';
    }
    return 0;
}