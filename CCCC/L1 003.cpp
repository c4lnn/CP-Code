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
int a[10];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;cin>>s;
    for(auto c:s) ++a[c-'0'];
    for(int i=0;i<10;i++) if(a[i]) {
        cout<<i<<':'<<a[i]<<'\n';
    }
    return 0;
}