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
    int x1,y1,z1,x2,y2,z2;cin>>x1>>y1>>z1>>x2>>y2>>z2;
    for(int i=-200;i<=200;i++) {
        for(int j=-200;j<=200;j++) {
            for(int k=-200;k<=200;k++) {
                if(x1*i+y1*j+z1*k==0&&x2*i+y2*j+z2*k==0) {
                    return cout<<i<<' '<<j<<' '<<k<<'\n',0;
                }
            }
        }
    }
    return 0;
}