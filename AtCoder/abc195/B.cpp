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
    int a,b,w;
    cin>>a>>b>>w;
    w*=1000;
    DB l=1.0*w/b,r=1.0*w/a;
    if(ceil(l)>r) cout<<"UNSATISFIABLE"<<'\n';
    else cout<<(int)ceil(l)<<' '<<(int)floor(r)<<'\n';
    return 0;
}