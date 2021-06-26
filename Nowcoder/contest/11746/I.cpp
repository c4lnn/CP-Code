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
int a[16];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    for(int i=1;i<=15;i++) a[i]=a[i-1]+(1<<(i-1));
    while(T--) {
        int n;
        cin>>n;
        bool f=false;
        for(int i=2;i<=15;i++) if(n%a[i]==0) f=true;
        cout<<(f?"YE5":"N0")<<'\n';
    }
    return 0;
}