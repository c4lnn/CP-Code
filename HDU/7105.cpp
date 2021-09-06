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
        int n;cin>>n;
        if(n%4==1) cout<<1+n/4*4<<'\n'<<'1';
        else if(n%4==2) cout<<4+n/4*4<<'\n'<<"0001";
        else if(n%4==3) cout<<2+n/4*4<<'\n'<<"01";
        else cout<<n<<'\n';
        int t=n/4;
        for(int i=0;i<t;i++) cout<<"1001";
        cout<<'\n';
    }
    return 0;
}