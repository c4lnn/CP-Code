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
    int n;cin>>n;
    char pre='2';
    int cnt=0;
    for(int i=1;i<=n;i++) {
        string s;cin>>s;
        if(i==1||s[0]==pre) ++cnt;
        pre=s[1];
    }
    cout<<cnt<<'\n';
    return 0;
}