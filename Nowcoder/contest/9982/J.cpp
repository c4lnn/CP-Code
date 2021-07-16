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
//head
int f[50];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    f[0]=1,f[1]=2;
    for(int i=1;i<=n;i++) {
        if(i<=42) {
            cout<<f[i]<<' ';
            if(i<=41) f[i+1]=f[i]+f[i-1];
        }
        else cout<<1<<' ';
    }
    cout<<'\n';
    return 0;
}