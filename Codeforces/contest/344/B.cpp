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
    for(int i=0;i<=a;i++) {
        int j=a-i,k=b-i;
        if(k>=0&&j+k==c) return cout<<i<<' '<<k<<' '<<j<<'\n',0;
    }
    cout<<"Impossible"<<'\n';
    return 0;
}