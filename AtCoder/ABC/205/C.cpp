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
    int a,b,c;cin>>a>>b>>c;
    if(c%2==0) a=abs(a),b=abs(b);
    if(a==b) cout<<"=\n"<<'\n';
    else if(a<0&&b>0) cout<<"<\n";
    else if(a>0&&b<0) cout<<">\n";
    else if(a>0&&b>0) cout<<(a>b?'>':'<')<<'\n';
    else cout<<(a>b?'>':'<')<<'\n';
    return 0;
}