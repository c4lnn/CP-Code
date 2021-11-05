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
    int n;cin>>n;
    int res=0;
    getchar();
    for(int i=1;i<=n;i++) {
        string s;getline(cin,s);
        for(auto c:s) if(c=='-') ++res;
    }
    cout<<res<<'\n';
    return 0;
}