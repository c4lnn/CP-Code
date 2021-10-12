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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,v1,v2,x1,x2;cin>>n>>v1>>v2>>x1>>x2;
        if(x1<x2) {
            x1=n-x1+1;
            x2=n-x2+1;
        }
        for(int i=1;;i++) {
            if(i&1) {
                if(x1==2&&x2==1) {cout<<i<<'\n';break;}
                if(x2>v2) x2-=v2;
                else if((v2-x2)&1) x2=1;
                else x2=2;
            }
            else {
                if(x1-x2<=v1) {cout<<i<<'\n';break;}
                x1-=v1;
            }
        }
    }
    return 0;
}