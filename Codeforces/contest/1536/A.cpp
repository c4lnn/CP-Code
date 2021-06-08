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
        int f=0;
        for(int i=0;i<n;i++) {
            int x;cin>>x;
            if(x<0) f=1;
        }
        if(f==1) cout<<"NO"<<'\n';
        else {
            cout<<"YES\n101\n";
            for(int i=0;i<=100;i++) cout<<i<<" \n"[i==100];
        }
    }
    return 0;
}